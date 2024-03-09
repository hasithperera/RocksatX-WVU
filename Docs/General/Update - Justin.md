# 02/29/2024
## General Updates
- Servo 1 is now converted into a continuous servo that we can vary the speed of rotation
	- This was done by removing the pin attached to the inner brass gear, cutting away the plastic connector to the brass gear that connected it to the potentiometer, and glueing the potentiometer to be as close to center as possible.
- The documentation https://components101.com/sites/default/files/component_datasheet/MG996R%20Datasheet.pdf suggests 50 Hz PWM signal
---
- We need longer 8x32 screws
	- The screws attaching the Servo Mounts to the Servo need to be ~3/8" longer. The current screws are 5/16" long, so we need 11/16" long screws
- Servo Assembly works great
	- It can both push and pull the nylon rod through and the teeth do not slip when the rod is pulled or pushed
	- The gear pushing into the rod may be too tight, seems to work fine tho.
---
## Testing Details for Servo 1

- Signal details
	- We produced a +- 2.5V signal 50 Hz
	- Supplied a 5V supply to the servo
---
- Testing for the PWM duty cycle where the servo is in a no rotation state, I find that 7.21-7.27% there is no rotation for Servo 1 #Hasith 
- At 7% duty cycle, to push a 41" rod, it took 76 sec, which is 0.54" per second
	- The maximum deployment rate is 1" per second
- At 7.48% duty cycle, to push 41", it took 41 sec, which is 1" per second #Hasith 
- At 6.8% duty cycle, to push a 41" rod, it took 31 sec, which is 1.32" per second
- At 6.9% duty cycle, to push a 41" rod, it took 42 sec, which is 0.98" per second #Hasith 

# 03/08/2024
## General Update
- We have made 2 more servos that are continuous.
## Testing Details for Servo 2

- Signal details
	- We produced a +- 2.5V signal 50 Hz
	- Supplied a 5V supply to the servo
---
- Testing for the PWM duty cycle where the servo is in a no rotation state, I find that 6.97-7.04% there is no rotation for Servo 2 #Hasith 
- At 7.11% duty cycle, to push a 41" rod, it took 77 sec, which is 0.53" per second
- At 7.5% duty cycle, to push 41", it took 29 sec, which is 1.41" per second
- At 7.28% duty cycle, to push a 41" rod, it took 35 sec, which is 1.17" per second
- At 7.20% duty cycle, to push a 41" rod, it took 47 sec, which is 0.87" per second
- At 7.24% duty cycle, to push a 41" rod, it took 39 sec, which is 1.05" per second #Hasith 
- At 6.72% duty cycle, to push a 41" rod, it took 50 sec, which is 0.82" per second
- At 6.68% duty cycle, to push a 41" rod, it took 39 sec, which is 1.05" per second #Hasith 

- Varying the frequency from 50 Hz to 49 Hz or 51 Hz causes major variations in the speed of deployment #Hasith 
## Testing Details for Servo 3

- Signal details
	- We produced a +- 2.5V signal 50 Hz
	- Supplied a 5V supply to the servo
---
- Testing for the PWM duty cycle where the servo is in a no rotation state, I find that 7.00-7.07% there is no rotation for Servo 3 #Hasith 
- At 7.25% duty cycle, to push a 41" rod, it took 50 sec, which is 0.82" per second
- At 7.3% duty cycle, to push 41", it took 40 sec, which is 1.02" per second #Hasith 
- At 6.75% duty cycle, to push a 41" rod, it took 48 sec, which is 0.85" per second
- At 6.73% duty cycle, to push a 41" rod, it took 46 sec, which is 0.89" per second
- At 6.70% duty cycle, to push a 41" rod, it took 39 sec, which is 1.05" per second #Hasith 