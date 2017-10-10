#include <stdio.h>
#include <stdlib.h>

struct stack {
	int top;
	int *array;
};

void push(struct stack *stack, int number) {
	stack->array[++stack->top] = number;
}

int pop(struct stack *stack) {
	return stack->array[stack->top--];
}

int isStackEmpty(struct stack *stack) {
	return (stack->top == -1 || !stack);
}

int main() {
	printf("\n");
	printf("Sorting an Array using 2 Stacks. \n");
	printf("\n");

	int n, i;
	printf("Enter the Size of Data to be sorted. \n");
	scanf("%d", &n);
	printf("\n");

	int *array;

	if ((array = (int *)calloc(n, sizeof(int))) == NULL) {
		printf("Memory not available. \nExiting! \n");
		exit(1);
	}

	printf("Input Data : \n");

	for (i = 0; i < n; i++) {
		scanf("%d", array + i);
	}
	printf("\n");

	struct stack *stack1, *stack2;

	stack1 = (struct stack *)malloc(sizeof(struct stack));
	stack1->top = -1;
	stack1->array = (int *)calloc(n, sizeof(int));

	stack2 = (struct stack *)malloc(sizeof(struct stack));
	stack2->top = -1;
	stack2->array = (int *)calloc(n, sizeof(int));

	push(stack1, *array);
	for (i = 1; i < n; i++) {
		if (stack1->array[stack1->top] >= *(array + i)) {
			push(stack1, *(array + i));
		}
		else {
			while ((stack1->array[stack1->top] < *(array + i)) && !isStackEmpty(stack1)) {
				push(stack2, pop(stack1));
			}
			push(stack1, *(array + i));
			while (!isStackEmpty(stack2)) {
				push(stack1, pop(stack2));
			}
		}
	}

	printf("Sorted Output : \n");

	for (i = 0; i < n; i++) {
		*(array + i) = pop(stack1);
		printf("%d \n", *(array + i));
	}
	printf("\n");

	return 0;
}