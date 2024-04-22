## folder locations

| location            | usage                                                  |
| ------------------- | ------------------------------------------------------ |
| /opt/data           | SD card alternate partition 50 GB                      |
| /opt/redpitaya      | internal utils for fpga level programming and start up |
| /opt/data/RedPitaya | external library for internal functions                |

## FPGA programming

To up date the fpga program 
`/opt/redpitaya/bin/fpgautil -b /opt/data/bin/<file.bin>`

