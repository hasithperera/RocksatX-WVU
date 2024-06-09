Sequence for Main Code
- Wait Code
	- Blink LED 1 to indicate we are in wait mode
	- Wait until a high is received on pin __
		- When high is received hold LED 1 high
		- When high is received start Deploy Code
	- While waiting, create/write to a Startup Data File the reset iteration
		- Check for a startup file
			- if no file
				- create one and write to it the reset iteration, code version, and deployment time = 0
			- if there is a startup file
				- read the reset iteration value and increment that value by one, write this to the startup file
- Deploy Code
	- While in Deploy code Blink LED 2
	- Check Startup file for deployment time 
		- subtract (18 sec) - (deployment time) to get time left for deployment
	- Send PWM to all three antenna to deploy
		- PWM signals will be sent for remainder of deployment time
		- As the PWMs are deployed write to a file every half second how long the PWM signals have been sent
			- every 0.5 sec write the read deployment time +0.5 until deployment time >= 18 sec
		- 
- Loop Code
	- 

## Deployment +
- [ ] Observe full Individual Antenna Extension and Retraction to ~18"
	- [ ] On Retraction ensure antennas retract fully
- [ ] Observe all three Antenna Extension and Retraction to ~18"
- [ ] Test Main Code
	- [ ] On startup the RP should be in wait mode
		- [ ]  LED 1 is lit
		- [ ] Startup Data file should be written to/created and contain the restart iteration
	- [ ] Ensure the TE signal is being received by the RP
		- [ ] LED 2 is lit
		- [ ] Antenna Extension has begun
		- [ ] Startup Data file should be written with value of time after start of extension until set value and the reset iteration
		- [ ] Test power restart during deployment to see if deployment continues where it left off and the reset iteration has incremented by one
	- [ ] Ensure the new image is loaded onto the RP after extension
		- [ ] LED 3 is lit
		- [ ] Antenna extension has ended
		- [ ] Startup file should contain the value of time for full extension and the reset iteration
		- [ ] On reset at this stage the deployment phase should be bypassed and the new image written with the reset iteration incremented by one

---
## LP
- [ ] Measure LP output and ensure sweep is outputting correctly
	- [ ] Is it a 1 sec Sweep?
	- [ ] Is it reaching -10 to 10 V?
	- [ ] ...
---
## Sounding
