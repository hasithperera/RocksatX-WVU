

- SPI sweeps: 0-10 V with 1000 steps SPI only takes ~150 ms 
	- Per stage: this would be $1000/200 \approx 5$ ms
- 0 to 10 V (one step) Jump and ADC recording
	- SPI only take 79 ms as measured in C
	- $\approx 81$ms in the scope measurements
- 0V to 10V (one step) with file write
	- Elapsed time: 0.137215646 s
