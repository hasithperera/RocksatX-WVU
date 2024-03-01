# 02/29/2024
## General Updates
- Servo 1 is now converted into a continuous servo that we can vary the speed of rotation
	- This was done by removing the pin attached to the inner brass gear, cutting away the plastic connector to the brass gear that connected it to the potentiometer, and glueing the potentiometer to be as close to center as possible.
- The documentation https://components101.com/sites/default/files/component_datasheet/MG996R%20Datasheet.pdf suggests 50 Hz PWM signal
- We need longer 8x32 screws
	- The screws attaching the Servo Mounts to the Servo need to be ~3/8" longer. The current screws are 5/16" long, so we need 11/16" long screws
- Servo Assembly works great
	- It can both push and pull the nylon rod through and the teeth do not slip when the rod is pulled or pushed
	- The gear pushing into the rod may be too tight, seems to work fine tho.
## Testing Details

- Testing for the PWM duty cycle where the servo is in a no rotation state, I find that 7.21-7.27% there is no rotation for Servo 1
- At 7% duty cycle, to push a 41" rod, it took 76 sec, which is 0.54" per second
	- The maximum deployment rate is 1" per second
- At 7.48% duty cycle, to push 41", it took 41 sec, which is 1" per second #ahe
- At 6.8% duty cycle, to push a 41" rod, it took 31 sec, which is 1.32" per second #ahe
- At 6.9% duty cycle, to push a 41" rod, it took 42 sec, which is 0.98" per second