/*
 * cpuT2F.c
 *
 *  Created on: Feb 11, 2016
 *      Author: pavan
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>


int first[10][10], second[10][10];
const float loopCounter = 10000;
float timeTaken, timeTaken2, emptyLoop, emptyLoop2;

void *complexFunction(void *agrs)
{
	int c, d, k, i, j, l, c2, d2, k2;
	float multiply[10][10], sum, multiply1[10][10], sum1, multiply2[10][10], sum2;
	int counter;
	printf("complex function started\n");
	struct timeval start, end;

	gettimeofday(&start, NULL);
	for(counter = 0; counter < loopCounter; counter++){
		for (c = 0; c < 10; c++)
		{
			for (d = 0; d < 10; d++)
			{
			}
		}


		for (c2 = 0; c2 < 10; c2++)
		{
			for (d2 = 0; d2 < 10; d2++)
			{
			}
		}


		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
			}
		}
	}
	gettimeofday(&end, NULL);

	emptyLoop = (end.tv_sec + (end.tv_usec/1000000.0))-(start.tv_sec + (start.tv_usec/1000000.0));

	gettimeofday(&start, NULL);
	for(counter = 0; counter < loopCounter; counter++){
		for (c = 0; c < 10; c++)
		{
			for (d = 0; d < 10; d++)
			{
				for (k = 0; k < 10; k++)
				{
					sum = sum + first[c][k]*second[k][d] + second[c][k]*first[k][d] + second[c][k] - first[k][d] + second[k][d] * second[k][d] * second[k][d] - first[k][d] * first[k][d] * first[k][d] + second[c][d]*first[k][d] * second[c][d]*first[k][d] * second[c][d]*first[k][d];
				}
				multiply[c][d] = sum;
				sum = 0;
			}
		}


		for (c2 = 0; c2 < 10; c2++)
		{
			for (d2 = 0; d2 < 10; d2++)
			{
				for (k2 = 0; k2 < 10; k2++)
				{
					sum2 = sum2 + first[c2][k2]*second[k2][d2] + second[c2][k2]*first[k2][d2] + second[c2][k2] - first[k2][d2] + second[c2][k2] * second[c2][k2] * second[c2][k2] - first[k2][d2] * first[k2][d2] * first[k2][d2] + second[c2][d2]*first[k2][d2] * second[c2][d2]*first[k2][d2] * second[c2][d2]*first[k2][d2];
				}
				multiply2[c][d] = sum2;
				sum2 = 0;
			}
		}


		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				for (l = 0; l < 10; l++)
				{
					sum1 = sum1 + first[i][l]*second[l][j] + second[i][l]*first[l][j] + second[i][l] - first[l][j] + second[i][l] * second[i][l] * second[i][l] + first[l][j] *first[l][j] * first[l][j] + first[i][j]*second[l][j]*first[i][j]*second[l][j]*first[i][j]*second[l][j] ;
				}
				multiply1[i][j] = sum1;
				sum1 = 0;
			}
		}
	}
	gettimeofday(&end, NULL);

	timeTaken = (end.tv_sec + (end.tv_usec/1000000.0))-(start.tv_sec + (start.tv_usec/1000000.0));
	timeTaken -= emptyLoop;

	printf("complex function finished\n");

	return NULL;
}

void *complexFunction2(void *agrs)
{
	int c, d, k, i, j, l, c2, d2, k2;
	float multiply[10][10], sum, multiply1[10][10], sum1, multiply2[10][10], sum2;
	int counter;
	printf("complex function started\n");
	struct timeval start2, end2;

	gettimeofday(&start2, NULL);
	for(counter = 0; counter < loopCounter; counter++){
		for (c = 0; c < 10; c++)
		{
			for (d = 0; d < 10; d++)
			{
			}
		}


		for (c2 = 0; c2 < 10; c2++)
		{
			for (d2 = 0; d2 < 10; d2++)
			{
			}
		}


		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
			}
		}
	}
	gettimeofday(&end2, NULL);

	emptyLoop2 = (end2.tv_sec + (end2.tv_usec/1000000.0))-(start2.tv_sec + (start2.tv_usec/1000000.0));

	gettimeofday(&start2, NULL);
	for(counter = 0; counter < loopCounter; counter++){
		for (c = 0; c < 10; c++)
		{
			for (d = 0; d < 10; d++)
			{
				for (k = 0; k < 10; k++)
				{
					sum = sum + first[c][k]*second[k][d] + second[c][k]*first[k][d] + second[c][k] - first[k][d] + second[k][d] * second[k][d] * second[k][d] - first[k][d] * first[k][d] * first[k][d] + second[c][d]*first[k][d] * second[c][d]*first[k][d] * second[c][d]*first[k][d];
				}
				multiply[c][d] = sum;
				sum = 0;
			}
		}


		for (c2 = 0; c2 < 10; c2++)
		{
			for (d2 = 0; d2 < 10; d2++)
			{
				for (k2 = 0; k2 < 10; k2++)
				{
					sum2 = sum2 + first[c2][k2]*second[k2][d2] + second[c2][k2]*first[k2][d2] + second[c2][k2] - first[k2][d2] + second[c2][k2] * second[c2][k2] * second[c2][k2] - first[k2][d2] * first[k2][d2] * first[k2][d2] + second[c2][d2]*first[k2][d2] * second[c2][d2]*first[k2][d2] * second[c2][d2]*first[k2][d2];
				}
				multiply2[c][d] = sum2;
				sum2 = 0;
			}
		}


		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				for (l = 0; l < 10; l++)
				{
					sum1 = sum1 + first[i][l]*second[l][j] + second[i][l]*first[l][j] + second[i][l] - first[l][j] + second[i][l] * second[i][l] * second[i][l] + first[l][j] *first[l][j] * first[l][j] + first[i][j]*second[l][j]*first[i][j]*second[l][j]*first[i][j]*second[l][j] ;
				}
				multiply1[i][j] = sum1;
				sum1 = 0;
			}
		}
	}
	gettimeofday(&end2, NULL);

	timeTaken2 = (end2.tv_sec + (end2.tv_usec/1000000.0))-(start2.tv_sec + (start2.tv_usec/1000000.0));
	timeTaken2 -= emptyLoop2;

	printf("complex function finished\n");

	return NULL;
}

int main(int argc, char *argv[]) {
	int i,c;
	double totalInstructions;

	for(i = 0; i < 10; i++)
	{
		for(c = 0; c < 10; c++)
		{
			first[i][c] = rand() % 791;
			second[i][c] = rand() % 791;
		}
	}

	pthread_t t[2];

	pthread_create(&t[0], NULL, &complexFunction, NULL);
	pthread_create(&t[1], NULL, &complexFunction2, NULL);

	for(i = 0; i < 2; i++)
		pthread_join(t[i], NULL);

	if(timeTaken2 > timeTaken)
		timeTaken = timeTaken2;

	printf("GFLOPS = %f\ttotal time taken = %f\n", (loopCounter * 3000 * 54 * 2)/(timeTaken * 1000000000), timeTaken);

}

