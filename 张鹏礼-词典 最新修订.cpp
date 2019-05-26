#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define LEN sizeof(struct student)
struct student
{ char word[10];//单词 
  char translate[12];//翻译 
  }stu[20]={0},temp;
void input();        //录入信息
void outputgrade(); //信息的显示
void change();      //修改信息
void del();         //删除信息
void search();      //查找
void search1();     //单词查找
void search2();     //翻译查找 
void count();      //统计单词个数 
int  compare(char a[10],char c[10]);   
  
//主函数
main()
{
int a,n; 
char c[10],d[10];

 system("color 71");//7背景颜色；百色，1前景蓝色

 
   do
   {
 printf("     \n");
 printf("     \n");
 printf("          ********************************************\n");
 printf("          *       【欢迎使用本电子英汉词典】         *\n"); 
 //printf("          *         作者:                      *\n");  
 printf("          *------------------------------------------*\n");   
 printf("          *         1.词条录入                       *\n");
 printf("          *         2.词条修改                       *\n");
 printf("          *         3.单词删除                       *\n"); 
 printf("          *         4.单词查询                       *\n");
 printf("          *         5.统计单词个数                   *\n");
 printf("          *         0.退出                           *\n");
 printf("          ********************************************\n");   
    printf("              输入你要操作的序号 :\n ");
	printf("                                 ");
    scanf("%d",&a);
	

    switch(a)
    {
   
     case 1:printf("\n");input(); break;
     case 2:printf("\n");change();break;
     case 3:printf("\n");del();   break;
     case 4:printf("\n");search(); break;
     case 5:printf("\n");count();  break;
     case 0:printf("\n         谢谢使用！\n");exit(0);break;//退出系统
     default:printf("\n选择菜单是 0 to 4,请重新选择：\n"); break;
    }
   }while(a);
   
}
 //录入信息
 void input()
{  int i,k=0;
   char ch[10];
    FILE *fp;//定义文件指针
  if((fp=fopen("data.txt","a+"))==NULL)//打开指定文件
  { 
	  printf("打开失败\n");
	  return;
  }
  while(!feof(fp))//检查文件结束
  {
	  if(fread(&stu[k] ,LEN,1,fp)==1)
		  k++;/*统计当前记录条数*/
  }
  fclose(fp);
  if(k==0)
	  printf("没有记录!\n");
  else
  {
	  system("cls");
      outputgrade();
  }
   if((fp=fopen("data.txt","wb"))==NULL)
	{
	  printf("打开失败\n");
	  return;
	}

   for(i=0;i<k;i++)
	{   fwrite(&stu[i] ,LEN,1,fp);/*向指定的磁盘文件写入信息*/
       
	}

 
   printf("\n输入单词:\n");
  do
  {   printf("\n单词:   翻译:  \n");
    
    scanf("%s%s",&stu[k].word,&stu[k].translate);
	for(i=0;i<k;i++)
	  {
	  
	  if(strcmp(stu[k].word,stu[i].word)==0)
	    {
	    printf("此单词已存在!");
	    fclose(fp);
	    return;
	    }
	    
	  }
    printf("您输入的是:    %s\t%s\n是否保存？y/n",stu[k].word,stu[k].translate);
    char d[10];
	scanf("%s",&d);
	if(strcmp(d,"y")==0||strcmp(d,"Y")==0)
	{
	    printf("\n保存成功！\n");
		if(fwrite(&stu[k],LEN,1,fp)!=1)/*将新录入的信息写入指定的磁盘文件*/
	     {
			 printf("存取失败!");
	       
		 }
	     else
		 {
			k++;
		 }
	    printf("\n是否继续输入单词(y/n): ");
	    scanf("%s",ch);
   }
   
   }
   while(strcmp(ch,"y")==0||strcmp(ch,"Y")==0);
  
    fclose(fp);
    outputgrade();
}
//信息的显示
void outputgrade()
{  int i,k=0;
   FILE *fp;
   fp=fopen("data.txt","rb");
   while(!feof(fp))
   {
   if(fread(&stu[k] ,LEN,1,fp)==1) 
   k++;
   }  
   fclose(fp);
   system("cls");
   printf(" 单词是:\n");
   printf("单词  翻译  \n");
   printf("-------------------------------------\n");
   for(i=0;i<k;i++)
   { 
	   printf("%s %4s",stu[i].word,stu[i].translate);
       printf("\n");  
	   printf("-------------------------------------\n");
   }
}
//修改信息
void change()

