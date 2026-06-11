//MATRIX CALCULATOR

#include <stdio.h>
#include <stdlib.h>

void add();
void sub();
void mul();
void scale();
void transpose();
void identity();
void sym();
void diag();
void det();

void main() 
{ 
    int choice;
    char ch;
    printf("---MATRIX CALCULATOR---\n");
    Loop:
    printf("\n1. Addition \n2. Subtraction \n3. Multiplication \n4. Scaling \n5. Transpose \n6. Check Identity Matrix \n7. Check Symmetric Matrix \n8. Trace \n9. Determinant \n10. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            sub();
            break;
        case 3:
            mul();
            break;
        case 4:
            scale();
            break;
        case 5:
            transpose();
            break;
        case 6:
            identity();
            break;
        case 7:
            sym();
            break;
        case 8:
            diag();
            break;
        case 9:
            det();
            break;
        case 10:
            goto End;
        default:
            printf("Incorrect input");
    }
    goto Loop;
    End:
        printf("--- Program end ---");
}
void add()
{
    int **a, **b, **c, r, col, i, j; 
   printf("Enter the rows and columns: "); 
   scanf("%d%d", &r, &col); 
   a = (int **)malloc(r*sizeof(int *)); 
   b = (int **)malloc(r*sizeof(int *)); 
   for(i=0;i<r;i++) 
   { 
       a[i] = (int *)malloc(col*sizeof(int)); 
       b[i] = (int *)malloc(col*sizeof(int)); 
   } 
   printf("Enter matrix A: \n"); 
   for(i=0;i<r;i++) 
   { 
       for(j=0;j<col;j++) 
           scanf("%d",&a[i][j]); 
   } 
   printf("Enter matrix B: \n"); 
   for(i=0;i<r;i++) 
   { 
       for(j=0;j<col;j++) 
           scanf("%d",&b[i][j]); 
   } 
    c = (int **)malloc(r*sizeof(int *)); 
   for(i=0;i<r;i++) 
       c[i] = (int *)malloc(col*sizeof(int)); 
   for(i=0;i<r;i++) 
   { 
       for(j=0;j<col;j++) 
           c[i][j] = a[i][j] + b[i][j]; 
   } 
   printf("Matrix C:\n"); 
   for(i=0;i<r;i++) 
   { 
       for(j=0;j<col;j++) 
           printf("%d ",c[i][j]); 
        printf("\n"); 
   }
}
void sub()
{
    int **a, **b, **c, r, col, i, j; 
   printf("Enter the rows and columns: "); 
   scanf("%d%d", &r, &col); 
   a = (int **)malloc(r*sizeof(int *)); 
   b = (int **)malloc(r*sizeof(int *)); 
   for(i=0;i<r;i++) 
   { 
       a[i] = (int *)malloc(col*sizeof(int)); 
       b[i] = (int *)malloc(col*sizeof(int)); 
   } 
   printf("Enter matrix A: \n"); 
   for(i=0;i<r;i++) 
   { 
       for(j=0;j<col;j++) 
           scanf("%d",&a[i][j]); 
   } 
   printf("Enter matrix B: \n"); 
   for(i=0;i<r;i++) 
   { 
       for(j=0;j<col;j++) 
           scanf("%d",&b[i][j]); 
   } 
     c = (int **)malloc(r*sizeof(int *)); 
   for(i=0;i<r;i++) 
       c[i] = (int *)malloc(col*sizeof(int)); 
   for(i=0;i<r;i++) 
   { 
       for(j=0;j<col;j++) 
           c[i][j] = a[i][j] - b[i][j]; 
   } 
   printf("Matrix C:\n"); 
   for(i=0;i<r;i++) 
   { 
       for(j=0;j<col;j++) 
           printf("%d ",c[i][j]); 
        printf("\n"); 
   }
}
void mul()
{
    int **a, **b, **c, r1,r2,c1,c2, i, j,k; 
    printf("Enter the rows and columns of matrix A: ");
	scanf("%d%d",&r1,&c1);
	printf("Enter the rows and columns of matrix B: ");
	scanf("%d%d",&r2,&c2);
    if (c1!=r2)
		printf("Matrix multiplication not possible\n");
	else
	{
    a = (int **)malloc(r1*sizeof(int *)); 
    b = (int **)malloc(r2*sizeof(int *)); 
    for(i=0;i<r1;i++) 
        a[i] = (int *)malloc(c1*sizeof(int)); 
    for(i=0;i<r2;i++)
        b[i] = (int *)malloc(c2*sizeof(int)); 
    printf("Enter matrix A: \n"); 
    for(i=0;i<r1;i++) 
    { 
        for(j=0;j<c1;j++) 
            scanf("%d",&a[i][j]); 
    } 
    printf("Enter matrix B: \n"); 
    for(i=0;i<r2;i++) 
    { 
        for(j=0;j<c2;j++) 
            scanf("%d",&b[i][j]); 
    } 
        c = (int **)malloc(r1*sizeof(int *)); 
    for(i=0;i<r1;i++) 
        c[i] = (int *)malloc(c2*sizeof(int));
    for (i=0;i<r1;i++)
        {
                for (j=0;j<c2;j++)
                {
                    c[i][j]=0;
                    for (k=0;k<r2;k++)
                        c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
                }
        }
        printf("Matrix C: \n");
        for (i=0;i<r1;i++)
        {
                for (j=0;j<c2;j++)
                    printf("%d ",c[i][j]);
                printf("\n");
        }
	}

    
}
void scale()
{
    int **a, r, c, i, j,n; 
   printf("Enter rows and columns: "); 
   scanf("%d%d", &r, &c); 
   a = (int **)malloc(r * sizeof(int *)); 
   for(i=0;i<r;i++) 
       a[i] = (int *)malloc(c * sizeof(int)); 
   printf("Enter matrix: "); 
   for(i=0;i<r;i++) 
   {
    for(j=0;j<c;j++) 
           scanf("%d", &a[i][j]); 
   }
    printf("Enter number to be scaled: ");
    scanf("%d",&n);
    for(i=0;i<r;i++) 
   {
    for(j=0;j<c;j++) 
           a[i][j]=a[i][j]*n; 
   } 
   printf("Scaled matrix: \n");
   for(i=0;i<r;i++) 
   {
    for(j=0;j<c;j++) 
           printf("%d ", a[i][j]); 
    printf("\n");
   }
}
void transpose()
{
    int **a,**b,r, c, i, j; 
   printf("Enter rows and columns: "); 
   scanf("%d%d", &r, &c); 
   a = (int **)malloc(r * sizeof(int *));
   b = (int **)malloc(c * sizeof(int *)); 
   for(i=0;i<r;i++)
   {
    a[i] = (int *)malloc(c * sizeof(int)); 
    b[i] = (int *)malloc(r * sizeof(int)); 
   } 
   printf("Enter matrix: "); 
   for(i=0;i<r;i++) 
   {
    for(j=0;j<c;j++) 
           scanf("%d", &a[i][j]); 
   }
   for (i=0;i<r;i++)
	{
			for (j=0;j<c;j++)
				b[j][i]=a[i][j];
		}
		printf("Transpose matrix: \n");
		for (i=0;i<c;i++)
		{
			for (j=0;j<r;j++)
				printf("%d ",b[i][j]);
			printf("\n");
	}

}
void identity()
{
    int **a, r, c, i, j,flag=1; 
   printf("Enter rows and columns: "); 
   scanf("%d%d", &r, &c); 
   a = (int **)malloc(r * sizeof(int *)); 
   for(i=0;i<r;i++) 
       a[i] = (int *)malloc(c * sizeof(int)); 
   printf("Enter matrix: "); 
   for(i=0;i<r;i++) 
   {
        for(j=0;j<c;j++) 
           scanf("%d", &a[i][j]); 
   }
    if (r!=c)
		flag=0;
	else
	{
		for (i=0;i<r;i++)
		{
			for (j=0;j<c;j++)
			{
				if ((i==j && a[i][j]!=1)||(i!=j && a[i][j]!=0))
				flag=0;
				break;
			}
		}
    }
	if (flag==1)
		printf("Identity matrix\n");
	else
		printf("Not an identity matrix\n");
	

}
void sym()
{
   int **a, **b, **c, r1,c1, i, j,flag=1; 
    printf("Enter the rows and columns of matrix A: ");
	scanf("%d%d",&r1,&c1);
    a = (int **)malloc(r1*sizeof(int *)); 
    for(i=0;i<r1;i++) 
            a[i] = (int *)malloc(c1*sizeof(int)); 
    for(i=0;i<r1;i++)
        printf("Enter matrix A: \n"); 
    for(i=0;i<r1;i++) 
    { 
        for(j=0;j<c1;j++) 
            scanf("%d",&a[i][j]);
    }
    if (r1!=c1)
		flag=0;
	else
	{
        for (i=0;i<r1;i++)
		{
			for (j=0;j<c1;j++)
			{
				if ( a[i][j]!=a[j][i])
				flag=0;
				break;
			}
		}
    }
    if (flag==1)
		printf("Symmetric matrix\n");
	else
		printf("Not a symmetric matrix\n");
}

