#include <stdio.h>
#include <time.h>  //获得时间
#include <string.h>
#include <stdlib.h>
//#include <iostream>  //c++的头文件
//using namespace std; //VS编程时需要添加
#define ROW 
#define COL 10
//#define _CRT_SECURE_NO_WARNINGS 1

int mine_count(char board[ROW + 2][COL + 2], int row, int col) //统计剩余*的数目

{

	int count = 0;

	for (int i = 1; i < (row - 1); i++)

	{

		for (int j = 1; j < (col - 1); j++)

		{

			if (board[i][j] == '*')

				count++;

		}

	}

	return count;

}


int mine_num(char mine[ROW + 2][COL + 2], int x, int y)//统计某个位置雷的个数
{
	return ((mine[x - 1][y - 1] - '0') + (mine[x][y + 1] - '0') + (mine[x + 1][y + 1] - '0') + (mine[x - 1][y] - '0')
		+ (mine[x][y - 1] - '0') + (mine[x + 1][y] - '0') + (mine[x + 1][y + 1] - '0') + (mine[x - 1][y + 1] - '0'));

}
void spread_board(char board[ROW + 2][COL + 2], char mine[ROW + 2][COL + 2], int x, int y)
{
	if ((1 <= x && x <= 10) && (1 <= y && y <= 10) && (mine[x][y] != '1') && (board[x][y] == '*'))
	{
		if (mine_num(mine, x, y)>0)
		{
			board[x][y] = mine_num(mine, x, y) + '0';
		}
		else
		{
			board[x][y] = ' ';
			spread_board(board, mine, x - 1, y - 1);
			spread_board(board, mine, x - 1, y);
			spread_board(board, mine, x - 1, y + 1);
			spread_board(board, mine, x, y + 1);
			spread_board(board, mine, x + 1, y + 1);
			spread_board(board, mine, x + 1, y);
			spread_board(board, mine, x + 1, y - 1);
			spread_board(board, mine, x, y - 1);


		}
	}
}
void set_mine(char mine[ROW + 2][COL + 2], int row, int col, int num)
{
	int i = 0;
	srand((unsigned)(time)(NULL));/*以现在的系统时间作为随机数的种子来产生随机数！
								  至于NULL这个参数。只有设置成NULL才能获得系统的时间！在调用rand（）这个函数之前使用*/
	for (i = 0; i<num; i++)
	{
		int x = rand() % (row - 2) + 1;
		int y = rand() % (col - 2) + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
		}
		else
		{
			i--;
		}
	}
}
void menu()
{
	printf("**********************\n");
	printf("***   1.开始游戏   ***\n");
	printf("***   2.退出游戏   ***\n");
	printf("   请选择接下来的路线:> ");
}
void print_board(char board[ROW + 2][COL + 2], int row, int col)
{
	printf("\n");
	int i = 0;
	printf("0 1 2 3 4 5 6 7 8 9 10\n");
	for (i = 1; i<row - 1; i++)
	{
		int j = 0;
		printf("%2d", i);
		for (j = 1; j<(col - 1); j++)
		{
			printf("%2c", board[i][j]);
		}
		printf("\n");
	}
}
void my_game()    //游戏主体
{
	int x = 0, y = 0;
	int count = 0;//剩余雷数
	int num = 0;
	char mine[ROW + 2][COL + 2];//定义雷区，跟迷雾区
	char board[ROW + 2][COL + 2];
	//初始化雷区，迷雾区
	memset(mine, '0', sizeof(mine));//来对一段内存空间全部设置为某个字符，一般用在对定义的字符串进行初始化为‘ ’或‘/0’
	memset(board, '*', sizeof(board));
	//布雷
	printf("请输入雷数：>");
	scanf("%d", &num);
	set_mine(mine, (ROW + 2), (COL + 2), num);
	//打印迷雾区
	print_board(board, (ROW + 2), (COL + 2));
	while (1)
	{
		//判断是否胜利
		count = mine_count(board, (ROW + 2), (COL + 2));
		if (count == num)
		{
			printf("恭喜你，成功的排掉了所有的雷！！！\n");
			break;
		}
		//输入坐标，同时判断坐标是否在合法范围内
		printf("please input (x,y)");
		scanf("%d,%d", &x, &y);
		if ((x >= 1 && x <= 10) && (y <= 10 && y >= 1))
		{
			if (mine[x][y] == '1')
			{
				printf("sorry,你踩到雷，请！再接再厉 \n");
				break;
			}
			else
			{
				spread_board(board, mine, x, y);
				print_board(board, (ROW + 2), (COL + 2));
			}
		}
		else
		{
			printf("你输入的坐标超出范围！\n");
		}

	}
}


int main()
{
   int input=0;
   do
    {
	   menu();
	   scanf("%d",&input);
	   switch(input)
	   {
	   case 1:my_game();break;
	   case 0:printf("退出游戏。\n");break;
	   default:printf("\n输入错误，请重新输入！！\n");break;


        }
	 }while(input);
   return 0;
}															