## Output file format

The file name created during the experiment will have the following syntax `xxxxx_y_zzzzz.bin`.
- `xxxxx` specifies the run id. This is increased automatically on a code restart
- `y`indicates the experiment id. (LP: 1,2 Sounding:3-8)
- `zzzzz` specifies the time block

## Data inspection 
- ssh in to the redpitay
	- navigate in to `/opt/data/out`
	- get info about all the saved files:
		- `ls -la >> ../logs/data_files.log'
- get the log files
	- Navigate to a path on your mac where you would like the data to be stored
	- make a log directory in mac: `mkdir logs` 
	- copy log files `scp root@<ip>:/opt/data/logs/*.log ./logs/`
		- [ ] confirm there are `run.log`,`data_files.log` and `StartUpData.log` is now in `logs`
		- if these are not the contact me. Some things broken
		- general scp syntax: `scp root@<ip>:<path to file> ./`
	- inspect the `StartUpData.log` file to find the most recent experiment id
		- Notes: The last experiment id I have is `111` any thing close and beyond that is expected
		- if you see smaller numbers this would indicate a possible currepted log at some point\
	- run these on the redpitaya after ssh into it
		1. `cd /opt/data/out`
		2. `mkdir lp`
		3. `mv *_1_*.bin lp`
		4. `mv *_2_*.bin lp`
		5. `tar cfv lp_data.tar lp`
		6. `ls -lh lp_data.tar`: Check the size of this each experiment is about ~30 MB depending on how many experiments you have it would change
	- on the mac to copy the tar file: (move to where you want the data saved)
		- `scp root@<ip>:/opt/data/out/lo_data.tar ./` : Depending on file size with will take a while ~10 MB/s is the max speed
		- After you have confirmed data is saved correctly you can delete the `*.tar` file in the redpitaya
	- You can re do from step 2 and select specific experiments or data sets. change the folder name and the `mv` cmd accordingly 

- Do you guys have a log of what experiments were actually conducted during the last testing session 
	- when was the resistor attached ? 
	- was the antenna extended
## Cleaning up for new launch 

- To clean and remove all data 
	- **NOTE: Make absolutely sure that you have the old data saved**
	- `rm /opt/data/*.bin`
	- `rm /opt/data/logs/*.log`
