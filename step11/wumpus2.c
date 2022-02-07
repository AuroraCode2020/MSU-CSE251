#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Name :  AuroraCode2020
 * 
 * Simple Wumpus game in 2D
*/

/* Id's for things in our Cave */
#define Empty 0
#define Wumpus 1
#define End 2
#define Pit 3

/* Number of rooms in our Cave in each dimension */
#define CaveSize 10
#define ArraySize (CaveSize + 2)

/* Directions I can face */
#define Left 0
#define Up 1
#define Right 2
#define Down 3

void CreateWorld(int cave[ArraySize][ArraySize]);
int *GetEmptyRoom(int cave[ArraySize][ArraySize]);
void DisplayWorld(int cave[ArraySize][ArraySize], int *agent, int agentDir);
int DifferenceByDirection(int dir);
bool DisplayStatus(int cave[ArraySize][ArraySize], int *agent, int *wumpus);
void FireToWumpus(int cave[ArraySize][ArraySize], int *agent, int agentDir);
 
int main()
{
    int *agentRoom,*wumpusRoom;
    int *pitRoom[10];
    int agentDirection;
    char command[20];
    int cave[ArraySize][ArraySize];
    int d;
    
    /* 播撒随机数种子 */
    srand(time(NULL));
    
    CreateWorld(cave);
    
    /* 将玩家放置到一个空房间并确定面向方向 */
    agentRoom = GetEmptyRoom(cave);
    agentDirection = rand() % 4;
    /* 将怪物放置到一个空房间 */
    wumpusRoom = GetEmptyRoom(cave);
    *wumpusRoom = Wumpus;
    /* 将十个坑洞放置到十个空房间 */
    for(int i=0; i<10; i++)
    {
        pitRoom[i] = GetEmptyRoom(cave);
        *pitRoom[i] = Pit;
    }
    
    /* 游戏循环 */
    while(true)
    {
    	if(DisplayStatus(cave, agentRoom, wumpusRoom))
            break;
            
		DisplayWorld(cave, agentRoom, agentDirection);
		
        /* 获取玩家命令 */
        printf("Command: ");
        scanf("%20s", command);
        
        if(strcmp(command, "quit") == 0)
        {
            break;
        }
        else if(strcmp(command, "move") == 0)
        {
            d = DifferenceByDirection(agentDirection);
            /* 直接在内存里操作，二维数组在C语言中是一行接着一行存放的 */
            if(*(agentRoom + d) != End)
                agentRoom += d;
        }
        else if(strcmp(command, "turn") == 0)
        {
            agentDirection ++;
            if(agentDirection > Down)
                agentDirection = Left;
        }
        else if(strcmp(command, "fire") == 0)
        {
            FireToWumpus(cave, agentRoom, agentDirection);
        }
        else
        {
            printf("I don't know what you are talking about\n");
        }
    }
    
}

/* 置空所有房间、放置洞壁 */
void CreateWorld(int cave[ArraySize][ArraySize])
{
	int i, j;
    
    for(i = 0;  i<ArraySize;  i++)
    {
        for(j = 0;  j<ArraySize;  j++)
        {
            if(i == 0 || j == 0 || i == ArraySize-1 || j == ArraySize-1)
            {
                cave[i][j] = End;
            }
            else
            {
                cave[i][j] = Empty;
            }
        }
    }
}

/* 将玩家、怪物或坑洞随机放置到一个空房间 */
int *GetEmptyRoom(int cave[ArraySize][ArraySize])
{
    int row, col;
    int *room;
    
    do
    {
        /* We need a random number in each dimension */
        row = rand() % ArraySize;
        col = rand() % ArraySize;
        
        room = &cave[row][col];
    } while(*room != Empty);
    
    return room;
}

