#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
∗ CSE 251 step 4 sine.c
∗ By: AuroraCode2020
*/

int main()
{
    double angle;
    int numSteps;
    double maxAngle = M_PI * 2;
    int i,j;
    double sinVal,numSpaces;
    double daoshu;
    printf("Input the number of steps: ");
    
    do{
    	scanf("%d",&numSteps);
    }
    while(numSteps<2);

    for(i = 0;  i<=numSteps;  i++)
    {
        angle = (double)i / (double)numSteps * maxAngle;
        sinVal = sin(angle);
        printf("%3d: %5.2f", i, angle);
        numSpaces = 30 + sinVal*30;
        for(j=0;j<numSpaces;j++){
        	printf(" ");
        }
        daoshu = cos(angle);
        if(daoshu>=0){
        	if(fabs(daoshu)<0.1){
        		printf("*\n");
        	}
        	else{
        		printf("\\\n");
        	}
        }
        else if(daoshu<0){
        	if(fabs(daoshu)<0.1){
        		printf("*\n");
        	}
        	else{
        		printf("/\n");
        	}
        }
    }
}