{
   
   char a[10];
   char ch[10];
   int i,k=0;
   
  FILE *fp;/*定义文件指针*/
  if((fp=fopen("data.txt","r+"))==NULL)/*打开指定文件*/
  { 
	  printf("打开失败\n");
	  return;
  }

  while(!feof(fp))//检查文件结束
  {
	  if(fread(&stu[k] ,LEN,1,fp)==1)
		  k++;/*统计当前记录条数*/
  }
  fclose(fp);
  if(k==0)
  {
	  printf("没有记录!\n");
	  return;
  }

  else
  {
	  system("cls");
      outputgrade();
  }
   printf("\n输入你要修改的单词:");
   scanf("%s",a);
   for(i=0;i<k;i++)
   {
    if(strcmp(stu[i].word,a)==0)//判断 
       break;
	
   }  
	  
  if(i==k) 
	 { system("cls");
	  printf("\t\t未找到记录!\n");/*未找到要查找的信息*/
     }
  else
	 {  printf("\n你确定要修改单词吗？(y/n): ");
       scanf("%s",ch);
       if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)   
	   {    printf("\n单词:"); 
	        scanf("%s",&stu[i].word);
	   }
      if((fp=fopen("data.txt","wb"))==NULL)
	   {   printf("打开失败\n");
	     return;
	   }
	for(i=0;i<k;i++)
	{ if(fwrite(&stu[i] ,LEN,1,fp)!=1)
		{ printf("保存失败!");}
		
	}

	printf("\t\t修改成功。\n");
       fclose(fp);
   
   

   outputgrade();
  }
}
//删除信息
void del()
{  
   char c[10],ch[10];
   FILE *fp;
  int i,j,k=0;
  
  if((fp=fopen("data.txt","r+"))==NULL) 
     { printf("打开失败\n");return;}

  while(!feof(fp))//检查文件结束
  {
	  if(fread(&stu[k] ,LEN,1,fp)==1)
		  k++;/*统计当前记录条数*/
  }
  fclose(fp);
  if(k==0) 
  {
	  printf("无记录!\n");
	  return;
  }
  else
  {
   printf("\n输入你要删除的单词 ：\n");
   printf("\t\t\t");
   scanf("%s",c);
   for(i=0;i<k;i++)
   {   if(strcmp(stu[i].word,c)==0) 
		  break;
       
   }
   if(i==k) 
	 { system("cls");
	  printf("\t\t未找到记录!\n");/*未找到要查找的信息*/
     }
   else
	{ printf("已删除，是否保存（若不保存则取消本次删除操作）?(y/n)");
    scanf("%s",ch);
  if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要进行删除*/
	{  for(j=i;j<k-1;j++)
	   { stu[j]=stu[j+1]; }
	}
  else 
	 { return; 
      system("cls");
	 }
    k--;
    if((fp=fopen("data.txt","wb"))==NULL)
     { printf("打开失败\n");return;}
    for(j=0;j<k;j++)/*将更改后的记录重新写入指定的磁盘文件中*/
	{   
		if(fwrite(&stu[j] ,LEN,1,fp)!=1)
           printf("保存失败!\n");
	}
    fclose(fp);
   printf("\n你已经删除 %s的信息\n",c);

   
   outputgrade();
  }
  }
}



