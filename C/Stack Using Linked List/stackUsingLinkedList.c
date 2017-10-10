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

int top(struct stack *stack) {
	if (isStackEmpty(stack)) {
		return INT_MIN;
	}
	return stack->top->data;
}

void deleteStack(struct stack *stack) {
	free(stack);
}

int main() {
	printf("\n");
	printf("Stack using Linked List. \n");
	printf("\n");

	printf("Initialising the stack \n");
	printf("\n");

	struct stack *stack = (struct stack *)malloc(sizeof(struct stack));

	if (!stack) {
		printf("Stack cannot be created. \nExiting. \n");
		exit(1);
	}

	stack->top = NULL;

	int choice;
	bool isExit = true;
	int number;

	while (isExit) {
		printf("Stack Operations : \n1. Push \n2. Pop \n3. Exit \n");
		scanf("%d", &choice);
		printf("\n");

		switch (choice) {
		case 1:
			printf("Number to Push : ");
			scanf("%d", &number);
			printf("\n");
			push(stack, number);
			break;
		case 2:
			number = pop(stack);
			if (number == INT_MIN) {
				printf("Nothing to Pop. \nStack is Empty. \n");
				break;
			}
			printf("Number Popped : %d \n", number);
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

	deleteStack(stack);

	return 0;
}