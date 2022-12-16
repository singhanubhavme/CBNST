// works
#include <stdio.h>
#include <math.h>

float func(float x)
{
    return x*x*x - 2*x - 5;
}

int iterations = 0;
void secant(float a, float b, float errAllow)
{

    float x = b - (((b - a) / (func(b) - func(a))) * func(b));

    printf("The Roots are %f  , %f  and the  values of x is %f  , %f\n", a, b, x, func(x));
    iterations++;
    if (fabs(func(x)) <= errAllow)
    {
        printf("The root of given Equation is -  %f \n", x);
        printf("iterations are - %d", iterations);
        return;
    }
    secant(x, a, errAllow);
}

int main()
{

    float x1, x2, a, b, allowErr;

    printf("Enter lower and higher guess = ");
    scanf("%f%f", &x1, &x2);

    printf("Enter the Allow error - ");
    scanf("%f", &allowErr);
    printf("Enter any value of a and b in between the range = ");
    scanf("%f%f", &a, &b);
    secant(a, b, allowErr);
}