/* 显示世界 */
void DisplayWorld(int cave[ArraySize][ArraySize], int *agent, int agentDir)
{
    int row, col;
    int *room;
    
    /* Loop over the rows of the cave */
    for(row=1;  row <= CaveSize + 1;  row++)
    {
        /* 
         * This loop lets us print an up direction 
         * above the agent or a v below the agent
         */
         
        for(col=1; col<=CaveSize; col++)
        {
            if(&cave[row][col] == agent && agentDir == Up)
            {
                printf(" ^  ");
            }
            else if(&cave[row-1][col] == agent && agentDir == Down)
            {
                printf(" v  ");
            }
            else
            {
                printf("    ");
            }
        }
        
        printf("\n");
        if(row > CaveSize)
            break;
            
        /*
         * This loop prints the agent or the room contents
         */ 
         
        for(col=1; col<=CaveSize; col++)
        {
            room = &cave[row][col];
            if(room == agent)
            {
                switch(agentDir)
                {
                case Left:
                    printf("<A  ");
                    break;
                    
                case Right:
                    printf(" A> ");
                    break;
                    
                default:
                    printf(" A  ");
                    break;
                        
                }
                continue;
            }
            
            switch(*room)
            {
            case Wumpus:
                printf("-W- ");
                break;
            case Empty:
                printf(" .  ");
                break;
            case Pit:
                printf(" O  ");
                break;
            }
        }

        printf("\n");
    }
    
}

/* 移动函数 */
int DifferenceByDirection(int dir)
{
    switch(dir)
    {
    case Up:
        return -ArraySize;
        
    case Down:
        return ArraySize;
        
    case Left:
        return -1;
        
    case Right:
        return 1;
    }
}

/* 检测游戏状态 */
bool DisplayStatus(int cave[ArraySize][ArraySize], int *agent, int *wumpus)
{	
	int row,col;
	int *room;
	/* 如果怪物和玩家在一个房间里，游戏结束 */
	if(*agent == Wumpus)
    {
        printf("You have been eaten by the Wumpus\n");
        return true;
    }
    /* 如果玩家掉进坑洞，游戏结束 */
	if(*agent == Pit)
    {
        printf("You have fallen into a pit\n");
        return true;
    }
    /* 如果怪物离玩家一格距离，玩家会闻到怪物气味 */
    if(*(agent-1) == Wumpus || *(agent + 1) == Wumpus || *(agent-ArraySize) == Wumpus || *(agent+ArraySize) == Wumpus )
    {
        printf("I smell a Wumpus\n");
    }
    /* 如果坑洞离玩家一格距离，玩家会感到气流 */
    if(*(agent-1) == Pit || *(agent + 1) == Pit || *(agent-ArraySize) == Pit || *(agent+ArraySize) == Pit )
    {
        printf("I feel a draft\n");
    }
    /* 检测洞穴里是否还有怪物 */
    if(*wumpus != Wumpus)
    {
        printf("You win the game\n");
    }

    /* We will return true to indicate we are dead! */
    return false;
}

/* 开火函数 */
void FireToWumpus(int cave[ArraySize][ArraySize], int *agent, int agentDir)
{
	int *room = agent;
	if(agentDir == Left)
	{
		for(int i=0; i<3 && *room != End; i++)
		{
			room--;
			if(*room == Wumpus)
			{
				*room = Empty;
				break;
			}
		}
	}
	else if(agentDir == Right)
	{
		for(int i=0; i<3 && *room != End; i++)
		{
			room++;
			if(*room == Wumpus)
			{
				*room = Empty;
				break;
			}
		}
	}
    else if(agentDir == Up)
    {
        for(int i=0; i<3 && *room != End; i++)
        {
            room -= ArraySize;
            if(*room == Wumpus)
			{
				*room = Empty;
				break;
			}
        }
    }
    else if(agentDir == Down)
    {
        for(int i=0; i<3 && *room != End; i++)
        {
            room += ArraySize;
            if(*room == Wumpus)
			{
				*room = Empty;
				break;
			}
        }
    }
}