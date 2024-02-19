#!/usr/bin/python3

import time
import rp

#overlay (needs testing-add image needed)
from rp_overlay import overlay



period = 1e-2      # period in secodns

# Initialize the interface
rp.rp_Init()

#####! Choose one of two methods, comment the other !#####
#! METHOD 1: Interacting with Registers direclty
while 1:

    for i in range(0,255):
        rp.rp_LEDSetState(i)     # or 0b00000001
        time.sleep(period/2.0)
        rp.rp_LEDSetState(0b00000000)     # or 0

# Release resources
rp.rp_Release()

