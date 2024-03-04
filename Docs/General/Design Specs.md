
## LP - Probe

- [ ] What is the exact sequence need to the probe #task #Dylan #help
	- set voltage
	- do we want to get feed back after the amplification stage for the probe potential
	- how long and what do we do with the input data.
		- reduce it onboard on python / save time_v_step data for every second
	- what data rates can we actually write the files: how much data do we have
	- Space constraints. Can we put all of these on there. (Motor drive, H bridge ?)
	- Slow ADC spec:
		- is this compatible with our use case. doc [here](https://redpitaya.readthedocs.io/en/latest/appsFeatures/examples/analog/ana-exm2.html)
		- external signal conditioning needed:
			- shift to -.9 to .9 (from 0-1.5) max is 1.8 V
			- scale up to +/- 10 V
		- Red pitaya spec:
			- RF in/out (SMA connectors):14 bits on STEM lab 125 M (this is a big overkill for what we need)
			- Slow ADC: 4 channels  0-3.5V 12bit
			- Slow DAC:  4 channels  0-1.8V 12bit

## System general FPGA design specs

- Ref: fill in a link to a file/section where more detailed information is found
- LP: langmier probe 
- Sounding(S): sounding and waves experiment 

| id  | type    | I/O | no of pins    | Descriptions                         | ref | FPGA pin | sub block (FPGA) |     |     |
| --- | ------- | --- | ------------- | ------------------------------------ | --- | -------- | ---------------- | --- | --- |
| 1   | Digital | in  | 1             | TE from Woleps                       |     |          | D+               |     |     |
| 2   | Digital | out | 3             | PWM (counter)                        |     |          | D+               |     |     |
| 3   | Analog  | out | 1 (8 bit DAC) | LP voltage sweep                     |     |          | LP               |     |     |
| 4   | Analog  | in  | 1             | LP current                           |     | RF in 1  | LP               |     |     |
| 5   | Analog  | out | 1             | sounding TX to Amp                   |     |          | S                |     |     |
| 6   | Analog  | in  | 1             | Sounding RX from amp                 |     |          | S                |     |     |
| 7   | Analog  | out | 2             | Switch component before each antenna |     |          | S                |     |     |
|     |         |     |               |                                      |     |          |                  |     |     |
|     |         |     |               |                                      |     |          |                  |     |     |
|     |         |     |               |                                      |     |          |                  |     |     |

##  Timing Sequence Deployment

- [ ] D+ specs #task  #Justin 

| Step | time (ms) | Description |
| ---- | ---- | ---- |
| send a 1 | Extend Antenna |  |
| send a 2 | Retract Antenna |  |
|  |  |  |


## Timing Sequence LP

- [ ] LP specs #task #Dylan  

| Step | time (ms) | Description |  |
| ---- | ---- | ---- | ---- |
| 1 | 1 | Mark time of LP Start Ramp |  |
| 2 | 800 (ms) | Ramp Voltage 0-1.5 V for SDR |  |
|  |  |  |  |

##  Timing Sequence S
- [ ] Sounding spec #task #Justin #Dylan #Nilay 

|  |  |
| ---- | ---- |
|  |  |
|  |  |
|  |  |

##  Timing Sequence Whole Experiment

|  |  |
| ---- | ---- |
|  |  |
|  |  |
|  |  |

##  Payload Testing Requirements
- Need a python code to activate the testing sequences listed above
- Currently upto 8 bits are available: 
- [ ] Check current design spec. #task #Justin #Dylan #fpga #specs
	- Decided on using the following table. this will allow simultaneous testing to be conducted by using the correct decimal equivalent on python

| 7   | 6   | 5   | 4   | 3   | 2   | 1   | 0   | Usage          | fpga   |
| --- | --- | --- | --- | --- | --- | --- | --- | -------------- | ------ |
| x   | x   | x   | x   | x   | x   | x   | 1   | en             | tested |
|     |     |     |     |     | 0   | 0   | 1   | pwm stop       | ?      |
|     |     |     |     |     | 0   | 1   | 1   | antenna fwd    |        |
|     |     |     |     |     | 1   | 0   | 1   | antenna rev    |        |
|     |     |     |     |     | 1   | 1   | 1   | antenna hold   |        |
| x   | x   | x   | x   | 1   | x   | x   | 1   | LP sweep       |        |
| x   | x   | x   | 1   | x   | x   | x   | 1   | LP data save   |        |
| x   | x   | 1   |     |     |     |     | 1   | Rnd generation |        |
|     | 1   | 1   |     |     |     |     | 1   | Sounding Tx    |        |
|     | 1   | 0   | x   | x   | x   | x   | 1   | Sounding RX    |        |
| 1   |     |     |     |     |     |     | 1   | Unused         |        |

### Onboard led specification

- This section shows the usage of the internal LED's of the red pitaya 
- Depending on the image used refer the correct row for data

| 7       | 6             | 5   | 4   | 3       | 2        | 1      | 0       | image label |
| ------- | ------------- | --- | --- | ------- | -------- | ------ | ------- | ----------- |
| clk     | Sounding save | RX  | TX  | LP save | LP sweep | PWM en |         | Production  |
| clk[28] | 27            | 26  | 25  | 24      | 23       | 22     | clk[21] | test 11     |
|         |               |     |     |         |          |        |         |             |
