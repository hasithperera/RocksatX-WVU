

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>





int main(){

  uint32_t buff_size = 16384;
  float *buff = (float *)malloc(buff_size * sizeof(float));
	printf("Start program \n");
	printf("%d \n",sizeof(float));
	for(uint32_t i=0;i<buff_size;i++){
		*(buff+i) = ((float)rand()/(float)(RAND_MAX)) * 1.0 -0.5;
		//*(buff+i) = i * 1.00;	
}
	printf("init memory done! \n");

	FILE *write_ptr;
	write_ptr = fopen("test.bin","wb");  // w for write, b for binary
	fwrite(buff,sizeof(float),buff_size,write_ptr); // write 10 bytes from our buffer
		
	// call 2nd time to save more data

	
	fwrite(buff,sizeof(float),buff_size,write_ptr); // write 10 bytes from our buffer
	fwrite(buff,sizeof(float),buff_size,write_ptr); // write 10 bytes from our buffer


	return 0;
}


