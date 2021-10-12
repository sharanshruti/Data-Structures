#include<stdio.h>

int p, q;

int main()
{
    int n, i, j;
    printf("Enter the value of n= "); //enter no. of rows for identity matrix
    scanf("%d", &n);

    int a[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
            a[i][j] = 1;
            else
            a[i][j] = 0;
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }



    char x[100];
    getchar();
    printf("Enter x = "); //add the value of the string
    gets(x);
    i=0, j=0;
    while(x[i])
    {
        if(x[i] == '1')
        p++;
        i++;
    }
    int b[n-p][n], c[n];

    for(i=0;i<n;i++)
    {
        c[i] = a[0][i];
    }

    for(i=0; i<n-p && j<n; j++)
    {
        if(x[j] == '0' || x[j] == '\0')
        {
            for(int k=0;k<n;k++)
            {
                b[i][k] = c[k];
                c[k] = a[j+1][k];
            }
            i++;
        }
        else
        {
            for(int k=0;k<n;k++)
            {
                c[k] += a[j+1][k];
            }
        }
    }




    for(i=0; i<n-p; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d  ",b[i][j]);
        }
        printf("\n");
    }

    char y[100];
    printf("Enter y = ");
    gets(y);
    i=0, j=0;
    while(y[i])
    {
        if(y[i] == '1')
        q++;
        i++;
    }
    int d[n-p][n-q];

    for(i=0;i<n-p;i++)
    {
        c[i] = b[i][0];
    }

    for(i=0; i<n-q && j<n; j++)
    {
        if(y[j] == '0' || y[j] == '\0')
        {
            for(int k=0;k<n-p;k++)
            {
                d[k][i] = c[k];
                c[k] = b[k][j+1];
            }
            i++;
        }
        else
        {
            for(int k=0;k<n-p;k++)
            {
                c[k] += b[k][j+1];
            }
        }
    }

    for(i=0; i<n-p; i++)
    {
        for(j=0; j<n-q; j++)
        {
            printf("%d  ",d[i][j]);
        }
        printf("\n");
    }


    return 0;

}