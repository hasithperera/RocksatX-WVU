
# What needs done?
## Sounding


| id  | type    | I/O | no of pins    | Descriptions                         | ref | FPGA pin | sub block (FPGA) |     |     |
| --- | ------- | --- | ------------- | ------------------------------------ | --- | -------- | ---------------- | --- | --- |
| 1   | Digital | in  | 1             | TE from Woleps                       |     |          | D+               |     |     |
| 2   | Digital | out | 3             | PWM (counter)                        |     |          | D+               |     |     |
| 3   | Analog  | out | 1 (8 bit DAC) | LP voltage sweep                     |     |          | LP               |     |     |
| 4   | Analog  | in  | 1             | LP current                           |     | RF in 1  | LP               |     |     |
| 5   | Analog  | out | 1             | sounding TX to Amp                   |     |          | S                |     |     |
| 6   | Analog  | in  | 1             | Sounding RX from amp                 |     |          | S                |     |     |
| 7   | Analog  | out | 2             | Switch component before each antenna |     |          | S                |     |     |
|     |         |     |               |                                      |     |          |                  |     |     |
|     |         |     |               |                                      |     |          |                  |     |     |
|     |         |     |               |                                      |     |          |                  |     |     |
## LP
## Deployment +
## FPGA
