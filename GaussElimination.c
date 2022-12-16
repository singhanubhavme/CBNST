// correct
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the order of the matrix = ");
    scanf("%d", &n);
    float arr[n][n + 1];
    printf("Enter the argumented matrix\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            scanf("%f", &arr[i][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (j < i)
            {
                float ratio = arr[i][j] / arr[j][j];

                for (int k = 0; k < n + 1; k++)
                {
                    arr[i][k] = arr[i][k] - ratio * (arr[j][k]);
                }
            }
        }
    }

    printf("After Converting to upper triangular matrix \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            printf("%0.4f  ", arr[i][j]);
        printf("\n");
    }

    float x[n];
    x[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        float sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += arr[i][j] * x[j];
        }
        x[i] = (arr[i][n] - sum) / arr[i][i];
    }

    for (int i = 0; i < n; i++)
        printf("The value of x%d =  %f\n", i, x[i]);

    return 0;
}