/*
 * ExecutionTime.c
 *
 *  Created on: Nov 19, 2016
 *      Author: Yiwei
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include "P4Header.h"

void ExecutionTime(int bufferSize)
{
 FILE *myfile;
 clock_t stime, etime;
 char* mybuffer;
 myfile = fopen("writefile.txt","w");
 int i, j;
 double iterations = 2147483648/bufferSize;
 mybuffer = (char*) malloc(bufferSize);
 for(i=0; i<bufferSize; i++)
 {
	 *(mybuffer+i)='x';
 }
 stime = clock();
 for(j=0; j<iterations; j++)
 {
	 fwrite(mybuffer, bufferSize, 1, myfile);
 }
 etime = clock();
 printf("write execution-time for %i = %f\n", bufferSize,((double)(etime-stime)/CLOCKS_PER_SEC));

 stime = clock();
 for(j=0; j<iterations; j++)
 {
	 fwrite(mybuffer, bufferSize, 1, myfile);
 }
 etime = clock();
 printf("read execution-time for %i = %f\n", bufferSize, ((double)(etime-stime)/CLOCKS_PER_SEC));

 fclose(myfile);
}
