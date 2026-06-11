//CALCULATOR

# include <stdio.h>
# include <math.h>
void main()
{
	int p,q,r,choice;
	double a,b,c;
	printf("---CALCULATOR---\n");
	Loop:
	    printf("\n1. Add \n2. Subtract \n3. Multiply \n4. Divide \n5. Quotient \n6. Remainder \n7. Power \n8. Exit \nEnter your choice: ");
	    scanf("%d",&choice);
	    switch (choice)
	    {
		case 1:
            printf("Enter 2 numbers: ");
            scanf("%lf%lf",&a,&b);
			c=a+b;
			printf("%g + %g = %g",a,b,c);
			break;
		case 2:
            printf("Enter 2 numbers: ");
	        scanf("%lf%lf",&a,&b);
			c=a-b;
			printf("%g - %g = %g",a,b,c);
			break;
		case 3:
            printf("Enter 2 numbers: ");
	        scanf("%lf%lf",&a,&b);
			c=a*b;
			printf("%g * %g = %g",a,b,c);
			break;
		case 4:
            printf("Enter 2 numbers: ");
	        scanf("%lf%lf",&a,&b);
			c=a/b;
			printf("%g / %g = %g",a,b,c);
			break;
		case 5:
			printf("Enter 2 numbers: ");
	        scanf("%d%d",&p,&q);
			r=p/q;
			printf("Quotient = %d",r);
			break;
		case 6: 
			printf("Enter 2 numbers: ");
	        scanf("%d%d",&p,&q);
			r=p%q;
			printf("Remainder = %d",r);
			break;
		case 7:
            printf("Enter base and exponent: ");
	        scanf("%lf%lf",&a,&b);
			c=pow(a,b);
			printf("Power = %g",c);
			break;
		case 8:
			goto end;
			break;
		default:
			printf("Invalid input");
			break;
	}
	printf("\n");
	      goto Loop;
	end:
	     printf("Thank You!");
}
