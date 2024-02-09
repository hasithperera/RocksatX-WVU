
## Basic testing on the RP

### 08/02/2024

- Set up manual ip to be `192.168.11.10`
- Configure your computer to be on the same subnet ie. 192.168.11.xxx (subnet 255.255.255.0) and a unique address. you can look at the web interface by visiting [192.168.11.10](http://192.168.11.10)
- `/root/in` has the repo from redpitaya
- to send files use `scp <src> <destination>` or `rsync`
- refer doc for user name and password
- compiling c code from the example failed. Possible missing library/dependancies
- Setting the time can be done with `data mmddHHMMYYYY`. Note this is in UTC time (EST +5 h) may required to do on restart since NTP is not operational in the current setup


