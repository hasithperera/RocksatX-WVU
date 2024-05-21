## folder locations

| location            | usage                                                  |
| ------------------- | ------------------------------------------------------ |
| /opt/data           | SD card alternate partition 50 GB                      |
| /opt/redpitaya      | internal utils for fpga level programming and start up |
| /opt/data/RedPitaya | external library for internal functions                |

## FPGA programming

To up date the fpga program 
`/opt/redpitaya/bin/fpgautil -b /opt/data/bin/<file.bin>`


## LP specs

- ADC data sheet: [here](https://www.ti.com/lit/ds/symlink/ads8881.pdf?ts=1716159539304&ref_url=https%253A%252F%252Fwww.mouser.fr%252F)
- page 25: this is the configuration currently in use. need to find a correct spi mode for this
- DAC: uses the external CS pin
- ADC: has the internal pin