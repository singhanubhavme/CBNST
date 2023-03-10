// correct
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define EPSILON 0.001

int n;
int flag;

void print(int iteration, float values[n])
{
    printf("Iteration %d ", iteration);
    for (int i = 0; i < n; i++)
        printf("value[%d]=%f ", i + 1, values[i]);
    printf("\n");
}

void findValues(float a[][n + 1], int maxIterations, float values_old[n])
{
    int i, j, k, iteration;
    float sum = 0;
    float values_new[n];
    for (iteration = 1; iteration <= maxIterations; iteration++)
    {
        for (i = 0; i < n; i++)
        {
            sum = 0;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                    sum += a[i][j] * values_old[j];
            }
            values_new[i] = (a[i][n] - sum) / a[i][i];
        }
        for (k = 0; k < n; k++)
        {
            if (fabs(values_old[k] - values_new[k]) < EPSILON)
                continue;
            else
                flag = 1;
                break;
        }
        if (flag == 0)
        {
            print(iteration, values_new);
            return;
        }
        flag = 0;
        print(iteration, values_new);
        for (k = 0; k < n; k++)
            values_old[k] = values_new[k];

    }
    print(iteration, values_new);

}

int main()
{
    int i, j, k, x, y, maxIterations;
    float ratio;
    printf("Enter no of Unknowns\n");
    scanf("%d", &n);
    printf("Enter no. of iterations\n");
    scanf("%d", &maxIterations);
    float a[n][n + 1];
    float values[n];

    printf("Enter the Augmented Matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            scanf("%f", &a[i][j]);
    }

    for (int i = 0; i < n; i++)
        values[i] = 0;
    findValues(a, maxIterations, values);
    return 0;
}
