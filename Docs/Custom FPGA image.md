
## Random number generator

- figure out the details for vivado to run the same pipe line using Matlab and model composer. see how feasible this is

---
### Backup SD image

- Used disk utility to graphically make an image (Image is the whole disk and it ~32 GB)
- `dd` can be used to make a reduced image
	- `dd if='/dev/sdx' of='<output>' bs=<> count=<>`
	- bs: sector size from `fdisk /dev/mmcblk0`
	- count: last partition + 1 
- Write this image back and test operation 
	- Used a 64 GB card
	- Writing speed: 52 MB/s
	- `rp_min.img` worked with the FPGA 
- [ ] upgrade OS
- [ ] Make extra partition for external data and make it mount during boot #task

## Check the API calls

- Default installed RP OS is 1.04
- `git clone https://github.com/RedPitaya/RedPitaya.git`
-  Compatible branch is 2022.2 (Python is not supported)
	- We will have to update the OS 
---
