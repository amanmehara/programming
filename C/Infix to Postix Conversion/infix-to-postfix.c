/*
    GIVEN PROGRAM CONVERTS
    INFIX EXPRESSION TO IT'S POSTFIX FORM
    FOR STACK PURPOSE
    DYNAMIC STACK IS CREATED USING
    LINKED LIST
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node* link;
};

struct Node* head;

void push(char x)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->link=head;
    head=newNode;
}

char pop()
{
    struct Node* temp;
    temp=head;
    int val=head->data;
    head=head->link;
    free(temp);
    return val;

}

int isEmpty()
{
    if(head==NULL)
        return 1;
    else
        return 0;
}

char tos()
{
    return head->data;
}

int getPrecedence(char opt)
{
    switch (opt)
    {
    case '^':
        return 3;
    break;

    case '*':
    case '/':
        return 2;
    break;

    case '+':
    case '-':
        return 1;
    break;

    default:
        return 0;
    }
}

int isRightPrecedence(char opt)
{
    if(opt=='^')
        return 1;
    else
        return 0;
}

int isOpeningBracket(char ch)
{
    if(ch=='{' || ch=='[' || ch=='(' )
        return 1;
    else
        return 0;
}

int isClosingBracket(char ch)
{
    if ( ch=='}' || ch==']' || ch==')' )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperand(char C)
{
    if(C >= '0' && C <= '9') return 1;
	if(C >= 'a' && C <= 'z') return 1;
	if(C >= 'A' && C <= 'Z') return 1;
	return 0;
}

int isOperation(char exp)
{
    if(exp=='*' || exp=='/' || exp=='+' || exp=='-' || exp=='^')
        return 1;
    else
        return 0;
}

// function to check higher precedence among two operators
int isHighPrecedence(char top,char exp)
{
    if(getPrecedence(top)==getPrecedence(exp))
    {
        if(isRightPrecedence(exp))
        {
            return 0;
        }
        return 1;
    }
    if(getPrecedence(top)>getPrecedence(exp))
        return 1;
    else
        return 0;
}

void InfixToPostfix(char* arr)
{
    char result[100];
    int i,j=0;
    printf("\n");
    for( i=0; arr[i]!='\0'; i++)
    {
        if(isOperand(arr[i]))
        {
            result[j++]=arr[i];
        }
        else if(isOperation(arr[i]))
        {
            while(!isEmpty() && isHighPrecedence(tos(),arr[i]) )
                  {
                      result[j++]=tos();
                      pop();
                  }
                  push(arr[i]);
        }
        else if(isOpeningBracket(arr[i]))
        {
            push(arr[i]);
        }
        else if(isClosingBracket(arr[i]))
        {
            while(!isEmpty() &&  !isOpeningBracket(tos()) )
                  {
                      result[j++]=tos();
                      pop();
                  }
                  pop(); // poping the opening bracker
        }

    }
    while(!isEmpty())
    {
        result[j++]=tos();
        pop();
    }
    result[j++]='\0';
    printf("\nConverted Postfix Expression: %s",result);
}

int main()
{
    // example string (a+b)*c-d^e^f
    char input[100];
    printf("Enter the expression for converting to postfix: ");
    scanf("%s",&input);
    printf("\nInputed Infix Expression: %s",input);
    InfixToPostfix(input);
    return 0;
}

/* PROGRAM INPUT AND OUTPUT
Enter the expression for converting to postfix: (a+b)*c-d^e^f

Inputed Infix Expression: (a+b)*c-d^e^f

Converted Postfix Expression: ab+c*def^^-

*/
