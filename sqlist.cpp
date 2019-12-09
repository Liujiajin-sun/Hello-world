#include <stdio.h>
#include <stdlib.h>
#define LIST_INTSIZE 50
typedef char DataType;             /*在此例中数据类型采用字符类型*/
   

typedef  struct {   DataType*  elem;                    /*线性表的基地址*/
			int  length;						/*线性表当前的长度*/
			int  listsize;						/*线性表当前分配的存储容量*/
		} SeqList;   

SeqList L;
int InitSeqList(SeqList* L)
{ 
	L->elem=(DataType *)malloc((LIST_INTSIZE+1)*sizeof(DataType));  /*数组的0元素没有使用*/
	if (L->elem==NULL)
	{
		printf("\t\t\t内存分配错误\n");
		return 0;
	}
	L->length=0;
	L->listsize=LIST_INTSIZE;
	printf("\t\t\t内存分配成功\n");
	return 1;
}

int  InsertSeqList(SeqList* L, int i, DataType x)
{   
	int j=0; 
//		printf("i=%d\n", i);
    if (L->length==LIST_INTSIZE)							/*顺序表已满，不能插入*/
    {   
		printf("%d\n",L->length);
		printf("%d\n",L->listsize);
		printf("\t\t\t顺序表已满!\n"); 
		return 0; 
    }  	
    else
    {
		if(i<1 || i>L->length+1)					/*检查插入位置的合法性*/				
        {   
		    printf("\t\t\t位置不合法!");
			return 0;
		} 
        else
		{
	            for(j=L->length;j>=i;j--)				/*顺序移动元素*/
        	    {     
			L->elem[j+1]=L->elem[j];  
	  	    }
			L->elem[i]=x;                            	/*新元素插入*/				
        	    L->length++;					/*表长加一*/
			return 1;/*插入成功，返回*/
		}
	}
}


int DeleteSeqList(SeqList* L, int i)
{
	int  j;
    if(i<1 || i>L->length)   					       /*检查删除位置的合法性*/
    { 
		printf ("不存在第i个元素!\n"); 
		return 0; 
	}
    else
	{
		for(j=i;j<L->length;j++)					/*向上顺序移动元素*/
			L->elem[j]=L->elem[j+1]; 
		L->length--;   							/*表长减一*/ 
		return 1;   						         /*删除成功*/
     }
}

int LenSeqList(SeqList* L)
/* 返回顺序表Ｌ的长度*/
{	
  return  L->length;
}

int SearchSeqList(SeqList* L, DataType y)
/*在线性表中查找值为ｘ的数据元素*/
{
	for(int m=0; m<L->length; m++)
	{	if(L->elem[m+1]==y)
	{	printf("\n\t\t\t查到此数，在表中位置是%d\n",m+1);
	return 1;}
}
	printf("\n\t\t\t查无此数\n");
	
	return 0;
}

char GetfromSeqList(SeqList* L, int i)
/*返回线性表中的第ｉ个元素的值*/
{

	printf("%d",i);
	if(i<1 || i>L->length)
	{
		printf("输入非法位置");
		return false;
	}
	else
	{
		return L->elem[i];
	}
}

void ShowSeqList(SeqList* L)
{	int i;
	printf("\n\t\t\t显示当前线性表的所有元素：");
	if(L->length==0)
		printf("\n\t\t\t线性表为空!\n");
	else
	{
		printf("\n\t\t");
		for(i=1;i<=L->length;i++)
		{	printf("\t%c",L->elem[i]);
		}
	}
}

void Initialization()
{
  //在屏幕上方显示操作命令清单：
	printf("\n\n\n\n");
	printf("\t\t\t--线 性 顺 序 表--\n");
	printf("\n\t\t\t************************************");
	printf("\n\t\t\t*       1-------顺序表初始化       *");
	printf("\n\t\t\t*       2-------插      入         *");
	printf("\n\t\t\t*       3-------删      除         *");
	printf("\n\t\t\t*       4-------求  表  长         *");
	printf("\n\t\t\t*       5-------按 值 查找         *");
	printf("\n\t\t\t*       6-------读取元素值         *");
	printf("\n\t\t\t*       7-------显示线性表         *");
	printf("\n\t\t\t*       0-------退      出         *");
	printf("\n\t\t\t************************************\n");
	printf("\t\t\t请选择菜单号(0--7)：");
  
}//Initialization

char ReadCommand(char cmd)
{
   //读入操作命令符
   //显示键入操作命令符的提示信息
   do{ cmd=getchar();
	}while(cmd!='1'&&cmd!='2'&&cmd!='3'&&cmd!='4'&&cmd!='5'&&cmd!='6'&&cmd!='7'&&cmd!='0');
   return cmd;
}

void Interpret(char cmd)
{
    int i=0;
	int j=1;

	DataType x=' ';
	DataType y=' ';

	//解释执行操作命令 cmd
  switch(cmd){
   case '1': //初始化；
   		  InitSeqList(&L);
          break;
  case '2': //插入；
		  printf("\n\t\t\t请输入的位置i和数值x(输入格式：i, x):");
		  scanf("%d,%c",&i,&x);
		  InsertSeqList(&L, i, x);
	  	  ShowSeqList(&L);
          break;
  case '3': //删除
	      printf("\n\t\t\t请输入要删除元素的位序: ");
		  scanf("%d",&i);
		  DeleteSeqList(&L, i);
     	  ShowSeqList(&L);
		  break;
  case '4'://求长度
		  printf("\n\t\t\t所求表长是：\n");
		  printf("\n\t\t\t%d\n",LenSeqList(&L));
		  ShowSeqList(&L);
		  break;
  case '5': //检索
		  printf("\n\t\t\t输入所查元素值: ");
		  getchar();//消耗掉\n
		  scanf("%c",&y);
	      SearchSeqList(&L, y);
   	  	  ShowSeqList(&L);
	      break;
  case '6'://获取某位置的数据元素
		  printf("\n\t\t\t输入数据元素所在位置: ");
		  getchar();
		  scanf("%d",&i);    
		  printf("\n\t\t\t顺序表第%d个位置的数据元素是%c",i,GetfromSeqList(&L, i));
  	  	  ShowSeqList(&L);
		  break;
  case '7': //显示线性表
	  	  ShowSeqList(&L);
	      break;
  }
}//Interpret

//主函数
int main()
{
  char cmd;
  Initialization(); //初始化
  do{
      cmd=ReadCommand(cmd); //读入一个操作命令符
      Interpret(cmd);  //解释执行操作命令符
      if(cmd!='0')
		  printf("\n\t\t\t请选择命令代码：");
  }while(cmd!='0');
  return 0;
}//main
