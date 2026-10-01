#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char opStack[MAX];
int top = -1;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

void pushOp(char c)
{
    opStack[++top] = c;
}

char popOp()
{
    return opStack[top--];
}

char peekOp()
{
    return opStack[top];
}

/* a) Infix to Postfix */
void infixToPostfix(char infix[], char postfix[])
{
    int i, k = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if (isspace(c))
            continue;

        /* Operand: variable or number */
        if (isalnum(c))
        {
            postfix[k++] = c;
        }
        else if (c == '(')
        {
            pushOp(c);
        }
        else if (c == ')')
        {
            while (top != -1 && peekOp() != '(')
                postfix[k++] = popOp();

            if (top != -1)
                popOp();   // Remove '('
        }
        else
        {
            while (top != -1 &&
                   peekOp() != '(' &&
                   precedence(peekOp()) >= precedence(c))
            {
                postfix[k++] = popOp();
            }

            pushOp(c);
        }
    }

    while (top != -1)
        postfix[k++] = popOp();

    postfix[k] = '\0';
}

/* b) Evaluate Postfix */
int evaluatePostfix(char postfix[], int values[])
{
    int stack[MAX];
    int top = -1;
    int i;
    char c;
    int a, b;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        c = postfix[i];

        if (isdigit(c))
        {
            stack[++top] = c - '0';
        }
        else if (isalpha(c))
        {
            /*
             * A=0, B=1, C=2, ...
             * values[] contains marks for variables.
             */
            stack[++top] = values[toupper(c) - 'A'];
        }
        else
        {
            b = stack[top--];
            a = stack[top--];

            switch (c)
            {
                case '+':
                    stack[++top] = a + b;
                    break;

                case '-':
                    stack[++top] = a - b;
                    break;

                case '*':
                    stack[++top] = a * b;
                    break;

                case '/':
                    stack[++top] = a / b;
                    break;

                case '^':
                {
                    int result = 1;
                    while (b--)
                        result *= a;
                    stack[++top] = result;
                    break;
                }
            }
        }
    }

    return stack[top];
}

int main()
{
    char infix[MAX], postfix[MAX];
    int values[26] = {0};
    char variable;
    int n, i;

    printf("Enter marks formula: ");
    fgets(infix, MAX, stdin);

    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("\nPostfix expression: %s\n", postfix);

    printf("\nEnter number of subjects/variables: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter variable and marks (e.g. A 85): ");
        scanf(" %c %d", &variable, &values[toupper(variable) - 'A']);
    }

    printf("\nCalculated result = %d\n",
           evaluatePostfix(postfix, values));

    return 0;
}
