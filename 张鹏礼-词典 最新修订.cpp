#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define LEN sizeof(struct student)
struct student
{ char word[10];//���� 
  char translate[12];//���� 
  }stu[20]={0},temp;
void input();        //¼����Ϣ
void outputgrade(); //��Ϣ����ʾ
void change();      //�޸���Ϣ
void del();         //ɾ����Ϣ
void search();      //����
void search1();     //���ʲ���
void search2();     //������� 
void count();      //ͳ�Ƶ��ʸ��� 
int  compare(char a[10],char c[10]);   
  
//������
main()
{
int a,n; 
char c[10],d[10];

 system("color 71");//7������ɫ����ɫ��1ǰ����ɫ

 
   do
   {
 printf("     \n");
 printf("     \n");
 printf("          ********************************************\n");
 printf("          *       ����ӭʹ�ñ�����Ӣ���ʵ䡿         *\n"); 
 //printf("          *         ����:                      *\n");  
 printf("          *------------------------------------------*\n");   
 printf("          *         1.����¼��                       *\n");
 printf("          *         2.�����޸�                       *\n");
 printf("          *         3.����ɾ��                       *\n"); 
 printf("          *         4.���ʲ�ѯ                       *\n");
 printf("          *         5.ͳ�Ƶ��ʸ���                   *\n");
 printf("          *         0.�˳�                           *\n");
 printf("          ********************************************\n");   
    printf("              ������Ҫ��������� :\n ");
	printf("                                 ");
    scanf("%d",&a);
	

    switch(a)
    {
   
     case 1:printf("\n");input(); break;
     case 2:printf("\n");change();break;
     case 3:printf("\n");del();   break;
     case 4:printf("\n");search(); break;
     case 5:printf("\n");count();  break;
     case 0:printf("\n         ллʹ�ã�\n");exit(0);break;//�˳�ϵͳ
     default:printf("\nѡ��˵��� 0 to 4,������ѡ��\n"); break;
    }
   }while(a);
   
}
 //¼����Ϣ
 void input()
{  int i,k=0;
   char ch[10];
    FILE *fp;//�����ļ�ָ��
  if((fp=fopen("data.txt","a+"))==NULL)//��ָ���ļ�
  { 
	  printf("��ʧ��\n");
	  return;
  }
  while(!feof(fp))//����ļ�����
  {
	  if(fread(&stu[k] ,LEN,1,fp)==1)
		  k++;/*ͳ�Ƶ�ǰ��¼����*/
  }
  fclose(fp);
  if(k==0)
	  printf("û�м�¼!\n");
  else
  {
	  system("cls");
      outputgrade();
  }
   if((fp=fopen("data.txt","wb"))==NULL)
	{
	  printf("��ʧ��\n");
	  return;
	}

   for(i=0;i<k;i++)
	{   fwrite(&stu[i] ,LEN,1,fp);/*��ָ���Ĵ����ļ�д����Ϣ*/
       
	}

 
   printf("\n���뵥��:\n");
  do
  {   printf("\n����:   ����:  \n");
    
    scanf("%s%s",&stu[k].word,&stu[k].translate);
	for(i=0;i<k;i++)
	  {
	  
	  if(strcmp(stu[k].word,stu[i].word)==0)
	    {
	    printf("�˵����Ѵ���!");
	    fclose(fp);
	    return;
	    }
	    
	  }
    printf("���������:    %s\t%s\n�Ƿ񱣴棿y/n",stu[k].word,stu[k].translate);
    char d[10];
	scanf("%s",&d);
	if(strcmp(d,"y")==0||strcmp(d,"Y")==0)
	{
	    printf("\n����ɹ���\n");
		if(fwrite(&stu[k],LEN,1,fp)!=1)/*����¼�����Ϣд��ָ���Ĵ����ļ�*/
	     {
			 printf("��ȡʧ��!");
	       
		 }
	     else
		 {
			k++;
		 }
	    printf("\n�Ƿ�������뵥��(y/n): ");
	    scanf("%s",ch);
   }
   
   }
   while(strcmp(ch,"y")==0||strcmp(ch,"Y")==0);
  
    fclose(fp);
    outputgrade();
}
//��Ϣ����ʾ
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
   printf(" ������:\n");
   printf("����  ����  \n");
   printf("-------------------------------------\n");
   for(i=0;i<k;i++)
   { 
	   printf("%s %4s",stu[i].word,stu[i].translate);
       printf("\n");  
	   printf("-------------------------------------\n");
   }
}
//�޸���Ϣ
void change()

