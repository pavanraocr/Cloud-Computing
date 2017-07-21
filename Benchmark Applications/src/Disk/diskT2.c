/*
 * diskT2.c
 *
 *  Created on: Feb 11, 2016
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

void createFile(char *fileName){
	FILE *fp;
	int index, i;
	char *c = (char *)malloc(sizeof(int));
	printf("\nInitiating File Creation Sequence...\n");
	fp = fopen(fileName,"w+"); /* open for writing */

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
	if(timeTakenInSec < timeTakenInSec2)
		timeTakenInSec = timeTakenInSec2;

 	printf("Test for File Size: %d\tBlock Size: %d\n", (fullSize*2), blockSize);

	printf("latency = %g ms\n", (double)(timeTakenInSec * 1000)/(fullSize*2));

	printf("throughput =%g MB/s\n", (double)(fullSize*2)/(timeTakenInSec*1024*1024));
}


//--------------------- Two Threads ------------------------
void *evaluateReadSpeedsThreads1(void *argv)
{
	char *coping = (char *)malloc(sizeof(char) * blockSize);
	int random[100000];
	float emptyLoopTime;
	int i;
	int isRandom = argv;
	printf("isRandom = %d\n", isRandom);

	if(isRandom)
	{
		printf("Random generating...\n");
		for(i = 0; i < 100000; i++)
		{
			random[i] = rand() % (fullSize-blockSize);
		}
		printf("Random generation complete...\n");
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

void *evaluateReadSpeedsThreads2(void *argv)
{
	char *coping = (char *)malloc(sizeof(char) * blockSize);
	int random[100000];
	float emptyLoopTime;
	int i;
	int isRandom = argv;
	printf("isRandom = %d\n", isRandom);

	if(isRandom)
	{
		printf("Random generating...\n");
		for(i = 0; i < 100000; i++)
		{
			random[i] = rand() % (fullSize-blockSize);
		}
		printf("Random generation complete...\n");
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

		gettimeofday(&start2, NULL);

		for (i = 1; i <= fullSize; i+=blockSize)
		{
			fseek(src2, random[i%100000], SEEK_SET);
			fread(coping, blockSize, 1, src2);
		}

		gettimeofday(&end2, NULL);
		printf("completed time evaluation...\n");
	}
	else
	{
		gettimeofday(&start2, NULL);
		for (i = 1; i <= fullSize; i+=blockSize)
		{
			fread(coping, blockSize, 1, src2);
		}

		gettimeofday(&end2, NULL);
	}

	timeTakenInSec2 = (end2.tv_sec + (end2.tv_usec/1000000.0))-(start2.tv_sec + (start2.tv_usec/1000000.0));
	timeTakenInSec2 -= emptyLoopTime;

	free(coping);
}

void *evaluateWriteSpeedsThreads1(void *argv)
{
	char *coping = (char *)malloc(sizeof(char) * blockSize);
	int random[100000];
	int i;
	fullSize = 10485760;
	float emptyLoopTime;
	int isRandom = argv;
	printf("isRandom = %d\n", isRandom);

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

void *evaluateWriteSpeedsThreads2(void *argv)
{
	char *coping = (char *)malloc(sizeof(char) * blockSize);
	int random[100000];
	int i;
	fullSize = 10485760;
	float emptyLoopTime;
	int isRandom = argv;
	printf("isRandom = %d\n", isRandom);

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
		gettimeofday(&start2, NULL);

		for (i = 1; i <= fullSize; i+=blockSize)
		{
			fseek(src2, random[i%100000], SEEK_SET);
			fwrite(coping, blockSize, 1, src2);
		}

		gettimeofday(&end2, NULL);
		printf("completed time evaluation...\n");
	}
	else
	{
		//copies the data from one place to the other
		gettimeofday(&start2, NULL);

		for (i = 1; i <= fullSize; i+=blockSize)
		{
			fwrite(coping, blockSize, 1, src2);
		}

		gettimeofday(&end2, NULL);
	}


	timeTakenInSec2 = (end2.tv_sec + (end2.tv_usec/1000000.0))-(start2.tv_sec + (start2.tv_usec/1000000.0));
	timeTakenInSec2 -= emptyLoopTime;

	free(coping);
}

int main()
{
	int i;
	pthread_t t[2];

	printf("\n~~~~~~~~~~~~~~~~~TWO THREAD~~~~~~~~~~~~~~~~~\n");
	printf("\n***************Test for sequential reading****************\n");
	for(i = 0; i < 3; i++)
	{
		createFile("dummysrc.txt");
		printf("Creating 2nd file\n");
		createFile("dummysrc2.txt");
		src = fopen("dummysrc.txt", "r");
		src2 = fopen("dummysrc2.txt", "r");
		blockSize = (int)pow(1024, i);
		pthread_create(&t[0], NULL, &evaluateReadSpeedsThreads1, 0);
		pthread_create(&t[1], NULL, &evaluateReadSpeedsThreads2, 0);
		pthread_join(t[0], NULL);
		pthread_join(t[1], NULL);
		printOutput();
		fclose(src);
		fclose(src2);
	}

	printf("\n****************Test for sequential writing****************\n");
	for(i = 0; i < 3; i++)
	{
		createFile("dummysrc.txt");
		printf("Creating 2nd file\n");
		createFile("dummysrc2.txt");
		src = fopen("dummysrc.txt", "w");
		src2 = fopen("dummysrc2.txt", "w");
		blockSize = (int)pow(1024, i);
		pthread_create(&t[0], NULL, &evaluateWriteSpeedsThreads1, 0);
		pthread_create(&t[1], NULL, &evaluateWriteSpeedsThreads2, 0);
		pthread_join(t[0], NULL);
		pthread_join(t[1], NULL);
		printOutput();
		fclose(src);
		fclose(src2);
	}

	printf("\n****************Test for random reading****************\n");
	for(i = 0; i < 3; i++)
	{
		createFile("dummysrc.txt");
		printf("Creating 2nd file\n");
		createFile("dummysrc2.txt");
		src = fopen("dummysrc.txt", "r");
		src2 = fopen("dummysrc2.txt", "r");
		blockSize = (int)pow(1024, i);
		pthread_create(&t[0], NULL, &evaluateReadSpeedsThreads1, 1);
		pthread_create(&t[1], NULL, &evaluateReadSpeedsThreads2, 1);
		pthread_join(t[0], NULL);
		pthread_join(t[1], NULL);
		printOutput();
		fclose(src);
	}

	printf("\n****************Test for random writing****************\n");
	for(i = 0; i < 3; i++)
	{
		createFile("dummysrc.txt");
		printf("Creating 2nd file\n");
		createFile("dummysrc2.txt");
		src = fopen("dummysrc.txt", "w");
		src2 = fopen("dummysrc2.txt", "w");
		blockSize = (int)pow(1024, i);
		pthread_create(&t[0], NULL, &evaluateWriteSpeedsThreads1, 1);
		pthread_create(&t[1], NULL, &evaluateWriteSpeedsThreads2, 1);
		pthread_join(t[0], NULL);
		pthread_join(t[1], NULL);
		printOutput();
		fclose(src);
		fclose(src2);
	}

return 1;
}
