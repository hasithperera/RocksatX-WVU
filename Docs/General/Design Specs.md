
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

| id | type | I/O | no of pins | Descriptions | ref | FPGA pin | sub block (FPGA) |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 1 | Digital | in | 1 | TE from Woleps |  |  | D+ |
| 2 | Digital | out | 3 | PWM (counter) |  |  | D+ |
| 3 | Analog | out | 1 (8 bit DAC) | LP voltage sweep |  |  | LP |
| 4 | Analog | in | 1 | LP current |  | RF in 1 | LP |
| 5 | Analog | out | 1 | sounding TX to Amp |  |  | S |
| 6 | Analog | in | 1 | Sounding RX from amp |  |  | S |
| 7 | Switching for amps | out | 2 | Switch before each antenna |  |  | S |
|  |  |  |  |  |  |  |  |
|  |  |  |  |  |  |  |  |
##  Timing Sequence LP

|  |  |
| ---- | ---- |
|  |  |
|  |  |
|  |  |

##  Timing Sequence S

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

##  Timing Sequence LP Testing

|  |  |
| ---- | ---- |
|  |  |
|  |  |
|  |  |

##  Timing Sequence S Testing

| What we get from Python | Even |
| ---- | ---- |
| send a 1 | Activate Noise |
| send a 2 | Deactivate Noise |
| send a 3 | Record Data |
| send a 4 | Stop Recording |
| send a 5 | Switch antenna TX to RX |

##  Timing Sequence Deployment Testing

| What do we need from python | Event |
| ---- | ---- |
| send a 1 | Extend Antenna |
| send a 2 | Retract Antenna |
|  |  |

##  Payload Testing Requirements
- Need a python code to activate the testing sequences listed above
- 
