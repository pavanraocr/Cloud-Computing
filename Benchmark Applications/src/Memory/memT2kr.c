/*
 * memT2kr.c
 *
 *  Created on: Feb 8, 2016
 *      Author: pavan
 */


#include<stdio.h>
#include<string.h>
#include<sys/time.h>
#include<pthread.h>

const int memorySize = 100 * 1024;
const int fullSize = 100*1024*1024;
const int blockSize = 1024;

char *mainBlk, *coping;
int randomValue[100000];

void *transfer(void *argv)
{
	int i;
	for(i = 0; i < fullSize; i +=blockSize)
	{
		memcpy((coping + randomValue[i%100000]), (mainBlk + randomValue[i%100000]), blockSize);
	}
}

void main(void *argv)
{
	mainBlk = (char *)malloc(sizeof(char) * fullSize);
	coping = (char *)malloc(sizeof(char) * fullSize);
	int i;
	//clock_t start, end;
	struct timeval start, end;
	double timeTakenInSec;
	pthread_t t[2];

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

	for(i=0; i<2;i++)
	{
		pthread_create(&t[i], NULL, &transfer, NULL);
	}

	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);

	//end = clock();
	gettimeofday(&end, NULL);

	//timeTakenInSec = (double)(end-start)/CLOCKS_PER_SEC;
	timeTakenInSec = (end.tv_sec + (end.tv_usec/1000000.0))-(start.tv_sec + (start.tv_usec/1000000.0));

	printf("latency = %g\n", (double)(timeTakenInSec* 1000)/fullSize);

	printf("throughput =%g MB/s\n ", (double)(fullSize * 2)/(timeTakenInSec*1024*1024));

	free(mainBlk);
	free(coping);
}
