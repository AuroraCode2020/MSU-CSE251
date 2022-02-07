#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/*
∗ CSE 251 step3 rlc2.c
∗ By: AuroraCode2020
*/

int main()
{
    double L,C,W,F;
    bool valid = true;
    printf("Input Capacitance (microfarads): ");
    scanf("%lf",&C);
    C = C*pow(10,-6);
    printf("Input Inductance (millihenrys): ");
    scanf("%lf",&L);
    if(L < 0)
    {
        printf("You moron, you entered a negative inductance!\n");
        valid = false;
    }
    else if(L == 0)
    {
        printf("You are really dumb, you entered zero.\n");
        valid = false;
    }
    else
        printf("Okay, I guess that's reasonable\n");
    if(valid)
    {
    	L = L*pow(10,-3);
    	W = 1.0/sqrt(L*C);
    	F = W/(2*M_PI);
    	printf("%.3f",F);
    	if(F>=20 && F<=20000)
    	{
    		printf("This frequency is one I can hear!");
    	}
    }
}
