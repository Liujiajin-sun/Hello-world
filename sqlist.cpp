#include <stdio.h>
#include <stdlib.h>
#define LIST_INTSIZE 50
typedef char DataType;             /*�ڴ������������Ͳ����ַ�����*/
   

typedef  struct {   DataType*  elem;                    /*���Ա�Ļ���ַ*/
			int  length;						/*���Ա�ǰ�ĳ���*/
			int  listsize;						/*���Ա�ǰ����Ĵ洢����*/
		} SeqList;   

SeqList L;
int InitSeqList(SeqList* L)
{ 
	L->elem=(DataType *)malloc((LIST_INTSIZE+1)*sizeof(DataType));  /*�����0Ԫ��û��ʹ��*/
	if (L->elem==NULL)
	{
		printf("\t\t\t�ڴ�������\n");
		return 0;
	}
	L->length=0;
	L->listsize=LIST_INTSIZE;
	printf("\t\t\t�ڴ����ɹ�\n");
	return 1;
}

int  InsertSeqList(SeqList* L, int i, DataType x)
{   
	int j=0; 
//		printf("i=%d\n", i);
    if (L->length==LIST_INTSIZE)							/*˳������������ܲ���*/
    {   
		printf("%d\n",L->length);
		printf("%d\n",L->listsize);
		printf("\t\t\t˳�������!\n"); 
		return 0; 
    }  	
    else
    {
		if(i<1 || i>L->length+1)					/*������λ�õĺϷ���*/				
        {   
		    printf("\t\t\tλ�ò��Ϸ�!");
			return 0;
		} 
        else
		{
	            for(j=L->length;j>=i;j--)				/*˳���ƶ�Ԫ��*/
        	    {     
			L->elem[j+1]=L->elem[j];  
	  	    }
			L->elem[i]=x;                            	/*��Ԫ�ز���*/				
        	    L->length++;					/*����һ*/
			return 1;/*����ɹ�������*/
		}
	}
}


int DeleteSeqList(SeqList* L, int i)
{
	int  j;
    if(i<1 || i>L->length)   					       /*���ɾ��λ�õĺϷ���*/
    { 
		printf ("�����ڵ�i��Ԫ��!\n"); 
		return 0; 
	}
    else
	{
		for(j=i;j<L->length;j++)					/*����˳���ƶ�Ԫ��*/
			L->elem[j]=L->elem[j+1]; 
		L->length--;   							/*����һ*/ 
		return 1;      						         /*ɾ���ɹ�*/
     }
}

int LenSeqList(SeqList* L)
/* ����˳���̵ĳ���*/
{	
  return  L->length;
}

int SearchSeqList(SeqList* L, DataType y)
/*�����Ա��в���ֵΪ��������Ԫ��*/
{
	for(int m=0; m<L->length; m++)
	{	if(L->elem[m+1]==y)
	{	printf("\n\t\t\t�鵽�������ڱ���λ����%d\n",m+1);
	return 1;}
}
	printf("\n\t\t\t���޴���\n");
	
	return 0;
}

char GetfromSeqList(SeqList* L, int i)
/*�������Ա��еĵڣ��Ԫ�ص�ֵ*/
{

	printf("%d",i);
	if(i<1 || i>L->length)
	{
		printf("����Ƿ�λ��");
		return false;
	}
	else
	{
		return L->elem[i];
	}
}

void ShowSeqList(SeqList* L)
{	int i;
	printf("\n\t\t\t��ʾ��ǰ���Ա������Ԫ�أ�");
	if(L->length==0)
		printf("\n\t\t\t���Ա�Ϊ��!\n");
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
  //����Ļ�Ϸ���ʾ���������嵥��
	printf("\n\n\n\n");
	printf("\t\t\t--�� �� ˳ �� ��--\n");
	printf("\n\t\t\t************************************");
	printf("\n\t\t\t*       1-------˳����ʼ��       *");
	printf("\n\t\t\t*       2-------��      ��         *");
	printf("\n\t\t\t*       3-------ɾ      ��         *");
	printf("\n\t\t\t*       4-------��  ��  ��         *");
	printf("\n\t\t\t*       5-------�� ֵ ����         *");
	printf("\n\t\t\t*       6-------��ȡԪ��ֵ         *");
	printf("\n\t\t\t*       7-------��ʾ���Ա�         *");
	printf("\n\t\t\t*       0-------��      ��         *");
	printf("\n\t\t\t************************************\n");
	printf("\t\t\t��ѡ��˵���(0--7)��");
  
}//Initialization

char ReadCommand(char cmd)
{
   //������������
   //��ʾ����������������ʾ��Ϣ
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

	//����ִ�в������� cmd
  switch(cmd){
   case '1': //��ʼ����
   		  InitSeqList(&L);
          break;
  case '2': //���룻
		  printf("\n\t\t\t�������λ��i����ֵx(�����ʽ��i, x):");
		  scanf("%d,%c",&i,&x);
		  InsertSeqList(&L, i, x);
	  	  ShowSeqList(&L);
          break;
  case '3': //ɾ��
	      printf("\n\t\t\t������Ҫɾ��Ԫ�ص�λ��: ");
		  scanf("%d",&i);
		  DeleteSeqList(&L, i);
     	  ShowSeqList(&L);
		  break;
  case '4'://�󳤶�
		  printf("\n\t\t\t������ǣ�\n");
		  printf("\n\t\t\t%d\n",LenSeqList(&L));
		  ShowSeqList(&L);
		  break;
  case '5': //����
		  printf("\n\t\t\t��������Ԫ��ֵ: ");
		  getchar();//���ĵ�\n
		  scanf("%c",&y);
	      SearchSeqList(&L, y);
   	  	  ShowSeqList(&L);
	      break;
  case '6'://��ȡĳλ�õ�����Ԫ��
		  printf("\n\t\t\t��������Ԫ������λ��: ");
		  getchar();
		  scanf("%d",&i);    
		  printf("\n\t\t\t˳����%d��λ�õ�����Ԫ����%c",i,GetfromSeqList(&L, i));
  	  	  ShowSeqList(&L);
		  break;
  case '7': //��ʾ���Ա�
	  	  ShowSeqList(&L);
	      break;
  }
}//Interpret

//������
int main()
{
  char cmd;
  Initialization(); //��ʼ��
  do{
      cmd=ReadCommand(cmd); //����һ�����������
      Interpret(cmd);  //����ִ�в��������
      if(cmd!='0')
		  printf("\n\t\t\t��ѡ��������룺");
  }while(cmd!='0');
  return 0;
}//main
