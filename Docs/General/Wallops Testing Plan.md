Sequence for Main Code


## Deployment +
- [ ] Observe full Individual Antenna Extension and Retraction to ~18"
	- [ ] On Retraction ensure antennas retract fully and activate limit switch
- [ ] Observe all three Antenna Extension and Retraction to ~18"
- [ ] Test Start Code
	- [ ] On startup the RP should be in wait mode
		- [ ]  LED 1 is lit
		- [ ] Startup file should be written and contain nothing
	- [ ] Ensure the TE signal is being received by the RP
		- [ ] LED 2 is lit
		- [ ] Antenna Extension has begun
		- [ ] Startup file should be written with value of time after start of extension until set value
		- [ ] Test power restart during deployment to see if deployment continues where it left off
	- [ ] Ensure the new image is loaded onto the RP after extension
		- [ ] LED 3 is lit
		- [ ] Antenna extension has ended
		- [ ] Startup file should contain the value of time for full extension
		- [ ] On reset at this stage the deployment phase should be bypassed and the new image written 
	- [ ] The 

---
## LP
- [ ] Measure LP output and ensure sweep is outputting correctly
	- [ ] Is it a 1 sec Sweep?
	- [ ] Is it reaching -10 to 10 V?
	- [ ] ...
---
## Sounding
