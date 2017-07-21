/*
 * memT1.c
 *
 *  Created on: Feb 6, 2016
 *      Author: pavan
*/

#include<stdio.h>
#include<string.h>
#include<sys/time.h>

const int memorySize = 1024*1024*100;
const int fullSize = 1024*1024*100;
const int blockSize = 1;

void main(void *argv)
{
	char *mainBlk = (char *)malloc(sizeof(char) * fullSize);
	char *coping = (char *)malloc(sizeof(char) * fullSize);
	int i;
	//clock_t start, end;
	float timeTakenInSec;
	struct timeval start, end;

	//prepares the source string with 100MB of data
	for(i = 0; i < memorySize ; i++)
	{
		memcpy((mainBlk + i), "a", 1);
	}

	//copies the data from one place to the other
	//start = clock();
	gettimeofday(&start, NULL);

	for(i = 0; i < fullSize; i+=blockSize)
	{
		memcpy((coping + i), (mainBlk + i), blockSize);
	}

	//end = clock();
	gettimeofday(&end, NULL);

	timeTakenInSec = (end.tv_sec + (end.tv_usec/1000000.0))-(start.tv_sec + (start.tv_usec/1000000.0));

	printf("latency = %g ms\n", (double)(timeTakenInSec * 1000)/fullSize);

	printf("throughput =%g MB/s\n ", (double)fullSize/(timeTakenInSec*1024*1024));

	free(mainBlk);
	free(coping);
}
