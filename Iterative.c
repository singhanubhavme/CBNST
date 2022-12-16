#include <stdio.h>
#include <math.h>

float polyFunc(float x)
{
    // return 2 * x - (log(x) / log(10)) - 7;
    return (cos(x) - 3 * x + 1);
}

float xForm(float x)
{
    return (1 + cos(x)) / 2;
}
int steps = 0;
void calIterative(float x, float allowErr)
{

    calIterative(x, allowErr);
}

int main()
{

    float x, allowErr;
    int itr;
    printf("Enter the guessed value - ");
    scanf("%f", &x);

    printf("Enter Number of Iterations : ");
    scanf("%d", &itr);
    printf("Enter the allowed Error : ");
    scanf("%f", &allowErr);

    while (itr--)
    {
        x = xForm(x);
        steps++;
        printf("%d  iteration and the value of x is - %f\n", steps, x);
    }

    return 0;
}