// correct
#include <stdio.h>
#include <math.h>

float polyFunc(float x)
{
    return cos(x) - x * exp(x);
}

int steps = 0;
void calFalsePosition(float a, float b, float errAllow)
{

    float x = a - (((b - a) / (polyFunc(b) - polyFunc(a))) * polyFunc(a));

    printf("The Roots are %f  , %f  and the  values of x is %f  , %f\n", a, b, x, polyFunc(x));
    steps++;
    if (fabs(polyFunc(x)) <= errAllow)
    {
        printf("The root of given Equation is -  %f \n", x);
        printf("Steps are - %d", steps);
        return;
    }

    if (polyFunc(a) * polyFunc(x) < 0)
        calFalsePosition(a, x, errAllow);
    else if (polyFunc(x) * polyFunc(b) < 0)
        calFalsePosition(x, b, errAllow);
}

int main()
{

    float a, b, errAllow;

    printf("Enter the first root = ");
    scanf("%f", &a);

    printf("Enter the second root = ");
    scanf("%f", &b);
    if (polyFunc(a) * polyFunc(b) < 0)
    {
        printf("Enter the Allowed Error - ");
        scanf("%f", &errAllow);
        calFalsePosition(a, b, errAllow);
    }
    else
        printf("Invalid roots !!!");
    return 0;
}