void diag()
{
   int **a, r, c, i, j,lsum=0, rsum=0; 
   printf("Enter rows and columns: "); 
   scanf("%d%d", &r, &c); 
   a = (int **)malloc(r * sizeof(int *)); 
   for(i=0;i<r;i++) 
       a[i] = (int *)malloc(c * sizeof(int)); 
   printf("Enter matrix: "); 
   for(i=0;i<r;i++) 
       for(j=0;j<c;j++) 
           scanf("%d", &a[i][j]); 
   printf("Trace:\n"); 
   if(r == c) 
   { 
       for(i=0;i<r;i++) 
       { 
           lsum += a[i][i]; 
           rsum += a[i][r-i-1]; 
       } 
   
    printf("Left Diagonal: %d\n", lsum); 
    printf("Right Diagonal: %d\n", rsum); 
   }
   else
    printf("Trace could not be calculated!\n");
}

void det()
{
    int **a, det, r, i, j; 
   printf("Enter dimension(2,3): "); 
   scanf("%d", &r); 
   a = (int **)malloc(r * sizeof(int *)); 
   for(i=0;i<r;i++) 
       a[i] = (int *)malloc(r * sizeof(int)); 
   printf("Enter matrix:"); 
   for(i=0;i<r;i++) 
  {
    for(j=0;j<r;j++) 
           scanf("%d", &a[i][j]); 
  }
  if (r==2)
  {
    det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
  }    
  else if (r==3)
  {
    det =a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
    - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
    + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
  }
  printf("Determinant = %d",det);
}

