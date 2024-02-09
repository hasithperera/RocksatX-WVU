
## Basic testing on the RP

## 08/02/2024

- Set up manual ip to be `192.168.11.10`
- Configure your computer to be on the same subnet ie. 192.168.11.xxx (subnet 255.255.255.0) and a unique address. you can look at the web interface by visiting [192.168.11.10](http://192.168.11.10)
- `/root/in` has the repo from redpitaya
- to send files use `scp <src> <destination>` or `rsync`
- refer doc for user name and password
- compiling c code from the example failed. Possible missing library/dependancies
- Setting the time can be done with `data mmddHHMMYYYY`. Note this is in UTC time (EST +5 h) may required to do on restart since NTP is not operational in the current setup

### Python
- 3rd party Wifi Dongle not working (Being detected by device, not connecting, possible driver issue)
- Able to run python script on laptop via SCPI Server
- Communicating commands via the ethernet, so once the connection is broken the program ends
### Thoughts on Roads ahead
- We should get the RP Wifi Dongle so we can access and install libraries onto the RP (RedPitaya), We can do this via ethernet by first installing to a laptop, but this would make it easier
- It might be possible to run code off the processor on the board, but that would require looking into the hardware of the processor to ensure it would be capable of handling the data load
- Another consideration is using a SATA connection to store the data on an external SSD

## 09/02/2024

### Internal Python api

- [ ] confirm the operation of internal API calls without using the network interface #task
- tutorial [here](https://redpitaya.readthedocs.io/en/latest/appsFeatures/remoteControl/API_scripts.html)
- [ ] find the current version of the os #task 
- [ ] Backup the original SD card as it is #task
- [ ] Evaluate the write speed of USB/SD card. (running a benchmark) #task 