{
   
   char a[10];
   char ch[10];
   int i,k=0;
   
  FILE *fp;/*�����ļ�ָ��*/
  if((fp=fopen("data.txt","r+"))==NULL)/*��ָ���ļ�*/
  { 
	  printf("��ʧ��\n");
	  return;
  }

  while(!feof(fp))//����ļ�����
  {
	  if(fread(&stu[k] ,LEN,1,fp)==1)
		  k++;/*ͳ�Ƶ�ǰ��¼����*/
  }
  fclose(fp);
  if(k==0)
  {
	  printf("û�м�¼!\n");
	  return;
  }

  else
  {
	  system("cls");
      outputgrade();
  }
   printf("\n������Ҫ�޸ĵĵ���:");
   scanf("%s",a);
   for(i=0;i<k;i++)
   {
    if(strcmp(stu[i].word,a)==0)//�ж� 
       break;
	
   }  
	  
  if(i==k) 
	 { system("cls");
	  printf("\t\tδ�ҵ���¼!\n");/*δ�ҵ�Ҫ���ҵ���Ϣ*/
     }
  else
	 {  printf("\n��ȷ��Ҫ�޸ĵ�����(y/n): ");
       scanf("%s",ch);
       if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)   
	   {    printf("\n����:"); 
	        scanf("%s",&stu[i].word);
	   }
      if((fp=fopen("data.txt","wb"))==NULL)
	   {   printf("��ʧ��\n");
	     return;
	   }
	for(i=0;i<k;i++)
	{ if(fwrite(&stu[i] ,LEN,1,fp)!=1)
		{ printf("����ʧ��!");}
		
	}

	printf("\t\t�޸ĳɹ���\n");
       fclose(fp);
   
   

   outputgrade();
  }
}
//ɾ����Ϣ
void del()
{  
   char c[10],ch[10];
   FILE *fp;
  int i,j,k=0;
  
  if((fp=fopen("data.txt","r+"))==NULL) 
     { printf("��ʧ��\n");return;}

  while(!feof(fp))//����ļ�����
  {
	  if(fread(&stu[k] ,LEN,1,fp)==1)
		  k++;/*ͳ�Ƶ�ǰ��¼����*/
  }
  fclose(fp);
  if(k==0) 
  {
	  printf("�޼�¼!\n");
	  return;
  }
  else
  {
   printf("\n������Ҫɾ���ĵ��� ��\n");
   printf("\t\t\t");
   scanf("%s",c);
   for(i=0;i<k;i++)
   {   if(strcmp(stu[i].word,c)==0) 
		  break;
       
   }
   if(i==k) 
	 { system("cls");
	  printf("\t\tδ�ҵ���¼!\n");/*δ�ҵ�Ҫ���ҵ���Ϣ*/
     }
   else
	{ printf("��ɾ�����Ƿ񱣴棨����������ȡ������ɾ��������?(y/n)");
    scanf("%s",ch);
  if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ����ɾ��*/
	{  for(j=i;j<k-1;j++)
	   { stu[j]=stu[j+1]; }
	}
  else 
	 { return; 
      system("cls");
	 }
    k--;
    if((fp=fopen("data.txt","wb"))==NULL)
     { printf("��ʧ��\n");return;}
    for(j=0;j<k;j++)/*�����ĺ�ļ�¼����д��ָ���Ĵ����ļ���*/
	{   
		if(fwrite(&stu[j] ,LEN,1,fp)!=1)
           printf("����ʧ��!\n");
	}
    fclose(fp);
   printf("\n���Ѿ�ɾ�� %s����Ϣ\n",c);

   
   outputgrade();
  }
  }
}



//ͳ�Ƶ��ʸ��� 
void count() //���ʲ� 
{   FILE *fp;
  int k=0;
  if((fp=fopen("data.txt","a+"))==NULL)
     { printf("��ʧ��\n");return;}
  while(!feof(fp))  
	{if(fread(&stu[k],LEN,1,fp)==1) 
		  k++;/*ͳ�Ƶ��ʸ���*/
	}
  if(k==0) {printf("û�м�¼!\n");}
	  
  system("cls");
  printf("\t\t\n");
  printf("\t\t���е��ʣ�%d\n",k);/*��ͳ�Ƶĸ������*/
  printf("\t\t\n");
  printf("\t\t\n");
  fclose(fp);
	
}

void search()/*�Զ�����Һ���*/
{ 
 int n;
  printf("��ѡ�񰴵��ʲ��һ��ǰ����Ĳ���\n1.���ʲ���\n2.�������\n");
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
     { printf("��ʧ��\n");return;}
  while(!feof(fp))  
  if(fread(&stu[k],LEN,1,fp)==1)
   k++;
  fclose(fp);
  if(k==0) {printf("û�м�¼!\n");return;}
  printf("����Ҫ���ҵĵ���:");
   scanf("%s",a);
  for(i=0;i<k;i++)
  
  {    if(compare(a,stu[i].word)==1);
  
         //if(strcmp(stu[i].word,a)==0)//����������Ƿ��ڼ�¼��
          break;
  }
   if(i==k) 
	  { system("cls");
	   printf("\t\tδ�ҵ�!\n");/*δ�ҵ�Ҫ���ҵ���Ϣ*/ 
       }
   else
   {
   system("cls");
   printf(" ������:\n");
   printf("���� ����  \n");
   printf("-------------------------------------\n");
   
   printf("%s %s\n",stu[i].word,stu[i].translate);
   
	printf("-------------------------------------\n");
   
   printf("�Ƿ��޸�?(y/n)");
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
     { printf("��ʧ��\n");return;}
  while(!feof(fp))  if(fread(&stu[k],LEN,1,fp)==1) k++;
  fclose(fp);
  if(k==0) {printf("û�м�¼!\n");return;}
  printf("����Ҫ���ҵķ���:");
   scanf("%s",a);
  for(i=0;i<k;i++)
  {   //if(compare(a,stu[i].translate)==1);   
  if(strcmp(stu[i].translate,a)==0)//��������ķ����Ƿ��ڼ�¼��
          //strcpy(&str[1][],a);//str=stu[i].word;//???
        {
		  
		  strcpy(str[k],stu[i].word);
		  k++;
		  
        }    /*
          vector<string> v;
          v.push_back(stu[i].word)//stu[i].wor����string�����޵кðɣ����У�ѹ�����Ƶ��ʳ��� 
	      */
          
   }
   if(str==0) 
	  { system("cls");
	   printf("\t\tδ�ҵ�!\n");/*δ�ҵ�Ҫ���ҵ���Ϣ*/ 
       }
   else
   {
   system("cls");
   printf(" ���ҵ���������:\n");
   printf("���� ����  \n");
   
   
   printf("-------------------------------------\n");
   for(i=0;i<k;i++)
   printf("%s\n",str[i]);
   //printf("%s %s\n",stu[i].word,stu[i].translate);
   
	printf("-------------------------------------\n");

   
   printf("�Ƿ��޸�?(y/n)");
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
