
## Used Pins

| Pins      | variable name | FPGA pin | voltage level | xdc         |
| --------- | ------------- | -------- | ------------- | ----------- |
| E1/DIO0_N |               |          |               |             |
| E1/DIO1_N | debug_1       | H17      | 3.3 V         | exp_n_io[1] |
| E1/DIO2_N | debug_2       | H18      | 3.3 V         | exp_n_io[2] |
|           | PWM1          |          |               |             |
|           | PWM2          |          |               |             |
|           | PWM3          |          |               |             |
|           |               |          |               |             |

### 22/02/2024
- Vivado 2020.1 is required. Online installer is not working 
- https://redpitaya-knowledge-base.readthedocs.io/en/latest/learn_fpga/3_vivado_env/tutorfpga1.html
- Trying the offline downloaded. which is 35 GB only supports Ubuntu 18.04. `/etc/os-release` editing seems to work 

#### Requirements

- Install **Vivado 2022.1** (this is what I intend to write programs in)
- Back up of the project generated using 2020.1 is available [in a google drive](https://drive.google.com/drive/folders/1FoSDH7iXBIBz88JlJWhi1wxN-frt9Btz?usp=drive_link)
- [x] Test the bin file with SDRLab #task ✅ 2024-02-26
- Commands to generate `bit.bin` files
	- `echo -n "all:{ red_pitaya_top_Z20.bit }" >  red_pitaya_top_Z20.bif`
	- `bootgen -image red_pitaya_top_Z20.bif -arch zynq -process_bitstream bin -o red_pitaya_top_Z20.bit.bin -w`
	- follow tutorial [here](https://redpitaya-knowledge-base.readthedocs.io/en/latest/learn_fpga/3_vivado_env/tutorfpga2.html)
- [x] VHDL components and memory mapping #task ✅ 2024-03-03
	- tutorial [here](https://redpitaya-knowledge-base.readthedocs.io/en/latest/learn_fpga/4_lessons/LedCounter.html)
- [ ] Simulate LFSR in python do a numerical FFT #task
	- [x] internal `np.random.rand` gives a flat spectrum
		![| 300](res/Pasted%20image%2020240226220230.png)
	- [ ] Confirm this with a LFSR simulation in python #task #help #Nilay
		- Initial simulation shows a gaussian spectrum. is this correct ?
		- Generate sample data using python and calculated the data rates/save capacity
	- How to verify once I implement this on RP
		- Making an arduino read 8 parallel bits
		- using the register map that is free `sys[6]` to put values in there
- internal PWM generation (using python)

### 26/02/2024

- Recompiling the project with 2022.1
- cleaned `impl_1`
- re-run synthesis and implementation
- `.dcp` file is the checkpoint and this speeds up the build process. If this is removed implementation needs to be redone
- [x] test sequence
	- make `bif` > `bit.bin` 
	- scp to RP and program 
	- `test2.bin`: all functions in `lp.py` works as the same as the default image
	- `test3.bin`: led_o output pins are isolated from internal image
	- [x] Set up a counter with known speed:  at least 80 M
	- [x] isolate DAC analog functions
	- [x] isolate Digital pins
	- [x] work with DMA memory
- New git repo to keep the FPGA source code [here](https://github.com/hasithperera/Rocksat-FPGA/) (private repo, no intention of collaboration here. purely documentation and recovery)
#### Slow ADC pins

- Analog 3: U13 
- `red_pitaya_pdm` module is setting the outputs
- Operation of PDM [here](https://www.koheron.com/blog/2016/09/27/pulse-density-modulation.html)
	- [x] read and analyze how to break this and implement internal ramp #task #LP ✅ 2024-03-03
	- [x] hey need help #task #ahe ✅ 2024-03-03
- [ ] find documentation on operation 
-  Draw block diagram #task #help 
- internal ams commands are based on having this module loaded
- `monitor -ams` gives access to internal temp on SoC and internal voltage references 
- [x] Find a way to isolate one analog3 Pin from this interface.
	- alternate methods of DAC for LP may be needed
	- [ ] Tune python and look at the internal delay to change sweep time for 900 ms. #task #Nilay
### 27/02/2024

 - [x] Possible bug in `lp.py`: #task #Hasith  #testing ✅ 2024-02-27
	 - Analog 2: switches very fast 800 us
		 - use a digital pin to measure. dose having smaller step size make switching time different ?
	 - [x] Analog 3 sweep is a lot slower. looking at the osc outputs
	- Disable Analog3 from internal python interface
		![|300](res/F0000TEK.jpg)
	- No bug found (its working as expected)
- [x] Make a counter as a frequency divider (Matlab Model composer)
	- [ ] Get 1 Hz clock for timed events
	- FPGA choice: from Vivado
	![400](res/Pasted%20image%2020240227202224.png)
	- Matlab > Vivado pipeline works
	- `test6.bin` has a counter to led direct mapping
	- [ ] Write verification program in any other platform to read digital data (8 bits) + clock(1 bit) as a way to verify operation. #task #testing #fpga
	
## 01/03/2024

- Digital pin outputs:
	- E1 connector `DIOX_N` pins are tri-state buffers
	- Documentation [here](https://docs.xilinx.com/r/2022.1-English/ug1353-versal-architecture-ai-libraries/IOBUF)
	- Python code to set the direction of the tri-state buffer: `pwm.py`
	- [ ] Isolate Tri-state buffer from python #task #Hasith #low_priority #fpga 
	- Extract known clock signals from the internal clock;
	- $f_n = \frac{f_0}{2^{n+1}}$ where $f_0$ is the clock frequency and $n$ is the slice offset from bottom bit in matlab.
- Design specs to a PWM module:
	- [x] Exact 50 Hz clock generation
		- `variable_map.m` Contains configuration variables
	- 10- bit PWM generator implementation
		- [x] Needs testing #task #fpga ✅ 2024-03-03
		- [x] External commanding interface #task #fpga ✅ 2024-03-03


## 02/03/2024

- Made basic VHDL files and test benches to test manually written components.
- Set the top module to be `ahe_tb.vhdl` and run simulation
- `mux_ahe.vhdl`:  designed to change a 32 bit register by changing states of a two bit signal.
	![300](../res/Pasted%20image%2020240303125806.png)

 - `pwm_ahe.vhd`: A working variable bit size PWM. Tested in simulation
	 ![300](../res/Pasted%20image%2020240303141931.png)
	 - [ ] Pending lab verification for the correct frequency and the duty cycle. #task #testing #fpga
		 - Got a very large number of Total Negative Slack (TNS). this is undesirable
		 -  Changing to the `adc_clk` instead of the 50 MHz clock makes this work
		 - Add `adc_clk` and `fclk[2]` both to the design as inputs to see what happens: This also fails timing 
		 - `adc_clk` Routed to U18/U19 
 - [x] Python commands (test toolkit): #task #Hasith ✅ 2024-03-03
	 - led register is used to set commands
	 - Design a detailed commanding syntax 
		 ![Design Specs](../General/Design%20Specs.md##Payload%20Testing%20Requirements)
	 - Basic working version `test10.bin`, python program `test.py`
		 - last bit is used to enable the counter
		 - Measured 8th bit: 240 kHz
			 - Base clock is 125 MHz
- [ ] PWM controller #task #Hasith 
	- Design the counters 
	- make Duty cycle switcher using 2 bits 
## 04/03/2023

- Wrote a test bench for PWM and outputs look good on there.
- Python commanding was also tested 
	![](../res/Pasted%20image%2020240304234328.png)
	- red signal is PWM
	- yellow signal is the python commands sent
	- Design was tested on the RP and it works as expected 
		![200](../res/TEK0000.jpg)
		- [ ] Check to drive servo assembly. #task #Justin 
			- Python: 1,3,4
			- designed to give 50 Hz but not giving that
			- [ ] 55,60 Hz signals are measured as 54.05 and 59.03 Hz (there is a possible offset of 1Hz ?? ) #bug #fpga #testing
			 ![200](../res/TEK0002.jpg)




## 09/03/2024

- [ ] Rethink data storage #task #Nilay #Justin 
- ADC freq: $f_0 = 125 MHz$
- buffer size: $16384 = 2^{16}$
- DFT calculation: to see resolution 
	- chose to decimation factor: 2
	- max rate: $f_1 = 62.5 MHz$
	- $\Delta f = \frac{62.5 \times 10^6}{16384} = 3.8 \times 10^3 Hz$
	- collection time for the buffer: 
		- with $f_1$: $1/f_1 * buffer = 0.27 ms$
- Data storage (theoretical max rates only for sounding):
	- 16 bit data = 2 bytes (assuming binary write. if ascii write is done this increases X32 at least assuming XXX data format. this is lossy too)
	- total data for one buffer: $2^{16}* 2 B = 2^{17} / 1000 = 131.07$ kB
	- for 1 ms of data : $132 * 3$ kB
	- for 1 s: $396$ MB (the SD card is limited to 15 MB/s on a computer. old card could do 50 MB/s)
	- for 200 s:  $79.2$ GB (we only have a 50 GB partition for data)
	  
	  
	- **This is what I was afraid of from the start. the data rates are too large in an ideal world**. We need to drop this to at least about  10-20 GB (for Sounding only)
		- [ ] Modifications to the sounding mode plan. 
			- sound 16 ms: 
				- get data during this.
					- Hasith: still believe this is hard to do on the FPGA end
			- Get data for 2 ms right after sounding
			- leave a gap (5-100 ms,also can be varied during the launch)
			- Get data again for 2 ms
			- leave a gap (5-100 ms)
- [ ] Do a similar calculation for LP #task #Dylan 

## 12/03/24

- Tested C programs from the repo and made a working makefile
	- `Can` gave issues during compilation these were removed from the makefile
	- SDR lab has only one os version. v2-23
	- [tutorial](https://redpitaya.readthedocs.io/en/latest/developerGuide/software/build/C%26Python_API.html#) is outdated. but make file is working
	- there are no preprocessor variables 
	- [ ] C binary write #task #help #Nilay #Hasith  📅 2024-03-17 
		- [ ] Evaluate time to write by building a program to test this
		- [ ] python data reading to verify whats saved can be read back in to show original information
	- [ ] C data ADC reading program #task #Hasith  