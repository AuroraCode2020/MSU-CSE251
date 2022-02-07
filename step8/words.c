#include <stdio.h>

/* 
 * Name : AuroraCode2020
 * Program to experiment with character arrays
 */

#define Space 1000
 
int main ()
{
    char c;
    char str[Space+1];
    int len = 0;
    int words = 0,sum = 0;
	char w[Space][Space];
	int MaxWord = 0,LengthOfMaxWord = 0;
	int i = 0;
  
    puts ("Enter text. Include a dot ('.') to end a sentence to exit:");
    do 
    {
        c=getchar();
        if(c != ' ' && c != '.' && len < Space)
        {
            /* This is a character of a word */
            str[len] = c;
            w[i][len] = c;
            len++;
        }
        else
        {
            /* The word is done */
            sum += len;
            words ++;
            if(len>LengthOfMaxWord)
            {
            	LengthOfMaxWord = len;
            	MaxWord = i;
            }
            i++;
            str[len] = 0;
            if(len==0)
            {
            	continue;
            }
            printf("%s\n", str);
            len = 0;
        }
    } while (c != '.');
    str[len] = 0;
    printf("%s\n", str);
    printf("%.2f\n",(double)sum/(double)words);
    for(i=0;i<LengthOfMaxWord;i++)
    {
    	printf("%c",w[MaxWord][i]);
    }
    printf("\n");
}