//统计单词个数 
void count() //单词查 
{   FILE *fp;
  int k=0;
  if((fp=fopen("data.txt","a+"))==NULL)
     { printf("打开失败\n");return;}
  while(!feof(fp))  
	{if(fread(&stu[k],LEN,1,fp)==1) 
		  k++;/*统计单词个数*/
	}
  if(k==0) {printf("没有记录!\n");}
	  
  system("cls");
  printf("\t\t\n");
  printf("\t\t共有单词：%d\n",k);/*将统计的个数输出*/
  printf("\t\t\n");
  printf("\t\t\n");
  fclose(fp);
	
}

void search()/*自定义查找函数*/
{ 
 int n;
  printf("请选择按单词查找还是按中文查找\n1.单词查找\n2.翻译查找\n");
  scanf("%d",&n);
  switch(n)
  {
  	case 1:printf("\n");search1();break;
  	case 2:printf("\n");search2();break;
  }
  } 
  void search1()
  {
  	FILE *fp;
  int i,k=0;
  char ch[10],a[10];
  if((fp=fopen("data.txt","rb"))==NULL)
     { printf("打开失败\n");return;}
  while(!feof(fp))  
  if(fread(&stu[k],LEN,1,fp)==1)
   k++;
  fclose(fp);
  if(k==0) {printf("没有记录!\n");return;}
  printf("输入要查找的单词:");
   scanf("%s",a);
  for(i=0;i<k;i++)
  
  {    if(compare(a,stu[i].word)==1);
  
         //if(strcmp(stu[i].word,a)==0)//查找输入的是否在记录中
          break;
  }
   if(i==k) 
	  { system("cls");
	   printf("\t\t未找到!\n");/*未找到要查找的信息*/ 
       }
   else
   {
   system("cls");
   printf(" 单词是:\n");
   printf("单词 翻译  \n");
   printf("-------------------------------------\n");
   
   printf("%s %s\n",stu[i].word,stu[i].translate);
   
	printf("-------------------------------------\n");
   
   printf("是否修改?(y/n)");
   scanf("%s",ch);
   if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
      {
          change();
	      
	  }
   else return;
   }   
  
  }
  void search2()
  {
  	char str[10][10]={0}; 
  	FILE *fp;
  int i,k=0,p=0,z;
  char ch[10],a[10];
  if((fp=fopen("data.txt","rb"))==NULL)
     { printf("打开失败\n");return;}
  while(!feof(fp))  if(fread(&stu[k],LEN,1,fp)==1) k++;
  fclose(fp);
  if(k==0) {printf("没有记录!\n");return;}
  printf("输入要查找的翻译:");
   scanf("%s",a);
  for(i=0;i<k;i++)
  {   //if(compare(a,stu[i].translate)==1);   
  if(strcmp(stu[i].translate,a)==0)//查找输入的翻译是否在记录中
          //strcpy(&str[1][],a);//str=stu[i].word;//???
        {
		  
		  strcpy(str[k],stu[i].word);
		  k++;
		  
        }    /*
          vector<string> v;
          v.push_back(stu[i].word)//stu[i].wor换成string类型无敌好吧，两行，压不限制单词长度 
	      */
          
   }
   if(str==0) 
	  { system("cls");
	   printf("\t\t未找到!\n");/*未找到要查找的信息*/ 
       }
   else
   {
   system("cls");
   printf(" 已找到，单词是:\n");
   printf("单词 翻译  \n");
   
   
   printf("-------------------------------------\n");
   for(i=0;i<k;i++)
   printf("%s\n",str[i]);
   //printf("%s %s\n",stu[i].word,stu[i].translate);
   
	printf("-------------------------------------\n");

   
   printf("是否修改?(y/n)");
   scanf("%s",ch);
   if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
      {
          change();
	      
	  }
   else return;
   }   
  }
  int compare(char *a,char *c)
{

	for(int d=0;d<10;d++)
	{
		if(abs(a[d]-c[d])!=0||(abs(a[d]-c[d])!=32))
		
		return 0;
		
	}
	return 1;
	
	
}
