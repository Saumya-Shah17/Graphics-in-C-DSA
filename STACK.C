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
void push()
{
i++;
nw=(struct node*)malloc(sizeof(struct node));
printf("Enter value to add:");
scanf("%d",&nw->a);
if(h==NULL)
{
	h=t=nw;
}
else
{
	nw->l=t;
	t=nw;
}
}
void pop()
{
i--;
t=t->l;
}
void main()
{
    int gd = DETECT, gmode,x1,y1,x2,y2,ch,s,dis;
    char str[20];
    clrscr();
    initgraph(&gd, &gmode, "c:\\turboc3\\bgi");
    setbkcolor(BLUE);
    while(1)
    {
	x1 = 470, y1 = 50;
	x2 = 570, y2 = 450;
	printf("1.Push\n2.Pop\n3.Quit\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		push();
	}
	else if(ch==2)
	{
		pop();
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
	cleardevice();
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
    }
}