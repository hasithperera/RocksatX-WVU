
## 14/02/2024

- Sounding mode
	- TX 10 ms - 1 s random noise intervals. Vary this along the flight to see what is a sustainable and usable power
	- RX when not TX module is not acting 
	- Signal needs to be inverted to provide to the other end of the antenna
		- This may not be usefill for us sincewe are not having that long antennas
- Tests done by the review 
	- TX random noise/ frequency sweeps 
	- auto run on start
	- respond to input even from onboard systems
- Need to talk to Nillay #task
	- whats needed on the hw side of things
		- Op-amps for signal amplification 
		- 5 - 20 MHz 
	- Level shifter's for the inputs. Start putting down a schematic 
	- Make a block diagram and divide between the two of us what parts each of us are attempting 