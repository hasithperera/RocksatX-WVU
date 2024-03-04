## FPGA Design meeting (01/03/2024)
- Wanna talk about the project as a whole 
- Justin and Dylan tell us what's needed.
	- Basic flight and experiment details
- Update on the current FPGA/RP state
- Work on:
	- Design specs
	- Testing specs
---
## Current progress - Hasith

- Red Pitaya basic system
	- Arm + FPGA (Xilinz Zynq series)
	- We have 2 versions: SDR lab and STEM lab. refer specs for difference
	- All my work so far has been on the SDR lab board
- What I know so far
	- Python control
		- LEDs and Digital pins
		- DAC ramp using (slow pins): we need to resolve the conflict here of why and what should be used. 
	- FPGA direct
		- you need 2020.1 to compile source I have upgraded the project to 2022.1
		- LED access 
		- Isolate DAC pins. can't drive them yet
---
## Questions for every one

- How are we going to approach collaboration between multiple developers(On Matlab)
	- Independent development and try to combine later ?
		- Runs the risk of not being able to fit in one FPGA
- Finalize a requirement and test plan document
- Testing: can this be done by some one else ? 
	- I might not have access to all the systems right now.
- [ ] What Xilinz Zynq do we have on the RP STEM? #task #Dylan 
