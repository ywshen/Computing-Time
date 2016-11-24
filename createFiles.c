/*
 * createFiles.c
 *
 *  Created on: Nov 20, 2016
 *      Author: Yiwei
 */
#include <stdio.h>
#include <stdlib.h>
#include "P4Header.h"

void CreateFile()
{
	int i;
	    FILE *fp;

	    fp=fopen("readfile.txt","w");

	    for(i=0;i<(2147483648 );i++) {
	        fseek(fp,(/*1024*1024*1024*/ (2147483648) ), SEEK_SET);
	        fprintf(fp,"C");
	    }

	    fclose(fp);
}

