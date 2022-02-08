#include "file.h"

/*
∗ project3
∗ By: AuroraCode2020
*/

int main()
{
    DisplayMenu();
    return 0;
}

void DisplayMenu()
{
    char command[10];
    int n;

    struct event *ec;
    int eventNum = 0;
    
    do
    {
        printf("1 - Insert a new event\n");
        printf("2 - Display all events\n");
        printf("3 - Now?\n");
        printf("4 - Delete expired\n");
        printf("0 - Exit\n");

        printf("Please select an option: ");
        InputString(command,  sizeof(command));

        do
        {
            if(strcmp(command, "1") && strcmp(command, "2") && strcmp(command, "3") && strcmp(command, "4") && strcmp(command, "0"))
            {
                printf("Please enter a right number!\n");
                printf("Please select an option: ");
                InputString(command, sizeof(command));
            }
            else
            {
                break;
            }
        } while (true);

        n = command[0] - 48;

        switch(n)
        {
            case 1:
            {
                if(eventNum == 0)
                {
                    ec = malloc(sizeof(struct event));
                    eventNum ++;
                    ec[0] = AddEvent(ec, eventNum);
                    continue;
                }
                else
                {
                    ec = realloc(ec, sizeof(struct event) * (eventNum + 1));
                    eventNum ++;
                    ec[eventNum-1] = AddEvent(ec, eventNum);
                    continue;
                }
            }
            case 2:
            {
                SortEvent(ec, eventNum);
                DisplayAllEvent(ec, eventNum);
                break;
            }
            case 3:
            {
                DisplayNowEvent(ec, eventNum);
                break;
            }
            case 4:
            {
                DeleteEvent(ec, eventNum);
                break;
            }
            case 0:
            {
                printf("The program is exiting.\n");
                return;
            }
        }
    } while(true);
}