
- [ ] On TE : Generate PWM for antenna extension (TS0)
- [ ] Delay N seconds (or ms)  for the complete antenna extension.  Set a hold duty cycle to hold it in the correct location. (TS1)
	- Random noise generator.
	- [ ] Delay implementation 
	- [x] PWM Specs needed #task #Justin #Answered ✅ 2024-02-29
		- Can the motors be matched to exactly 50% 
			- Yes, there is a band width of about 0.06% duty cycle that the servo will not rotate
		- What is the freq for the PWM
			- The documentation says 50 Hz
		- What is the duty cycle: 
			- Extension: 
				- For servo 1 it is 6.9%
			- Retraction:
				- For servo 1 it is 7.68%
			- Hold: 
				- For servo 1 it is 7.24%
- [ ] Start LP sweep (TS1)
	- 900 ms ramp (TS1.1)
	- 900 ms RF ADC read + file write
	- 100 ms data storage (TS1.2)
- [ ] SPI DAC and ADC for Langmuir Probe
	- [ ] 
- [ ] Sounding mode

## Timing Diagram for whole mission

