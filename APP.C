#include<graphics.h>
#include<stdio.h>
#include<conio.h>
int i=-1;
struct node
{
	int a;
	struct node *l;
};
struct node *h=NULL,*t,*d,*nw;
void push(int x)
{
int x1,y1,x2,y2,dis;
char str[5];
x1 = 470;
y1 = 50;
x2 = 570;
y2 = 450;
cleardevice();
setbkcolor(BLUE);
i++;
nw=(struct node*)malloc(sizeof(struct node));
nw->a=x;
nw->l=NULL;
if(h==NULL || t==NULL)
{
	h=t=nw;
}
else
{
	nw->l=t;
	t=nw;
}
	setbkcolor(BLUE);
	settextstyle(4,HORIZ_DIR,4);
	outtextxy(485,5,"Stack");
	gotoxy(1,1);
	dis=400/(i+1);
	y2=y2-(i*dis);
	d=t;
	while(d!=NULL)
	{
		rectangle(x1,y1,x2,y2);
		sprintf(str,"%d",d->a);
		settextstyle(3,HORIZ_DIR,2);
		outtextxy(510,((y1+y2)/2)-textheight(str)/2,str);
		y1=y2;
		y2=y2+dis;
		d=d->l;
	}
	delay(1000);
}
int pop()
{
int x=t->a,x1,y1,x2,y2,dis;
char str[5];
i--;
t=t->l;
x1 = 470, y1 = 50;
x2 = 570, y2 = 450;
cleardevice();
if(i<0)
{
	setbkcolor(BLUE);
	settextstyle(4,HORIZ_DIR,4);
	outtextxy(485,5,"Stack");
	rectangle(x1,y1,x2,y2);
}
else
{
	setbkcolor(BLUE);
	settextstyle(4,HORIZ_DIR,4);
	outtextxy(485,5,"Stack");
	gotoxy(1,1);
	dis=400/(i+1);
	y2=y2-(i*dis);
	d=t;
	while(d!=NULL)
	{
		rectangle(x1,y1,x2,y2);
		sprintf(str,"%d",d->a);
		settextstyle(3,HORIZ_DIR,2);
		outtextxy(510,((y1+y2)/2)-textheight(str)/2,str);
		y1=y2;
		y2=y2+dis;
		d=d->l;
	}
	delay(1000);
}
return x;
}
void bin()
{
	int x,j=-1;
	char s[50];
	printf("Enter decimal number:");
	scanf("%d",&x);
	while(x!=0)
	{
		push(x%2);
		x=x/2;
	}
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(50,50,"Pushed The Stack");
	delay(1500);
	while(i!=-1)
	{
		s[++j]=(char)(pop()+'0');
	}
	s[++j]='\0';
	settextstyle(4,HORIZ_DIR,4);
	outtextxy(30,405,"Binary:");
	outtextxy(130,405,s);
}
void fac()
{
	int x,f=1;
	char s[50];
	printf("Enter a number:");
	scanf("%d",&x);
	while(x!=0)
	{
		push(x--);
	}
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(50,50,"Pushed The Stack");
	delay(1500);
	while(i!=-1)
	{
		f=f*pop();
	}
	sprintf(s,"%d",f);
	settextstyle(4,HORIZ_DIR,4);
	outtextxy(30,405,"Factorial:");
	outtextxy(160,405,s);
}
void main()
{
    int gd = DETECT, gmode,ch,s;
    char str[20];
    clrscr();
    initgraph(&gd, &gmode, "c:\\turboc3\\bgi");
    setbkcolor(BLUE);
    settextstyle(4,HORIZ_DIR,4);
    outtextxy(485,5,"Stack");
    while(1)
    {
	printf("1.Factorial\n2.Decimal to Binary\n3.Quit\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		fac();
	}
	else if(ch==2)
	{
		bin();
	}
	else if(ch==3)
	{
		closegraph();
		exit(0);
	}
	else
	{
		printf("Enter valid input!\n");
	}

    }
}