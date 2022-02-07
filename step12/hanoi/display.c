#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "hanoi.h"

/*
∗ CSE 251 step12 hanoi display.c
∗ By: AuroraCode2020
*/

/*
 * Display a disk of width p
 */
void DisplayDisk(int p)
{
    int i;
    int spaceAround = (MaxDiskSize - p) / 2;

    for(i=0; i<spaceAround;  i++)
        printf(" ");

    if(p == 0)
    {
        printf("|");
    }
    else
    {
        for(i=0;  i<p;  i++)
            printf("O");
    }

    for(i=0;  i<spaceAround;  i++)
        printf(" ");
}

/*
 * Reset the tower to its initial state
 */
void Reset(int tower[NumPins][NumDisks])
{
    int i, j;

    for(j=0;  j<NumDisks;  j++)
    {
        tower[0][j] = 13 - j * 2;
    }

    for(i=1; i<NumPins;  i++)
    {
        for(j=0;  j<NumDisks;  j++)
        {
            tower[i][j] = 0;
        }
    }

}


/*
 * Move a disk from one pin to another
 */
void MoveDisk(int tower[NumPins][NumDisks], int fm, int to)
{
    int f;
    int t;
    int moving;

    /* Where is the pin to move? */
    for(f=NumDisks-1; f>=0;  f--)
    {
        if(tower[fm-1][f] > 0)
            break;
    }

    if(f < 0)
    {
        printf("No disks on that pin\n");
        return;
    }

    /* Size we are moving */
    moving = tower[fm-1][f];

    /* Where is an empty space to move to? */
    for(t=NumDisks-1; t>=0;  t--)
    {
        if(tower[to-1][t] > 0)
            break;
    }

    /* Test to move legality */
    if(t >= 0 && tower[to-1][t] < moving)
    {
        printf("\n!!! Illegal move !!!\n");
        return;
    }

    /* And move it */
    t++;
    tower[to-1][t] = moving;
    tower[fm-1][f] = 0;
}


/*
 * Get a pin from the user
 */
int InputPin(char *msg, int fm, int to)
{
    int val;

    /* Allow values in the range [fm, to] */
    do
    {
        printf("%s", msg);
        scanf("%d", &val);
        if(val < fm || val > to)
            val = fm-1;

    } while(val < fm);

    return val;
}

/*
 * Check to see if all disks moved to last pin
 */
bool CheckDone(int tower[NumPins][NumDisks])
{
    return tower[0][0] == 0 && tower[1][0] == 0;
}

/*
 * Display the Towers of Hanoi
 */
void DisplayTower(int tower[NumPins][NumDisks])
{
    int i;

    printf("\n ");

    DisplayDisk(0);
    printf("  ");
    DisplayDisk(0);
    printf("  ");
    DisplayDisk(0);
    printf("\n");

    for(i=0;  i<NumDisks;  i++)
    {
        printf(" ");

        /* We display from the top down */
        DisplayDisk( tower[0][5 - i] );
        printf("  ");
        DisplayDisk( tower[1][5 - i] );
        printf("  ");
        DisplayDisk( tower[2][5 - i] );
        printf("\n");
    }

    for(i=0;  i<NumPins * MaxDiskSize + (NumPins - 1) * 2 + 2; i++)
        printf("=");

    printf("\n");
}
