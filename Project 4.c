/*
 ============================================================================
 Name        : Project.c
 Author      : Yiwei Shen
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "P4Header.h"

int main(void) {
	int m;
	for (m=64; m<=65536; m=m*2)
	{
		ExecutionTime(m);
		WallClockTime(m);
	}
	return 0;
}
