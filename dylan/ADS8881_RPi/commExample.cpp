//run w/ sudo ./commExample -C
//compile w/ sudo g++ -o commExample commExample.cpp
/*
 * SPI testing utility (using spidev driver)
 *
 * Copyright (c) 2007  MontaVista Software, Inc.
 * Copyright (c) 2007  Anton Vorontsov <avorontsov@ru.mvista.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 * Cross-compile with cross-gcc -I/path/to/cross-kernel/include
 */

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <sys/time.h>

#include <math.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

static void pabort(const char *s)
{
	perror(s);
	abort();
}

static const char *device = "/dev/spidev1.0";
static uint8_t mode;
static uint8_t bits = 8;
static uint32_t speed = 100000000;
static uint16_t delay =0;
static float average = 0.0;
static double voltage = 0.0;

static union{
	int outputCode;
	uint8_t rx[3];
};
int main(int argc, char *argv[])
{

	int fd = open(device, O_RDWR);
	if (fd < 0)
		pabort("can't open device");
	mode |= SPI_CS_HIGH;
	int ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret == -1)
		pabort("can't set spi mode");
	ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
	if (ret == -1)
		pabort("can't get spi mode");
	/*
	 * bits per word
	 */
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't set bits per word");
	ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't get bits per word");
	/*
	 * max speed hz
	 */
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't set max speed hz");
	ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't get max speed hz");
	printf("spi mode: %d\n", mode);
	printf("bits per word: %d\n", bits);
	printf("max speed: %d Hz (%d KHz)\n", speed, speed/1000);
int j = 10000;
int data[j];
data[j] = 0;
int time[j];
time[j] = 0;
uint8_t tx[3] = {
		0x00,0x00,0x00
	};
struct spi_ioc_transfer tr = {
		(long)tx,
		(long)rx,
		 ARRAY_SIZE(tx),
		speed,
		 delay,
		bits,
		false,
	};
timeval tv;
gettimeofday(&tv, NULL);
int start = tv.tv_usec;
for(int i = 0; i<j; i++)
{
//	gettimeofday(&tv, NULL);
//	time[i]=tv.tv_usec;
	outputCode=0;
	ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	data[i] = outputCode;
}
gettimeofday(&tv, NULL);
int finish = tv.tv_usec;

std::ofstream ADCData;
ADCData.open("/home/pi/ADCData.csv");
//average/=j;
//printf("Average %.4f \n", average);
for(int i = 0; i<j; i++)
{
	outputCode = data[i];
	outputCode = ((((int32_t)rx[0])<<16)|(((int16_t)rx[1])<<8)|rx[2])>>6;

        if((outputCode & 0x20000) == 0x20000)
        {
                outputCode=~outputCode;
                outputCode= outputCode&0x1ffff;
                outputCode=~outputCode;
        }
        else
        {
                outputCode = outputCode&0x1ffff;
	}
//	printf("OutputCode Bytes: %.2X\n", outputCode);
//	printf("ADC Output Code: %.3i\n", outputCode);
	voltage = ((double)2*4.5/(double)(pow(2.0, 18.0))) *outputCode ;
//	printf("Voltage: %2f\n\n", voltage);
	ADCData << time[i]  << "," << voltage << std::endl;
}
printf("Start: %8d\n", start);
printf("Finish: %8d\n", finish);
printf("Delta: %8d\n", finish - start);
	close(fd);
	ADCData.close();

	return ret;

}
