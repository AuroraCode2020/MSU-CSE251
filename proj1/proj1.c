/*
∗ CSE 251 Project 1
∗ By: AuroraCode2020
∗
∗ Complete the following table:
∗
∗ a b n estimate
∗ −1 1 1883 1.178979838
∗ 0 10 2028 0.489888070
∗ −1000 1000 18861 0.999796418
∗ 10 15 1515 0.016860599
∗ 0.1 0.2 138 0.096211811
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double function(double x);

int main()
{	
	double a,b;
	double sum1=0,sum2=0;
	double delta;
	double x;
	printf("Enter a value for a:");
	scanf("%lf",&a);
	printf("Enter a value for b:");
	scanf("%lf",&b);
	printf("Integral evaluation\n");
	for(int n=10;n<100000;n++)
	{	
		if(fabs(sum2-sum1)<1e-10 && sum1!=0)
		{
			break;
		}
		sum1 = sum2;
		sum2 = 0;
		delta = (b-a)/(double)n;
		for(int i=1;i<=n;i++)
		{	
			x = a + (i-0.5) * delta;
			sum2 += function(x)*delta;
		}
		if(sum1==0)
		{
			printf("%d %.9f\n",n,sum2);
		}
		else
		{
			printf("%d %.9f %e\n",n,sum2,fabs(sum2-sum1));
		}
	}
	printf("The integral result is %.9f\n",sum2);
}

double function(double x)
{
	double result;
	if(x==0)
	{
		result = 1;
	}
	else
	{
		result = sin(M_PI*x)/(M_PI*x);
	}
	return result;
}
