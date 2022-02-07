#include <stdio.h>
#include <stdbool.h>

/* 
 * Name : AuroraCode2020
 * Program to experiment with arrays
 */
 
#define NumMovies 10
#define MaxGrosses 5
 
int main()
{
    double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622,3156594, 1629735, 2659234, 2028036, 510768};
    double sum;
    char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech", "Just Go With It", "Gnomeo and Juliet", "Drive Angry", "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son", "True Grit"};
    
    sum = 0;        /* Initialize to zero */
    int i,j;
    for(i = 0;  i<NumMovies;  i++)
    {
    	printf("Movie %2d %33s: %.0f\n", i+1, names[i], gross[i]);
        sum += gross[i];
    }
    printf("Total gross for these films was $%.0f\n", sum);
    
    int highestGrossIndex = 0;
    double highestGross = 0;
    double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 10000000};
    bool value = true;
    for(i=0;  i<NumMovies;  i++)
    {
        if(gross[i] > highestGross)
        {
            highestGrossIndex = i;
            highestGross = gross[highestGrossIndex];
        }
    }
    for(i=0; i<5; i++)
    {
    	value = true;
    	for(j=0;j<10;j++)
    	{
    		if(gross[j]<maxGross[i])
    		{
    			value = false;
    			printf("The highest gross less than %.0f is %s at %.0f\n",maxGross[i],names[j],gross[j]);
    		}
    	}
    	if(value)
    	{
    		printf("No film made less than %.0f\n",maxGross[i]);
    	}
    }
    printf("The highest grossing film is: %s\n", names[highestGrossIndex]);
}
