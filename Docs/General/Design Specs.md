
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

| id  | type               | I/O | no of pins    | Descriptions         | ref | FPGA pin | sub block (FPGA) |
| --- | ------------------ | --- | ------------- | -------------------- | --- | -------- | ---------------- |
| 1   | Digital            | in  | 1             | TE from Woleps       |     |          | D+               |
| 2   | Digital            | out | 1 / 3         | PWM (counter)        |     |          | D+               |
| 3   | Analog             | out | 1 (8 bit DAC) | LP voltage sweep     |     |          | LP               |
| 4   | Analog             | in  | 1             | LP current           |     | RF in 1  | LP               |
| 5   | Analog             | out | 1             | sounding TX to Amp   |     |          |                  |
| 6   | Analog             | in  |               | Sounding RX from amp |     |          |                  |
| 7   | Switching for amps |     |               |                      |     |          |                  |
|     |                    |     |               |                      |     |          |                  |
