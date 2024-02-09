
## Red-pitaya

- Based on the documentation
	- Power requirements: 2A
	- This is a lot of power and given we would be in an enclosed system this could be a problem. In the past from Rocketry projects I know they have an extended pad time and that causes the system to heat up if it's operating continuously. >> **We need a way to trigger it**
	- Data storage to a USB should be possible. We might not need an M2/an SSD if we limit our data rates it should be fine
	


---

## Differences in specs

- Depending on the FPGA capability 
	- SDRlab is a viable option but limits our ADC to -/+ .5 V_peak (more than enough for rf)
	- STEM lab version +/- 20 V but lower DSP slices 
- we can go about this is 2 main ways
	- use the provided image and write our own custom c/python to get and save data - relatively easy
	- Write a custom FPGA file - Should be possible but verification would take time 
--- 

# Things that needs to be figured out


- Sounding mode
	-  RF input and output switching
	-  RF power amplification components
	-  RF pre amp. Nillai has done this and has an ic. (Maintain v_peak constraint) ✅ 2024-01-27
	-  FPGA
		-  White noise: is this basically a random number generator ? If that is the case I have a working algorithm. But this has a finite repeatability. How long should be the seed/sequence\
---
-  LP mode
	-  Power supply. How are we sweeping the voltage. 
	-  Best case we would have +/- 20 V on the ADC. Can you work with this ?
	-  can we build our own ADC
	-  How many probes are going to be in there. 2 ? 
		- To find How many ADC's we need at a time 

---

# Order list

- Get a small ethernet switch. 
	- Would be good to have since we need to be able to ssh in to the Red-pitaya. And our network is limiting to say the least.
	- [ ] Wifi dongle #task #order