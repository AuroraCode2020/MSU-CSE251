#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "transistors.h"

/*
 * Name :  AuroraCode2020
 * Description : Simple transistor description example program
*/

int main()
{
    int i;
    Tran *trans;
    int numTrans;
    char command[10];
    
    printf("transistors!\n");

    /* Allocate space for one transistor */
    printf("Please enter a transistor: ");
    trans = malloc(sizeof(Tran));
    numTrans = 1;
    
    /* Input the first transistor */
    trans[0] = InputTransistor();
    
    do
    {
    	printf("Would you like to enter another transistor (Y/N)?");
		InputString(command, sizeof(command));
		printf("%s\n",command);
		if(strcmp(command, "Y") == 0 || strcmp(command, "y") == 0)
		{
			/* Increase the space by one transistor */
			trans = realloc(trans, sizeof(Tran) * (numTrans + 1));
			numTrans++;
			printf("Please enter a transistor: ");
			trans[numTrans-1] = InputTransistor();
		}
		else
		{
			/* Output the transistors */
			printf("\nThe transistors:\n");
			for(i=0;  i<numTrans;  i++)
			{
				DisplayTransistor(trans[i]);
			}
			break;
		}
    } while(true);
    
    /* Free the memory */
    free(trans);
}
