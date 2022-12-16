// working
#include <stdio.h>
#include <math.h>

int main()
{

    int n, fact = 1;
    float x, u, y, newU;

    printf("Enter the value of n = ");
    scanf("%d", &n);
    float arr[n][n + 1];

    printf("Enter the value's of X = ");
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i][0]);

    printf("Enter the value's of Y = ");
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i][1]);

    printf("Enter the value of x which you want find y = ");
    scanf("%f", &x);

    for (int j = 2; j < n + 1; j++)
        for (int i = 0; i <= n - j; i++)
            arr[i][j] = arr[i + 1][j - 1] - arr[i][j - 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i; j++)
            printf("%0.2f ", arr[i][j]);
        printf("\n");
    }

    u = (x - arr[0][0]) / (arr[1][0] - arr[0][0]);

    newU = u;
    y = arr[0][1];

    for (int i = 2; i < n + 1; i++)
    {
        y = y + (newU * arr[0][i]) / fact;
        fact = fact * i;
        newU = newU * (u - (i - 1));
    }

    printf("The value of x and y is = %0.2f and %0.2f", x, y);
    return 0;
}