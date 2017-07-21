/*
 * memT1mr.c
 *
 *  Created on: Feb 7, 2016
 *      Author: pavan
 */

#include<stdio.h>
#include<string.h>
#include<sys/time.h>

const int memorySize = 100;
const int fullSize = 100*1024*1024;
const int blockSize = 1024;

void main(void *argv)
{
	char *mainBlk = (char *)malloc(sizeof(char) * fullSize);
	char *coping = (char *)malloc(sizeof(char) * fullSize);
	int randomValue[100000];
	int i;
	//clock_t start, end;
	struct timeval start, end;
	double timeTakenInSec;

	for(i = 0; i < 100000; i++)
	{
		randomValue[i] = rand()%fullSize;
	}

	//prepares the source string with 100MB of data
	for(i = 0; i < fullSize ; i++)
	{
		memcpy((mainBlk + i), "a", 1);
	}

	//copies the data from one place to the other
	//start = clock();
	gettimeofday(&start, NULL);

	for(i = 0; i < fullSize; i +=blockSize)
	{
		memcpy((coping + randomValue[i%100000]), (mainBlk + randomValue[i%100000]), blockSize);
	}

	//end = clock();
	gettimeofday(&end, NULL);

	//timeTakenInSec = (double)(end-start)/CLOCKS_PER_SEC;
	timeTakenInSec = (end.tv_sec + (end.tv_usec/1000000.0))-(start.tv_sec + (start.tv_usec/1000000.0));

	printf("latency = %g\n", (double)(timeTakenInSec* 1000)/fullSize);

	printf("throughput =%g MB/s\n ", (double)fullSize /(timeTakenInSec*1024*1024));

	free(mainBlk);
	free(coping);
}

