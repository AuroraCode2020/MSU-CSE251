#include <stdio.h>
#include <math.h>

/*
∗ CSE 251 step2 rlc.c
∗ By: AuroraCode2020
*/

int main()
{
    double L,C,W,F;
    printf("Input Capacitance (microfarads): ");
    scanf("%lf",&C);
    C = C*pow(10,-6);
    printf("Input Inductance (millihenrys): ");
    scanf("%lf",&L);
    L = L*pow(10,-3);
    W = 1.0/sqrt(L*C);
    F = W/(2*M_PI);
    printf("%.3f",F);
}
