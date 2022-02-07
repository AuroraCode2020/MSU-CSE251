#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
 * A simple war game by cards.
 * By:  AuroraCode2020
 */

void PrintResult(int value);
void PrintNumber(int number,int player);
void PrintHuaSe(int huase,int player);

int main()
{
	time_t t;
	srand((unsigned) time(&t));
	PrintResult(0);
}

void PrintResult(int value)
{
	if(value==2)
	{
		printf("this is a tie\n");	
	}
	int n1,n2,h1,h2;
	n1 = rand() % 13;
	n2 = rand() % 13;
	h1 = rand() % 4;
	h2 = rand() % 4;
	if(n1==n2)
	{
		if(h1==h2)
		{
			PrintResult(value+1);
		}
		else
		{
			if(h1>h2)
			{
				printf("Player 1 wins\n");
			}
			else
			{
				printf("Player 2 wins\n");
			}
			PrintNumber(n1,1);
			PrintNumber(n2,2);
			PrintHuaSe(h1,1);
			PrintHuaSe(h2,2);
		}
	}
	{
		if(n1>n2)
		{
			printf("Player 1 wins\n");
		}
		else
		{
			printf("Player 2 wins\n");
		}
		PrintNumber(n1,1);
		PrintNumber(n2,2);
		PrintHuaSe(h1,1);
		PrintHuaSe(h2,2);
	}
}

void PrintNumber(int number,int player)
{
	switch(number)
	{
		case 0:printf("Player %d's number is 2\n",player);break;
		case 1:printf("Player %d's number is 3\n",player);break;
		case 2:printf("Player %d's number is 4\n",player);break;
		case 3:printf("Player %d's number is 5\n",player);break;
		case 4:printf("Player %d's number is 6\n",player);break;
		case 5:printf("Player %d's number is 7\n",player);break;
		case 6:printf("Player %d's number is 8\n",player);break;
		case 7:printf("Player %d's number is 9\n",player);break;
		case 8:printf("Player %d's number is 10\n",player);break;
		case 9:printf("Player %d's number is J\n",player);break;
		case 10:printf("Player %d's number is Q\n",player);break;
		case 11:printf("Player %d's number is K\n",player);break;
		case 12:printf("Player %d's number is A\n",player);break;
	}
}

void PrintHuaSe(int huase,int player)
{
	switch(huase)
	{
		case 0:printf("Player %d's huase is meihua\n",player);break;
		case 1:printf("Player %d's huase is heitao\n",player);break;
		case 2:printf("Player %d's huase is fangkuai\n",player);break;
		case 3:printf("Player %d's huase is hongtao\n",player);break;
	}
}
