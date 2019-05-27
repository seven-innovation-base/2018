#include <stdio.h>
#include <time.h>  //���ʱ��
#include <string.h>
#include <stdlib.h>
//#include <iostream>  //c++��ͷ�ļ�
//using namespace std; //VS���ʱ��Ҫ���
#define ROW 
#define COL 10
//#define _CRT_SECURE_NO_WARNINGS 1

int mine_count(char board[ROW + 2][COL + 2], int row, int col) //ͳ��ʣ��*����Ŀ

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


int mine_num(char mine[ROW + 2][COL + 2], int x, int y)//ͳ��ĳ��λ���׵ĸ���
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
	srand((unsigned)(time)(NULL));/*�����ڵ�ϵͳʱ����Ϊ������������������������
								  ����NULL���������ֻ�����ó�NULL���ܻ��ϵͳ��ʱ�䣡�ڵ���rand�����������֮ǰʹ��*/
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
	printf("***   1.��ʼ��Ϸ   ***\n");
	printf("***   2.�˳���Ϸ   ***\n");
	printf("   ��ѡ���������·��:> ");
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
void my_game()    //��Ϸ����
{
	int x = 0, y = 0;
	int count = 0;//ʣ������
	int num = 0;
	char mine[ROW + 2][COL + 2];//������������������
	char board[ROW + 2][COL + 2];
	//��ʼ��������������
	memset(mine, '0', sizeof(mine));//����һ���ڴ�ռ�ȫ������Ϊĳ���ַ���һ�����ڶԶ�����ַ������г�ʼ��Ϊ�� ����/0��
	memset(board, '*', sizeof(board));
	//����
	printf("������������>");
	scanf("%d", &num);
	set_mine(mine, (ROW + 2), (COL + 2), num);
	//��ӡ������
	print_board(board, (ROW + 2), (COL + 2));
	while (1)
	{
		//�ж��Ƿ�ʤ��
		count = mine_count(board, (ROW + 2), (COL + 2));
		if (count == num)
		{
			printf("��ϲ�㣬�ɹ����ŵ������е��ף�����\n");
			break;
		}
		//�������꣬ͬʱ�ж������Ƿ��ںϷ���Χ��
		printf("please input (x,y)");
		scanf("%d,%d", &x, &y);
		if ((x >= 1 && x <= 10) && (y <= 10 && y >= 1))
		{
			if (mine[x][y] == '1')
			{
				printf("sorry,��ȵ��ף��룡�ٽ����� \n");
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
			printf("����������곬����Χ��\n");
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
	   case 0:printf("�˳���Ϸ��\n");break;
	   default:printf("\n����������������룡��\n");break;


        }
	 }while(input);
   return 0;
}															