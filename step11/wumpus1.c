#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * Name :  AuroraCode2020
 * 
 * Simple Wumpus game in 1D
*/

/* Add any #defines here */

/* Id's for things in our Cave */
#define Empty 0
#define Wumpus 1
#define End 2

/* Number of rooms in our Cave */
#define CaveSize 20
#define ArraySize (CaveSize + 2)

/* Directions I can face */
#define Left 0
#define Right 1

/* Add any function prototypes here */

void CreateWorld(int cave[]);
int *GetEmptyRoom(int cave[]);
void DisplayWorld(int cave[], int *agent, int agentDir);
int DifferenceByDirection(int dir);
bool DisplayStatus(int cave[], int *agent);
void FireToWumpus(int cave[], int *agent, int agentDir);
 
int main()
{
	int cave[ArraySize];
	int *agentRoom;
	int agentDirection;
	char command[20];
	int direction;
    
    /* 播撒随机数种子 */
    srand(time(NULL));
    
    CreateWorld(cave);
    /* 把特工放入随机的一个空房间，并给予一个面向方向 */
    agentRoom = GetEmptyRoom(cave);
    agentDirection = rand() % 2;
    
    /* 游戏循环 */
    while(true)
    {
    	if(DisplayStatus(cave, agentRoom))
            break;
            
    	DisplayWorld(cave, agentRoom, agentDirection);
        /* 输入命令 */
        printf("Command: ");
        scanf("%20s", command);
        
        /* 读入quit命令结束游戏 */
        if(strcmp(command, "quit") == 0)
        {
            break;
        }
        /* 移动命令 */
        else if(strcmp(command, "move") == 0)
        {
            
            direction = DifferenceByDirection(agentDirection);
            if( *(agentRoom + direction) != End)
                agentRoom += direction;
        }
        /* 转向命令 */
        else if(strcmp(command, "turn") == 0)
        {
            agentDirection = !agentDirection;
        }
        /* 开火命令 */
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

/* 创建世界函数 */
void CreateWorld(int cave[])
{
	int i;
	int *room;
	/* 置空洞穴 */
    for(i = 0;  i<ArraySize;  i++)
    {
        cave[i] = Empty;
    }
    /* 放置洞壁 */
    cave[0] = End;
    cave[ArraySize-1] = End;

    /* 将怪物放入随机的一个空房间 */
    room = GetEmptyRoom(cave);
    *room = Wumpus;
    
}

/* 返回一个指向空房间的指针 */
int *GetEmptyRoom(int cave[])
{
    int room;
    do
    {
        room = rand() % ArraySize;
    } while(cave[room] != Empty);
    
    return &cave[room];
}

/* 显示世界函数 */
void DisplayWorld(int cave[], int *agent, int agentDir)
{
    int *room;
    
    for(room = cave + 1;  *room != End;  room++)
    {
        if(room == agent)
        {
            switch(agentDir)
            {
            case Left:
                printf("<A  ");
                break;
                
            case Right:
                printf(" A> ");
            }
            
            continue;
        }
        
        switch(*room)
        {
        case Wumpus:
            printf("-W- ");
            break;
            
        default:
            printf(" .  ");
            break;    
        }
    }
    
    printf("\n");
}

/* 移动函数 */
int DifferenceByDirection(int dir)
{
    if(dir == Left)
        return -1;
    else
        return 1;
}

/* 检测游戏状态 */
bool DisplayStatus(int cave[], int *agent)
{	
	int i;
	/* 如果怪物和玩家在一个房间里，游戏结束 */
	if(*agent == Wumpus)
    {
        printf("You have been eaten by the Wumpus\n");
        return true;
    }
    /* 如果怪物离玩家一格距离，玩家会闻到怪物气味 */
    if(*(agent-1) == Wumpus || *(agent + 1) == Wumpus)
    {
        printf("I smell a Wumpus\n");
    }
    /* 检测洞穴里是否还有怪物 */
    for(i=1; i <= CaveSize; i++)
    {
    	if(cave[i] == Wumpus)
    	{
    		break;
    	}
    }
    if(i == CaveSize + 1)
    {
    	printf("You win the game\n");
    	exit(0);
    }
    /* We will return true to indicate we are dead! */
    return false;
}

/* 开火函数 */
void FireToWumpus(int cave[], int *agent, int agentDir)
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
	else
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
}