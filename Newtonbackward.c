// working
#include <stdio.h>
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

    printf("\n\nx \t\t  y \t  d1 \t  d2 \t  d3 \t  d4\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i; j++)
            printf("%0.2f\t", arr[i][j]);
        printf("\n");
    }

    u = (x - arr[n - 1][0]) / (arr[1][0] - arr[0][0]);
    y = arr[n - 1][1];
    newU = u;

    int j = 2;

    for (int i = n - 2; i >= 0; i--)
    {
        y = y + (newU * arr[i][j]) / fact;
        fact = fact * j;
        newU = newU * (u + (j - 1));
        j++;
    }

    printf("\n\nThe value of x and y is = %f and %f", x, y);
    return 0;
}