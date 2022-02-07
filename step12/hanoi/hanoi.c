#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "hanoi.h"
#include "autosolve.h"

/*
 * Name :  AuroraCode2020
 *
 * Simple Towers of Hanoi game. You can solve it yourself or
 * ask the game to solve it for you.
 */


/*
 * The program main entry point
 */
int main()
{
    int tower[NumPins][NumDisks];
    int fm, to;

    /* Reset the tower to all disks on the first pin */
    Reset(tower);
    printf("\n");

    do
    {
        /* Display the tower before the move */
        DisplayTower(tower);

        /* Get a move from the user */
        fm = InputPin("Pin to move from: ", 0, 3);
        if(fm == 0)
        {
            Autosolve(tower);
            break;
        }

        to = InputPin("Pin to move to: ", 1, 3);

        /* Perform the move the user asked */
        MoveDisk(tower, fm, to);

    } while(!CheckDone(tower));

    return 0;
}
