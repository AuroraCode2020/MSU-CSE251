#include "file.h"

/*
∗ project3
∗ By: AuroraCode2020
*/

void InputString(char *str, int max)
{
    char buffer[100];
    
    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);

    /* Remove any stray newlines from the buffer */
    while (buffer[0] == '\n')
        fgets(buffer, sizeof(buffer), stdin);
    
    /* Remove any \n we may have input */
    if(strlen(buffer) > 0)
        buffer[strlen(buffer)-1] = '\0';
        
    /* Copy up to max characters to our string */
    strncpy(str, buffer, max);
    str[max-1] = '\0';
}

time_t InputDate(char *notice)
{
    char buffer[100];
    char *result;
    struct tm date;

    int p1 = -1, p2 = -1;
    bool value;

    printf("%s", notice);

    do
    {
        fgets(buffer, sizeof(buffer), stdin);

        for(int i=0; buffer[i] != '\0'; i++)
        {
            if(p1 == -1 && buffer[i] == '/')
            {
                p1 = i;
                continue;
            }
            if(p1 != -1 && buffer[i] == '/')
            {
                p2 = i;
                continue;
            }
            if(p1 != -1 && p2 != -1 && buffer[i] =='/' )
            {
                printf("Please enter a right date!");
                value = false;
                break;
            }
            if(buffer[i] == '\n')
                value = true;
        }
        if(value)
            break;
        else
            continue;
    } while(true);
    

    if(strlen(buffer) > 0)
        buffer[strlen(buffer)-1] = '\0';

    result = strptime(buffer, "%m/%d/%Y", &date);

    date.tm_min = 0;
    date.tm_hour = 0;
    date.tm_sec = 0;
    date.tm_isdst = -1;

    return mktime(&date);
}

time_t InputTime(char *prompt, time_t date)
{
    char buffer[10];
    int hour, minute1, minute2, minute;
    char ap1, ap2;
    int sum;
    time_t result;
    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin);

    do
    {
        if(buffer[1] == ':')
        {
            hour = buffer[0] - 48;
            if( hour < '0' && hour > '9' )
            {
                printf("Please enter a right time!\n");
                continue;
            }
            minute1 = buffer[2] - 48;
            minute2 = buffer[3] - 48;
            if( minute1 < '0' && minute1 > '5' )
            {
                
            }
            minute = minute1 * 10 + minute2;
            ap1 = buffer[4];
            ap2 = buffer[5];
            if( buffer[6] != '\n' )
            {
                printf("Please enter a right time!\n");
                continue;
            }
            else
            {
                if( (ap1 == 'a' || ap1 == 'A') && (ap2 == 'm' || ap2 == 'M') )
                {
                    sum = hour * 60 * 60 + minute * 60;
                    result = date + sum;
                    break;
                }
                else if( (ap1 == 'p' || ap1 == 'P') && (ap2 == 'm' || ap2 == 'M') )
                {
                    sum = hour * 60 * 60 + minute * 60 + 43200;
                    result = date + sum;
                    break;
                }
                else
                {
                    printf("Please enter a right time!\n");
                    continue;
                }
            }
        }
        else if(buffer[2] == ':')
        {
            hour = (buffer[0] - 48) * 10 + buffer[1];
            if( hour < 10 && hour > 12 )
            {
                printf("Please enter a right time!\n");
                continue;
            }
            minute1 = buffer[3] - 48;
            minute2 = buffer[4] - 48;
            if( minute1 < '0' && minute1 > '5' )
            {
                printf("Please enter a right time!\n");
                continue;
            }
            minute = minute1 * 10 + minute2;
            ap1 = buffer[5];
            ap2 = buffer[6];
            if( buffer[7] != '\n' )
            {
                printf("Please enter a right time!\n");
                continue;
            }
            else
            {
                if( (ap1 == 'a' || ap1 == 'A') && (ap2 == 'm' || ap2 == 'M') )
                {
                    sum = hour * 60 * 60 + minute * 60;
                    result = date + sum;
                    break;
                }
                else if( (ap1 == 'p' || ap1 == 'P') && (ap2 == 'm' || ap2 == 'M') )
                {
                    sum = hour * 60 * 60 + minute * 60 + 43200;
                    result = date + sum;
                    break;
                }
                else
                {
                    printf("Please enter a right time!\n");
                    continue;
                }
            }
        }
        else
        {
            printf("Please enter a right time!\n");
            continue;
        }
    } while(true);

    return result;
}