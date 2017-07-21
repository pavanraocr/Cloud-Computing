/*
 * diskT1rbs.c
 *
 *  Created on: Feb 10, 2016
 *      Author: pavan
 */


#include<stdio.h>
#include<string.h>
#include<sys/time.h>
#include<math.h>
#include<pthread.h>

int fullSize;
int blockSize;
float timeTakenInSec, timeTakenInSec2;
struct timeval start, end, start2, end2;
FILE *src, *src2;
int isSecondFile;

void createFile(char *fileName){
	FILE *fp;
	int index, i;
	char *c = (char *)malloc(sizeof(int));
	printf("\nInitiating File Creation Sequence...\n");
	fp = fopen("dummysrc.txt","w+"); /* open for writing */

	for (i = 1; i <= 10240; i++)
	{
		for (index = 1; index <= 1024; index++)
		{
			sprintf(c,"%d",rand()%26);
			fprintf(fp, c);
		}
	}

	fseek(fp, 0L, SEEK_END);
	fullSize = ftell(fp);
	printf("File Creation Complete...\n");
	free(c);
	fclose(fp); /* close the file before ending program */
}

void printOutput()
{
	printf("Test for File Size: %d\tBlock Size: %d\n", fullSize, blockSize);

	printf("latency = %g ms\n", (double)(timeTakenInSec * 1000)/fullSize);

	printf("throughput =%g MB/s\n", (double)fullSize/(timeTakenInSec*1024*1024));
}

void evaluateReadSpeeds(FILE *src, int isRandom)
{
	char *coping = (char *)malloc(sizeof(char) * blockSize);
	int random[100000];
	float emptyLoopTime;
	int i;

	if(isRandom)
	{
		printf("Random generating...\n");
		for(i = 0; i < 100000; i++)
		{
			random[i] = rand() % (fullSize-blockSize);
		}
	}

	//copies the data from one place to the other
	gettimeofday(&start, NULL);

	for (i = 1; i <= fullSize; i+=blockSize)
	{}

	gettimeofday(&end, NULL);
	emptyLoopTime = (end.tv_sec + (end.tv_usec/1000000.0))-(start.tv_sec + (start.tv_usec/1000000.0));

	if(isRandom)
	{
		i=0;
		printf("started with time evaluation...\n");
		gettimeofday(&start, NULL);

		for (i = 1; i <= fullSize; i+=blockSize)
		{
			fseek(src, random[i%100000], SEEK_SET);
			fread(coping, blockSize, 1, src);
		}

		gettimeofday(&end, NULL);
		printf("completed time evaluation...\n");
	}
	else
	{
		gettimeofday(&start, NULL);

		for (i = 1; i <= fullSize; i+=blockSize)
		{
			fread(coping, blockSize, 1, src);
		}

		gettimeofday(&end, NULL);
	}

	timeTakenInSec = (end.tv_sec + (end.tv_usec/1000000.0))-(start.tv_sec + (start.tv_usec/1000000.0));

	timeTakenInSec -= emptyLoopTime;

	free(coping);
}

void evaluateWriteSpeeds(FILE *src, int isRandom)
{
	char *coping = (char *)malloc(sizeof(char) * blockSize);
	int random[100000];
	int i;
	fullSize = 10485760;
	float emptyLoopTime;

	for(i = 0; i < blockSize; i++)
	{
		coping[i] = 'a';
	}

	if(isRandom)
	{
		printf("Random generating...\n");
		for(i = 0; i < 100000; i++)
		{
			random[i] = rand() % (fullSize-blockSize);
		}
		printf("Random generation complete...\n");
	}

	//calculation for empty loop
	gettimeofday(&start, NULL);

	for (i = 1; i <= fullSize; i+=blockSize)
	{}

	gettimeofday(&end, NULL);
	emptyLoopTime = (end.tv_sec + (end.tv_usec/1000000.0))-(start.tv_sec + (start.tv_usec/1000000.0));

	if(isRandom)
	{
		printf("started with time evaluation...\n");
		//copies the data from one place to the other
		gettimeofday(&start, NULL);

		for (i = 1; i <= fullSize; i+=blockSize)
		{
			fseek(src, random[i%100000], SEEK_SET);
			fwrite(coping, blockSize, 1, src);
		}

		gettimeofday(&end, NULL);
		printf("completed time evaluation...\n");
	}
	else
	{
		//copies the data from one place to the other
		gettimeofday(&start, NULL);

		for (i = 1; i <= fullSize; i+=blockSize)
		{
			fwrite(coping, blockSize, 1, src);
		}

		gettimeofday(&end, NULL);
	}

	timeTakenInSec = (end.tv_sec + (end.tv_usec/1000000.0))-(start.tv_sec + (start.tv_usec/1000000.0));
	timeTakenInSec -= emptyLoopTime;

	free(coping);
}




int main()
{
	int i;

	printf("\n~~~~~~~~~~~~~~~~~SINGLE THREAD~~~~~~~~~~~~~~~~~\n");

	printf("\n***************Test for sequential reading****************\n");
	for(i = 0; i < 3; i++)
	{
		createFile("dummysrc.txt");
		src = fopen("dummysrc.txt", "r");
		blockSize = (int)pow(1024, i);
		evaluateReadSpeeds(src, 0);
		printOutput();
		fclose(src);
	}

	printf("\n****************Test for sequential writing****************\n");
	for(i = 0; i < 3; i++)
	{
		createFile("dummysrc.txt");
		src = fopen("dummysrc.txt", "w");
		blockSize = (int)pow(1024, i);
		evaluateWriteSpeeds(src, 0);
		printOutput();
		fclose(src);
	}

	printf("\n****************Test for random reading****************\n");
	for(i = 0; i < 3; i++)
	{
		createFile("dummysrc.txt");
		src = fopen("dummysrc.txt", "r");
		blockSize = (int)pow(1024, i);
		evaluateReadSpeeds(src, 1);
		printOutput();
		fclose(src);
	}

	printf("\n****************Test for random writing****************\n");
	for(i = 0; i < 3; i++)
	{
		createFile("dummysrc.txt");
		src = fopen("dummysrc.txt", "w");
		blockSize = (int)pow(1024, i);
		evaluateWriteSpeeds(src, 1);
		printOutput();
		fclose(src);
	}
	return 1;
}


