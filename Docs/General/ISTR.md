


# What needs done?

## LP

## Deployment +

- [x] Final PWM controller and python interface for testing #task #Hasith 📅 2024-03-15 ✅ 2024-03-15
      ![FPGA direct programming](../Old/FPGA%20direct%20programming.md#PWM%20Module%20testing )
- [x] Make 3 motors + calibration data #task #Justin 📅 2024-03-08 ✅ 2024-03-15
- [ ] Auto run program and custom image #task #Hasith 
- [x] Testing PCB for 3 servos #task #Justin ✅ 2024-03-15
	- Add extra 3 pins to osc out puts
	- Did not build a PCB. made a usable setup
## FPGA

- [ ] SPI simulated device: Temperature probe #task #Dylan  #Hasith 
- [ ] FPGA-TX module integration #task #fpga #Gabriela 
	- [ ] Need plots of random numbers to show as verification
	- [ ] DMA interface backup #task #Hasith 

- [x] FPGA-RX #task #Hasith ✅ 2024-03-15
	- [x] Data spec : $\Delta f$, $N_{bits}$
	- [x] Complex number spec: simulation and what data rates can be achieved 
	- [x] Data write from the ADC
	- [x] C interface