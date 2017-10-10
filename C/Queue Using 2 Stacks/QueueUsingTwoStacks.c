#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct stackNode {
	int data;
	struct stackNode *next;
};

struct stack {
	struct stackNode *top;
};

struct queue {
	struct stack *stack1;
	struct stack *stack2;
};

void push(struct stack *stack, int data) {
	struct stackNode *temp;

	temp = (struct stackNode *)malloc(sizeof(struct stackNode));

	temp->data = data;
	temp->next = stack->top;
	stack->top = temp;
}

int isStackEmpty(struct stack *stack) {
	return (!(stack->top));
}

int pop(struct stack *stack) {
	int data;
	struct stackNode *temp;

	if (isStackEmpty(stack)) {
		return INT_MIN;
	}

	temp = stack->top;
	stack->top = stack->top->next;
	data = temp->data;
	free(temp);
	return data;
}

void enqueue(struct queue *queue, int data) {
	push(queue->stack1, data);
}

int dequeue(struct queue *queue) {
	if (!isStackEmpty(queue->stack2)) {
		return pop(queue->stack2);
	}
	else {
		while (!isStackEmpty(queue->stack1)) {
			push(queue->stack2, pop(queue->stack1));
		}
		return pop(queue->stack2);
	}
}

void deleteQueue(struct queue *queue) {
	free(queue);
}

int main() {
	printf("\n");
	printf("Queue using 2 stacks. \n");
	printf("\n");

	printf("Initialising the Queue \n");
	printf("\n");

	struct queue *queue = (struct queue *)malloc(sizeof(struct queue));

	if (!queue) {
		printf("Queue cannot be created. \nExiting. \n");
		exit(1);
	}

	queue->stack1 = (struct stack *)malloc(sizeof(struct stack));
	queue->stack1->top = NULL;

	queue->stack2 = (struct stack *)malloc(sizeof(struct stack));
	queue->stack2->top = NULL;

	int choice;
	bool isExit = true;
	int number;

	while (isExit) {
		printf("Stack Operations : \n1. Enqueue \n2. Dequeue \n3. Exit \n");
		scanf("%d", &choice);
		printf("\n");

		switch (choice) {
		case 1:
			printf("Number to Enqueue : ");
			scanf("%d", &number);
			printf("\n");
			enqueue(queue, number);
			break;
		case 2:
			number = dequeue(queue);
			if (number == INT_MIN) {
				printf("Nothing to Dequeue. \nQueue is Empty. \n");
				break;
			}
			printf("Number Dequeued : %d \n", number);
			break;
		case 3:
			printf("Exiting. \n");
			isExit = false;
			break;
		default:
			isExit = false;
			break;
		}

		printf("\n");
	}

	return 0;
}