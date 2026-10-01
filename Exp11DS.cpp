#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push an opening bracket onto stack */
void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = ch;
}

/* Pop a bracket from stack */
char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}

/* Check whether brackets match */
int isMatchingPair(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    return 0;
}

/* Check balanced parentheses */
int checkParentheses(char expression[])
{
    int i;
    char ch, open;

    for (i = 0; expression[i] != '\0'; i++)
    {
        ch = expression[i];

        /* Opening brackets */
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }

        /* Closing brackets */
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (top == -1)
                return 0;

            open = pop();

            if (!isMatchingPair(open, ch))
                return 0;
        }
    }

    /* Stack should be empty */
    if (top == -1)
        return 1;

    return 0;
}

int main()
{
    char expression[MAX];

    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);

    if (checkParentheses(expression))
        printf("Parentheses are Balanced.\n");
    else
        printf("Parentheses are Not Balanced.\n");

    return 0;
}
