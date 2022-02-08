#include "file.h"

/*
∗ project3
∗ By: AuroraCode2020
*/

struct event AddEvent(struct event *ec, int eventNum)
{
    struct event e;

    printf("What is the event: \n");
    InputString(e.WhatToDo, sizeof(e.WhatToDo));
    e.date = InputDate("Event date: ");
    e.start = InputTime("Start time: ", e.date);
    e.end = InputTime("End time: ", e.date);

    for(int i = 0; i < eventNum-1; i++)
    {
        if( (e.end > ec[i].start && e.end < ec[i].end)  || (e.start < ec[i].end && e.start > ec[i].start) )
        {
            struct tm temp;
            temp = *localtime(&(ec[i].date));
            printf("Warning, this event overlaps: \n");
            printf("%d/%d/%d\n", temp.tm_mon, temp.tm_mday, temp.tm_year);
        }
    }

    e.value = true;
    printf("This event is added successfully.\n");

    return e;
}

void SortEvent(struct event *ec, int eventNum)
{
    int i,j;
    struct event temp;
    for (i = 0; i < eventNum; ++i)
    {
        for (j = 0; j < eventNum - i - 1; ++j)
        {
            if (ec[j].start > ec[j + 1].start)
            {
                temp = ec[j];
                ec[j] = ec[j + 1];
                ec[j + 1] = temp;
            }
        }
    }
}

void DisplayAllEvent(struct event *ec, int eventNum)
{
    struct tm t, t1, t2;
    for(int i=0; i < eventNum; i++)
    {
        if( ec[i].value )
        {
            t = *localtime(&(ec[i].date));
            t1 = *localtime(&(ec[i].start));
            t2 = *localtime(&(ec[i].end));

            printf("%d/%d/%d ", t.tm_mon + 1, t.tm_mday, t.tm_year + 1900);
            PrintTime(t1);
            PrintTime(t2);
            printf("%s\n", ec[i].WhatToDo);
        }
    }
}

void DisplayNowEvent(struct event *ec, int eventNum){
    time_t temp;
    struct tm t, t1, t2;
    bool value = false;
    temp = time(NULL);
    for(int i=0; i < eventNum; i++)
    {
        if( ec[i].start < temp && ec[i].end > temp )
        {
            printf("Currently active events: \n");

            t = *localtime(&(ec[i].date));
            t1 = *localtime(&(ec[i].start));
            t2 = *localtime(&(ec[i].end));

            printf("%d/%d/%d ", t.tm_mon + 1, t.tm_mday, t.tm_year + 1900);
            PrintTime(t1);
            PrintTime(t2);
            printf("%s\n", ec[i].WhatToDo);
            
            value = true;
        }
    }
    if(!value)
        printf("There is no event actively.\n");
}

void PrintTime(struct tm t){
    if(t.tm_hour > 12)
        if(t.tm_min >= 0 && t.tm_min <= 9)
            printf("%d:0%dPM ", t.tm_hour - 12, t.tm_min);
        else
            printf("%d:%dPM ", t.tm_hour - 12, t.tm_min);
    else
        if(t.tm_min >= 0 && t.tm_min <= 9)
            printf("%d:0%dPM ", t.tm_hour, t.tm_min);
        else
            printf("%d:%dPM ", t.tm_hour, t.tm_min);
}

void DeleteEvent(struct event *ec, int eventNum)
{
    time_t temp;
    temp = time(NULL);
    struct tm t, t1, t2;
    bool value = false;

    printf("Deleting: \n");

    for(int i = 0; i < eventNum; i++)
    {
        if( ec[i].end < temp && ec[i].value == true )
        {
            ec[i].value = false;
            value = true;

            t = *localtime(&(ec[i].date));
            t1 = *localtime(&(ec[i].start));
            t2 = *localtime(&(ec[i].end));

            printf("%d/%d/%d ", t.tm_mon + 1, t.tm_mday, t.tm_year + 1900);
            PrintTime(t1);
            PrintTime(t2);
            printf("%s\n", ec[i].WhatToDo);
        }
    }

    if(!value)
        printf("No events will be deleted.\n");
}