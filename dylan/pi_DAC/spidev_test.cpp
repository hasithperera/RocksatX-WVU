/*
 * SPI testing utility (using spidev driver)
 *
 * Copyright (c) 2007  MontaVista Software, Inc.
 * Copyright (c) 2007  Anton Vorontsov <avorontsov@ru.mvista.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
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
#include <stdlib.h> //ahe
/*
#include <iostream>
#include <fstream>
#include <sstream>*/
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
static uint32_t speed = 50000;
static uint16_t delay = 200;


int main(int argc, char *argv[])
{

	int fd = open(device, O_RDWR);
	if (fd < 0)
		pabort("can't open device");
	//mode |= SPI_CS_HIGH;
	mode = 0;
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

uint8_t tx[3] = {
		0x00,0x00,0x00
	};
uint8_t rx[3] = {0x00};

struct spi_ioc_transfer tr = {
		(long)tx,
		(long)rx,
		 ARRAY_SIZE(tx),
		speed,
		 delay,
		bits,
		false,
	};
union{
	uint32_t outputCode;
	uint8_t OCBytes[4];
};
bool exit = false;

for(int i = 0; i < 100; i++)
{
for(outputCode = 0; outputCode < (uint32_t)65535; outputCode+=255)
{
	printf("%2d\t%2X %2X\n", outputCode, OCBytes[1], OCBytes[0]);
	tx[1]=OCBytes[1];
	tx[2]=OCBytes[0];
//	printf("%2d\t%2X %2X\n", outputCode, tx[1], tx[2]);
	ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	printf("test delay");
	sleep(1000);
}

for(outputCode = 65280; !exit; outputCode-=255)
{
	printf("%2d\t%2X %2X\n", outputCode, OCBytes[1], OCBytes[0]);
	tx[1]=OCBytes[1];
	tx[2]=OCBytes[0];
	//ioctl(fd, SPI_IOC_MESSAGE(1), &tr); //ahe - spi cmd
	//printf("%2d\t%2X %2X\n", outputCode, tx[1], tx[2]);
	if(outputCode == 0) 
		break;
}

}
	close(fd);
	return ret;

}
