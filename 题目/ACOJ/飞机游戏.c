#include "stdio.h"
#include <windows.h>
#include <conio.h>
#include <time.h>
#define Esc 27 //�˳�
#define Up 72 //�ϣ��£�����
#define Down 80
#define Left 75
#define Right 77
#define Kong 32 //�����ӵ�
int x=10; //�ɻ�����
int y=18;
int d2=10;//�л�����
int d1=10; 
int d=10;
int r=1;
int r1=1;
int r2=1;
int t=1; // ��Ϸ����
int f=0; // �Ʒ���
int m=3; // �л���
int j=0; // �ߵ���
char p; // ���ܰ���
void kongzhi(int bx,int by);//��������
void huatu();
void gotoxy(int x,int y) //�ƶ�����
{
COORD coord;
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void hidden()//���ع��
{
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cci;
GetConsoleCursorInfo(hOut,&cci);
cci.bVisible=0;//��1Ϊ��ʾ����0Ϊ����
SetConsoleCursorInfo(hOut,&cci);
}
//**************************************************************************************
//˵��
void shuoming() 
{
printf("\t\t\t\n\n\n\n");
printf("\t\t\t�������\n\n"
"\t\t\t�� ��\n\n"
"\t\t\t�� ��\n\n"
"\t\t\t�� ��\n\n"
"\t\t\t�� ��\n\n"
"\t\t\t�ӵ� �ո�\n\n\n"
"\t\t\t�˳��밴 ESC\n");
gotoxy(0,0); 
}
//****************************************************************************************
//�ж��һ���û��/��Ϸ����
void byebye()
{
if((x==d&&y==r)||(x==d1&&y==r1)||(x==d2&&y==r2))
{ gotoxy(1,3);
printf(" !!! ��Ϸ���� !!!\n"
"*******************\n"
" �����ܵ÷�: %d\n\n"
" �л���: %d\n"
" �ߵ���: %d\n"
" ������: %.0f %%\n"
"*******************\n",f,m,j,((float)j/(float)m)*100);
while(!kbhit()) 
{ Sleep(500);
gotoxy(1,12);
printf(" �����밴�����...\n\n\n");
Sleep(900); 
gotoxy(1,12); 
printf(" ");
}
gotoxy(0,0);
huatu(); 
f=0; m=0; j=0;
if(x>=18) x--;
else x++;
gotoxy(x,y);
printf("��");
}
}
// �Ʒ�/���µл�
void jifan()
{ 
if(x==d&&y==r)
{ gotoxy(d,r); printf("3");
Sleep(200);
gotoxy(d,r); printf(" "); f+=2; r=0; j++;}
if(x==d1&&y==r1)
{ gotoxy(d1,r1); printf("1");
Sleep(200);
gotoxy(d1,r1); printf(" "); f+=3; r1=0; j++;}
if(x==d2&&y==r2)
{ gotoxy(d2,r2); printf("0");
Sleep(200);
gotoxy(d2,r2); printf(" "); f+=1; r2=0; j++;}
gotoxy(26,2);
printf(" %d \n",f);
}
//��ͼ
void huatu()
{ int i,n;

for(i=0;i<=20;i++)
{
for(n=0;n<=20;n++)
{
printf("*");
} 
printf("\n");
}
for(i=1;i<=19;i++)
{
for(n=1;n<=19;n++)
{
gotoxy(i,n);
printf(" ");
}
}
}
//��������л�
void dfeiji ()
{ 
while(t)
{
if(!r) {d=rand()%17+1; m++;}
if(!r1) {d1=rand()%17+1; m++;}
if(!r2) {d2=rand()%17+1; m++;}
while(t)
{ r++; r1++; r2++;
gotoxy(d,r); printf("��");
gotoxy(d1,r1); printf("��");
gotoxy(d2,r2); printf("��");
Sleep(900);
gotoxy(d,r); printf(" ");
gotoxy(d1,r1); printf(" ");
gotoxy(d2,r2); printf(" ");
kongzhi(0,0);
byebye();
if(r==18) r=0;
if(r1==18) r1=0;
if(r2==18) r2=0;
if(r==0||r1==0||r2==0) break; 
}
}
}
//�ٿطɻ�
void kongzhi(int bx,int by)
{
int a;
while (kbhit())
{if ((p=getch())==-32) p=getch();
a=p;
gotoxy(22,5);
switch(a)
{//���Ʒ���
case Up:if (y!=1)
{ gotoxy(x,y); printf(" ");
y--; 
gotoxy(x,y); printf("��");
}break;
case Down:if (y!=18)
{ gotoxy(x,y); printf(" ");
y++;
gotoxy(x,y); printf("��");
}break;
case Left:if (x!=1)
{ gotoxy(x,y); printf(" ");
x--;
gotoxy(x,y); printf("��");
}break;
case Right:if (x!=18)
{ gotoxy(x,y); printf(" ");
x++;
gotoxy(x,y); printf("��");
}break;
case Kong:{ bx=y;
for(by=y;by>1;) //�����ӵ�
{ by--;
gotoxy(x,by); printf("��");
Sleep(10);
gotoxy(x,by); printf(" ");
y=by;
jifan();
if(r==0||r1==0||r2==0) break;
}
y=bx;
}break;
case Esc:t=0; break; //�˳�
default:break;
}
}
}
int main()
{
srand(time(NULL));
shuoming();
hidden();
huatu();
gotoxy(x,y);
printf("��");
gotoxy(22,2);
printf("����:");
while (t)
{ kongzhi(0,0);
if(t)
dfeiji ();
}
}
