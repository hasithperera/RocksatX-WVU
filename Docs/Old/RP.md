
## Basic testing on the RP

## 08/02/2024

- Set up manual ip to be `192.168.11.10`
- Configure your computer to be on the same subnet ie. 192.168.11.xxx (subnet 255.255.255.0) and a unique address. you can look at the web interface by visiting [192.168.11.10](http://192.168.11.10)
- `/root/in` has the repo from redpitaya
- to send files use `scp <src> <destination>` or `rsync`
- refer doc for user name and password
- compiling c code from the example failed. Possible missing library/dependencies
- Setting the time can be done with `date mmddHHMMYYYY`. Note this is in UTC time (EST +5 h) may required to do on restart since NTP is not operational in the current setup
- `date -u`: get the UTC time from linux/Mac

---
## Programming FPGA

- log in to the rp: `ssh root@<ip>`
- FPGA custom images are stored in `/opt/data/bin`
- Each of the files here correspond to some version of an FPGA image that had been used. select what you are testing and reprogram it to start testing.
- To reprogram use `/opt/redpitaya/bin/fpgautil -b <bin file>`
- Most of the FPGA programs written here requires a python/c program to be running in order to operate as expected
- Note: test21.bin is currently set to autoload.


---
### Python
- 3rd party Wifi Dongle not working (Being detected by device, not connecting, possible driver issue)
- Able to run python script on laptop via SCPI Server
- Communicating commands via the ethernet, so once the connection is broken the program ends

---
### Thoughts on Roads ahead
- We should get the RP Wifi Dongle so we can access and install libraries onto the RP (RedPitaya), We can do this via ethernet by first installing to a laptop, but this would make it easier
- It might be possible to run code off the processor on the board, but that would require looking into the hardware of the processor to ensure it would be capable of handling the data load
- [x] Another consideration is using a SATA connection to store the data on an external SSD
	- These SATA looking connectors are not conventional connectors. 
		- [Schematic](https://downloads.redpitaya.com/doc/Customer_Schematics_STEM122-16SDR_V1r1%28Series1%29.PDF) shows them as S1,S2 connectors
		- these seems to be useful for internal clock sync and shown [here](https://redpitaya.readthedocs.io/en/latest/appsFeatures/applications/streaming/appXCStreaming.html)
		- **Only viable option is USB drive write using the internal API**

---

## 09/02/2024

### Internal Python api

- [ ] confirm the operation of internal API calls without using the network interface #task
- tutorial [here](https://redpitaya.readthedocs.io/en/latest/appsFeatures/remoteControl/API_scripts.html)
- [x] find the current version of the os #task ✅ 2024-02-22
- [x] Backup the original SD card as it is #task ✅ 2024-02-22
- [ ] Evaluate the write speed of USB/SD card. (running a benchmark) #task
