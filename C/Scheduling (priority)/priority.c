#include <stdio.h>
#include <stdlib.h>

struct process {
	int processID;
	int priority;
	int burstTime;
	int totalTime;
	int waitTime;
};

int main() {
	int i, j, k, number, totalTurnAroundTime = 0, totalWaitTime = 0;
	float averageTurnAroundTime, averageWaitTime;
	struct process temp;

	printf("\n");
	printf("Scheduling \n");
	printf("\n");

	printf("W-Time : Wait Time \n");
	printf("B-Time : Burst Time \n");
	printf("T-Time : Total Time \n");
	printf("\n");

	printf("Number of Processes : ");
	scanf("%d", &number);
	printf("\n");

	struct process *process = (struct process *)calloc(number, sizeof(struct process));

	for (i = 0; i < number; i++) {
		printf("Priority of Process P%d (ms) : ", (i + 1));
		scanf("%d", &(process[i].priority));
		printf("B-Time for Process P%d (ms) : ", (i + 1));
		scanf("%d", &(process[i].burstTime));
		process[i].processID = i + 1;
		printf("\n");
	}

	for (i = 0; i < (number - 1); i++) {
		for (j = i; j < number; j++) {
			if ((process[i].priority > process[j].priority) || (process[i].priority == process[j].priority && process[i].processID > process[j].processID)) {
				temp = process[i];
				process[i] = process[j];
				process[j] = temp;
			}
		}
	}

	process[0].waitTime = 0;
	process[0].totalTime = process[0].burstTime;

	for (i = 1; i < number; i++) {
		process[i].waitTime = process[i - 1].totalTime;
		process[i].totalTime = process[i].waitTime + process[i].burstTime;
	}

	for (i = 0; i < number; i++) {
		totalWaitTime += process[i].waitTime;
		totalTurnAroundTime += process[i].totalTime;
	}

	averageWaitTime = (float)totalWaitTime / number;
	averageTurnAroundTime = (float)totalTurnAroundTime / number;

	printf("\n");
	printf("Priority Scheduling \n");
	printf("\n");

	i = 42;
	while (i--) {
		printf("-");
	}
	printf("\n");

	printf("Process\t W-Time\t B-Time\t T-Time\t Priority \n");

	i = 42;
	while (i--) {
		printf("-");
	}
	printf("\n");

	for (i = 0; i < number; i++) {
		printf("%4s%d\t %6d\t %6d\t %6d\t %8d \n", "P", process[i].processID, process[i].waitTime, process[i].burstTime, process[i].totalTime, process[i].priority);
	}

	i = 42;
	while (i--) {
		printf("-");
	}
	printf("\n");

	printf("\n");
	printf("Gantt Chart \n");
	printf("\n");

	i = totalTurnAroundTime - totalWaitTime + number * 2 + 1;
	while (i--) {
		printf("-");
	}
	printf("\n");

	printf("|");
	for (i = 0; i < number; i++) {
		k = process[i].burstTime / 2;
		for (j = 0; j < k; j++) {
			printf(" ");
		}

		printf("P%d", process[i].processID);

		for (j = k + 1; j < process[i].burstTime; j++) {
			printf(" ");
		}

		printf("|");
	}

	printf("\n");
	i = totalTurnAroundTime - totalWaitTime + number * 2 + 1;
	while (i--) {
		printf("-");
	}
	printf("\n");
	printf("%d", 0);

	for (i = 0; i < number; i++) {
		for (j = 0; j < process[i].burstTime; j++) {
			printf(" ");
		}

		printf("%2d", process[i].totalTime);

	}
	printf("\n");

	printf("\n");
	printf("Average Wait Time : %.2f ms \n", averageWaitTime);
	printf("Average TurnAround Time : %.2f ms \n", averageTurnAroundTime);
	printf("\n");

	return 0;
}