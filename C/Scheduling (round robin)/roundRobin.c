#include <stdio.h>
#include <stdlib.h>

struct process {
	int processID;
	int burstTime;
	int totalTime;
	int waitTime;
	int timeSlotsRequired;
	int remaining;
};

int main() {
	int i, j, k, x;
	int number, timeQuantum, maximum = 0, time = 0, totalTimeSlotsRequired = 0;
	int totalWaitTime = 0, totalBurstTime = 0, totalTurnAroundTime = 0;
	float averageTurnAroundTime, averageWaitTime;

	printf("\n");
	printf("Scheduling \n");
	printf("\n");

	printf("W-Time : Wait Time \n");
	printf("B-Time : Burst Time \n");
	printf("T-Time : Total Time \n");
	printf("\n");

	printf("Number of Processes : ");
	scanf("%d", &number);
	printf("Time Quantum (ms) : ");
	scanf("%d", &timeQuantum);
	printf("\n");

	struct process *process = (struct process *)calloc(number, sizeof(struct process));

	for (i = 0; i < number; i++) {
		printf("B-Time for Process P%d (ms) : ", (i + 1));
		scanf("%d", &(process[i].burstTime));

		process[i].timeSlotsRequired = process[i].burstTime / timeQuantum;

		if (process[i].burstTime%timeQuantum != 0) {
			process[i].timeSlotsRequired++;
		}

		process[i].processID = i + 1;
		process[i].remaining = process[i].timeSlotsRequired;

		totalBurstTime += process[i].burstTime;

		totalTimeSlotsRequired += process[i].timeSlotsRequired;
		if (maximum < process[i].timeSlotsRequired) {
			maximum = process[i].timeSlotsRequired;
		}
	}
	printf("\n");

	for (x = 0; x < maximum; x++) {
		for (i = 0; i < number; i++) {
			if (process[i].remaining>1) {
				time += timeQuantum;
			}
			else if (process[i].remaining == 1) {

				if (((process[i].burstTime) % timeQuantum) != 0) {
					time += (process[i].burstTime) % timeQuantum;
					process[i].totalTime = time;
					process[i].waitTime = process[i].totalTime - process[i].burstTime;
				}
				else {
					time += timeQuantum;
					process[i].totalTime = time;
					process[i].waitTime = process[i].totalTime - process[i].burstTime;
				}
			}
			process[i].remaining--;
		}
	}

	for (i = 0; i < number; i++) {
		totalWaitTime += process[i].waitTime;
		totalTurnAroundTime += process[i].totalTime;
	}

	averageWaitTime = (float)totalWaitTime / number;
	averageTurnAroundTime = (float)totalTurnAroundTime / number;

	printf("\n");
	printf("Round Robin Scheduling \n");
	printf("\n");

	i = 32;
	while (i--) {
		printf("-");
	}
	printf("\n");

	printf("Process\t W-Time\t B-Time\t T-Time \n");

	i = 32;
	while (i--) {
		printf("-");
	}
	printf("\n");

	for (i = 0; i < number; i++) {
		printf("%4s%d\t %6d\t %6d\t %6d\t \n", "P", process[i].processID, process[i].waitTime, process[i].burstTime, process[i].totalTime);
	}

	i = 32;
	while (i--) {
		printf("-");
	}
	printf("\n");

	printf("\n");
	printf("Gantt Chart \n");
	printf("\n");

	i = totalBurstTime + totalTimeSlotsRequired * 2 + 1;
	while (i--) {
		printf("-");
	}
	printf("\n");

	for (i = 0; i < number; i++) {
		process[i].remaining = process[i].timeSlotsRequired;
	}

	printf("|");

	for (x = 0; x < maximum; x++) {
		for (i = 0; i < number; i++) {
			if (process[i].remaining>1) {
				k = timeQuantum / 2;
				for (j = 0; j < k; j++) {
					printf(" ");
				}

				printf("P%d", process[i].processID);

				for (j = k + 1; j < timeQuantum; j++) {
					printf(" ");
				}

				printf("|");
			}
			else if (process[i].remaining==1) {
				if (((process[i].burstTime) % timeQuantum) != 0) {
					k = ((process[i].burstTime) % timeQuantum) / 2;
					for (j = 0; j < k; j++) {
						printf(" ");
					}

					printf("P%d", process[i].processID);

					for (j = k + 1; j < ((process[i].burstTime) % timeQuantum); j++) {
						printf(" ");
					}

					printf("|");
				}
				else {
					k = timeQuantum / 2;
					for (j = 0; j < k; j++) {
						printf(" ");
					}

					printf("P%d", process[i].processID);

					for (j = k + 1; j < timeQuantum; j++) {
						printf(" ");
					}

					printf("|");
				}
			}
			process[i].remaining--;
		}
	}

	printf("\n");
	i = totalBurstTime + totalTimeSlotsRequired * 2 + 1;
	while (i--) {
		printf("-");
	}
	printf("\n");

	for (i = 0; i < number; i++) {
		process[i].remaining = process[i].timeSlotsRequired;
	}

	printf("%d", 0);

	time = 0;
	for (x = 0; x < maximum; x++) {
		for (i = 0; i < number; i++) {
			if (process[i].remaining>1) {
				for (j = 0; j < timeQuantum; j++) {
					printf(" ");
				}

				time += timeQuantum;
				printf("%2d", time);
			}
			else if (process[i].remaining == 1) {

				if (((process[i].burstTime) % timeQuantum) != 0) {
					for (j = 0; j < ((process[i].burstTime) % timeQuantum); j++) {
						printf(" ");
					}

					time += (process[i].burstTime) % timeQuantum;
				}
				else {
					for (j = 0; j < timeQuantum; j++) {
						printf(" ");
					}

					time += timeQuantum;
				}
				printf("%2d", time);
			}
			process[i].remaining--;
		}
	}
	printf("\n");


	printf("\n");
	printf("Average Wait Time : %.2f ms \n", averageWaitTime);
	printf("Average TurnAround Time : %.2f ms \n", averageTurnAroundTime);
	printf("\n");

	return 0;
}