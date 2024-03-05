
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
	- yello signal is the python commands sent