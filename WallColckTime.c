/*
 * WallColckTime.c
 *
 *  Created on: Nov 19, 2016
 *      Author: Yiwei
 */

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>
#include "P4Header.h"

void WallClockTime(int bufferSize)
{
struct timeval time;
FILE *myfile;
clock_t stime, etime;
char* mybuffer;
int i, j;
double iterations = 2147483648/bufferSize;
myfile = fopen("writefile.txt","w");

mybuffer = (char*) malloc(bufferSize);
 for(i=0; i<bufferSize; i++)
 {
	 *(mybuffer+i)='x';
 }

gettimeofday(&time, NULL);
stime = time.tv_sec + 1.0e-6*time.tv_usec;
for(j=0; j<iterations; j++)
 {
	 fwrite(mybuffer, bufferSize, 1, myfile);
 }
gettimeofday(&time, NULL);
etime = time.tv_sec + 1.0e-6*time.tv_usec;
printf("write wall-clock time for %i = %5.3f\n", bufferSize, (double)(etime-stime));

gettimeofday(&time, NULL);
stime = time.tv_sec + 1.0e-6*time.tv_usec;
for(j=0; j<iterations; j++)
 {
	 fread(mybuffer, bufferSize, 1, myfile);
 }
gettimeofday(&time, NULL);
etime = time.tv_sec + 1.0e-6*time.tv_usec;
printf("read wall-clock time for %i = %5.3f\n", bufferSize, (double)(etime-stime));

fclose(myfile);
}
