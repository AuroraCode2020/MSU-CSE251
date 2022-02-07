#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
∗ CSE 251 step4 factorial.c
∗ By: AuroraCode2020
*/

int main()
{
	printf("Number to compute the factorial of: ");
    int f;      /* Number we compute the factorial of */
    scanf("%d",&f);
    if(f<0){
    	printf("Please enter a number >= 0!");
    	exit(1);
    }
    else{
    	int fac = 1;    /* Initial value of factorial */
    	while(f > 0)
    	{
        	fac = fac * f;
        	f--;
    	}
    	printf("Factorial = %d\n", fac);
    }
}
