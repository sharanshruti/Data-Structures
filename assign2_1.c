#include<stdio.h>
//Operations on Matrix

void row_average(int a[50][50], int n)
{
    int min, max, count = 0;
    float avg[50];
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp += a[i][j];
        }
        avg[i] = (float)temp / n;
        temp = 0;
    }

    min = avg[0];
    max = avg[0];

    for (int i = 0; i < n; i++)
    {
        if (avg[i] <= min)
        {
            min = avg[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (min == avg[i])
        {
            printf("row with min avg %d\n", i + 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (avg[i] >= max)
        {
            max = avg[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (max == avg[i])
        {
            printf("row with max avg %d\n", i + 1);
        }
    }
}

void coloumn_average(int a[50][50], int n)
{
    float min, max;
    float avg[50];
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp += a[j][i];
        }
        avg[i] = (float)temp / n;
        temp = 0;
    }

    min = avg[0];
    max = avg[0];

    for (int i = 0; i < n; i++)
    {
        if (avg[i] < min)
        {
            min = avg[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (min == avg[i])
        {
            printf("coloumn with min avg %d\n", i + 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (avg[i] > max)
        {
            max = avg[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (max == avg[i])
        {
            printf("coloumn with max avg %d\n", i + 1);
        }
    }
}

void swap(int a[50][50], int n)
{
    int min = a[0][0];
    int max = a[0][0];
    int i1 = 0, j1 = 0, i2 = 0, j2 = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < min)
            {
                min = a[i][j];
                i1 = i;
                j1 = j;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                i2 = i;
                j2 = j;
            }
        }
    }

    int temp = a[i1][j1];
    a[i1][j1] = a[i2][j2];
    a[i2][j2] = temp;

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void row_colmn_swap(int a[50][50], int n)
{
    int x, y;
    printf("enter the value of 1st row and coloumn to be swapped\n");
    scanf("%d", &x);
    printf("enter the value of 2nd row and coloumn to be swapped\n");
    scanf("%d", &y);

    int temp[50];

    for (int i = x - 1; i <= x - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[j] = a[i][j];
            a[i][j] = a[y - 1][j];
        }
    }

    for (int i = y - 1; i <= y - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = temp[j];
        }
    }

    printf("after row operation\n");
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    int temp1[50];

    for (int i = x - 1; i <= x - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp1[j] = a[j][i];
            a[j][i] = a[j][y - 1];
        }
    }
    for (int i = y - 1; i <= y - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[j][i] = temp1[j];
        }
    }

    printf("after coloumn operation\n");
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%p", &a[i][j]);
        }
        printf("\n");
    }
}

void address(int a[50][50], int n)
{
    printf("%p\n", &a[0][0]);
}

void checkmajor(int a[50][50], int n)
{
    if (&a[0][0] - &a[0][1] == 4)
    {
        printf("it is row major\n");
    }
    else
    {
        printf("it is coloumn major\n");
    }
}

void row_colmn_major(int a[50][50], int n)
{
    int r[200], q[200], k = 0, l = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            r[k] = a[i][j];
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            q[l] = a[j][i];
            l++;
        }
    }

    printf("in row major\n");
    for (int i = 0; i < n * n; i++)
    {
        printf("%d", r[i]);
    }

    printf("\n");
    printf("in coloumn major\n");
    for (int i = 0; i < n * n; i++)
    {
        printf("%d", q[i]);
    }
    printf("\n");
}

void daig(int a[50][50], int n)
{
    int r[200], i, j, k = 0, p = 0, q = 0, c = 0, t = 0;

    while (p < n && q < n)
    {
        i = p, j = q;

        while (i < n && j < n)
        {
            r[k] = a[i][j];
            i++;
            j++;
            k++;
        }
        if (c % 2 == 0)
        {
            p++;
        }
        t = p;
        p = q;
        q = t;
        c++;
    }

    printf("In diagonal major\n");
    for (int i = 0; i < n*n; i++)
    {
        printf("%d ", r[i]);
    }
    printf("\n");
    
}

int main()
{
    int n;
    int a[50][50];

    printf("enter the value of n\n");
    scanf("%d", &n);

    printf("enter the value for matrix\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n");
    printf("matrix is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    row_average(a, n);
    coloumn_average(a, n);
    swap(a, n);
    //row_colmn_swap(a, n);
    address(a, n);
    checkmajor(a, n);
    row_colmn_major(a, n);
    daig(a, n);

    return 0;
}
