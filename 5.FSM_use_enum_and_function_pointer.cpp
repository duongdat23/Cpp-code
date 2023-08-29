#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum state { S1, S2, S3 };

int func1(int a, int b);
int func2(int a, int b);
int func3(int a, int b);
int func4(int a, int b);
int func5(int a, int b);
int func6(int a, int b);

void main()
{
    enum state currentState, nextState;
    int x = 3, y = 2;
    int input, output, indexFunc;
    int (*ptr_func[])(int, int) = { func1, func2, NULL,
                                    NULL, func3, func4,
                                    func6, func5, NULL };
    currentState = S1;
    nextState = S1;

    while (1)
    {
        scanf_s("%d", &input);
        printf("input = %d\n", input);
        if (input > 1) break;
        currentState = nextState;
        switch (currentState)
        {
        case S1:
            printf("Current state: S1\n");
            if (input == 0)
                nextState = S2;
            else
                nextState = S1;
            break;
        case S2:
            printf("Current state: S2\n");
            if (input == 0)
                nextState = S2;
            else
                nextState = S3;
            break;
        case S3:
            printf("Current state: S3\n");
            if (input == 0)
                nextState = S1;
            else
                nextState = S2;
            break;
        default:
            break;
        }
        indexFunc = 3 * currentState + nextState;
        output = (*ptr_func[indexFunc])(x, y);
        printf("\noutput = %d\n", output);
    }

}

int func1(int a, int b)
{
    printf("func1: X+Y");
    return a + b;
}
int func2(int a, int b)
{
    printf("func2: X-Y");
    return a - b;
}
int func3(int a, int b)
{
    printf("func3: X*Y");
    return a * b;
}
int func4(int a, int b)
{
    printf("func4: X^Y");
    return (int)pow(a, b);
}
int func5(int a, int b)
{
    printf("func5: X^2 + Y^2");
    return (int)pow(a, 2) + (int)pow(b, 2);
}
int func6(int a, int b)
{
    printf("func6: X^2 - Y^2");
    return (int)pow(a, 2) - (int)pow(b, 2);
}