### Backup SD image

- Used disk utility to graphically make an image (Image is the whole disk and it ~32 GB)
- `dd` can be used to make a reduced image
	- `dd if='/dev/sdx' of='<output>' bs=<> count=<>`
	- bs: sector size from `fdisk /dev/mmcblk0`
	- count: last partition secors + 1 
- Write this image back and test operation 
	- Used a 64 GB card (my personal card)
	- Writing speed: 52 MB/s
	- `rp_min.img` worked with the FPGA 
- [x] upgrade OS ✅ 2024-02-12
- [x] Make extra partition for external data and make it mount during boot #task ✅ 2024-02-12
	- made a 50 GB partition on the end of the chip 
	![](res/Pasted%20image%2020240212235307.png)
	- [x] mount the new partition #task ✅ 2024-02-13
		- `/dev/mmcblk0p4` is mounted on `/opt/data`
		- change `/etc/fstab` to change mount points. (No need to change this setting unless other external devices are added. eg USB Drive)
	- left extra 1 GB space to make backing up the os easy
	  
---
## Check the API calls

- Default installed RP OS is 1.04
- `git clone https://github.com/RedPitaya/RedPitaya.git`
-  Compatible branch is 2022.2 (Python is not supported)
	- We will have to update the OS 
- `../src/main.py` - A program to count in binary on the LED's
	- This is running as long as you are running the python file
	- need to set sources to set the correct location for the libraries
- [ ] make this program run on startup #task
	- a service `ahe` is created to execute `/opt/data/hasith/main.py`
	- RP libraries are linked to the same folder (This allows it to be able to run at init)
	- Working configuration
		- `Wants=network.target`
		- `After=syslog.target network-online.target` 
		- Currently it waits for network to come online. 
			- During startup a new FPGA image is written.this needs to be disabled some how. 
			![](res/Pasted%20image%2020240213030709.png)
			I found another FPGA write sequence after my process. Needs to disable this to get it runing at the start
	
## Signal generation 

- [ ] Check function generation using Python #task
- [ ] FFT and data logging with Python  #task
	- [ ] Save binary files 

---
