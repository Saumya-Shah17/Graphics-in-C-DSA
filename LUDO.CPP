#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void dda(int x1,int y1,int x2,int y2)
{
    float i=x1,j=y1,m=(float)(y2-y1)/(x2-x1),inx,iny;
    int lim=x2-x1;
    int k=0;
    if(m==1)
	inx=iny=1;
    else if(m>1)
    {
	inx=1/m;
	iny=1;
    }
    else
    {
	inx=1;
	iny=m;
    }
    for(k=0;k<lim;k++)
    {
	putpixel(i,j,8);
	i=i+inx;
	j=j+iny;
    }
}
void bcir(int x,int y,int r,int c)
{
    int i=0,j=r,p=3-2*r;
    while(i<=j)
    {
	putpixel(x+i,y+j,c);
	putpixel(x-i,y-j,c);
	putpixel(x+j,y+i,c);
	putpixel(x-j,y-i,c);
	putpixel(x-i,y+j,c);
	putpixel(x+i,y-j,c);
	putpixel(x-j,y+i,c);
	putpixel(x+j,y-i,c);
	if(p<0)
	{
	    i++;
	    p=p+4*i+6;
	}
	else
	{
	    i++;
	    j--;
	    p=p+4*(i-j)+10;
	}
    }
}
void ln(int x1,int y1,int x2,int y2)
{
    int p,dx=x2-x1,dy=y2-y1,j,lim=y2-y1,k,i;
    p=2*dy-dx;
    i=x1;
    j=y1;

    for(k=0;k<lim;k++)
    {
	putpixel(i,j,8);
	if(x2-x1==0)
	{
	    j++;
	}
	else
	{
		if(p>=0)
		{
		p=p+2*dy-2*dx;
		i++;
		j++;
		}
		else
		{
		p=p+2*dy;
		i++;
		}
	}
	}
}

void mcir(int x,int y,int r,int c)
{
    int p=1-r,i,j;
    i=0;
    j=r;
    while(i<=j)
    {
	putpixel(x+i,y+j,c);
	putpixel(x+j,y+i,c);
	putpixel(x-j,y+i,c);
	putpixel(x+j,y-i,c);
	putpixel(x-i,y-j,c);
	putpixel(x-j,y-i,c);
	putpixel(x-i,y+j,c);
	putpixel(x+i,y-j,c);
	if(p<0)
	{
	    i++;
	    p=p+2*i+1;
	}
	else
	{
	    i++;
	    j--;
	    p=p-2*j+2*i+1;
	}
    }
}
int main()
{
    int gd=DETECT,gm,tx,ty,i;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");

    setbkcolor(WHITE);

    //Big Square
    dda(100,20,540,20);
    dda(100,460,540,460);
    ln(100,20,100,460);
    ln(540,20,540,460);

    //First Square
    dda(100,195,275,195);
    ln(275,20,275,195);
    bcir(144,64,30,8);
    bcir(229,64,30,8);
    bcir(144,149,30,8);
    bcir(229,149,30,8);
    setfillstyle(SOLID_FILL,RED);
    floodfill(101,21,8);


    //Second Square
    dda(365,195,540,195);
    ln(365,20,365,195);
    bcir(408,64,30,8);
    bcir(493,64,30,8);
    bcir(408,149,30,8);
    bcir(493,149,30,8);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(366,21,8);

    //Third Square
    dda(100,285,275,285);
    ln(275,285,275,460);
    bcir(144,328,30,8);
    bcir(229,328,30,8);
    bcir(144,413,30,8);
    bcir(229,413,30,8);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(101,286,8);

    //Fourth Square
    dda(365,285,540,285);
    ln(365,285,365,460);
    bcir(408,328,30,8);
    bcir(493,328,30,8);
    bcir(408,413,30,8);
    bcir(493,413,30,8);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(366,286,8);

    //Mid Square
    dda(275,195,365,195);
    dda(275,285,365,285);
    ln(275,195,275,365);
    ln(365,195,365,365);
    //Cross Line
    ln(275,195,365,285);
    dda(275,285,365,195);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(360,270,8);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(360,284,8);
    setfillstyle(SOLID_FILL,RED);
    floodfill(280,270,8);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(360,196,8);

    //Top Rect
    ln(305,20,305,195);
    ln(335,20,335,195);
    ty=49;
    tx=275;
    for(i=0;i<5;i++)
    {
    dda(tx,ty,tx+90,ty);
    ty=ty+29;
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(tx+31,ty,8);
    }
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(336,50,8);
    mcir(350,64,10,WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(350,64,WHITE);
    mcir(319,35,8,8);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(319,35,8);
    floodfill(276,102,8);

    //Bot Rect
    ln(305,285,305,460);
    ln(335,285,335,460);
    ty=315;
    tx=275;
    for(i=0;i<5;i++)
    {
    dda(tx,ty,tx+90,ty);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(tx+31,ty-1,8);
    ty=ty+29;
    }
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(276,429,8);
    mcir(290,415,10,WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(290,415,WHITE);
    mcir(319,445,8,8);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(319,445,8);
    floodfill(336,400,8);

    //Left Rect
    dda(100,225,275,225);
    dda(100,255,275,255);
    ty=195;
    tx=129;
    for(i=0;i<5;i++)
    {
    ln(tx,ty,tx,ty+90);
    tx=tx+29;
    setfillstyle(SOLID_FILL,RED);
    floodfill(tx,ty+31,8);
    }
    setfillstyle(SOLID_FILL,RED);
    floodfill(132,196,8);
    mcir(144,210,10,WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(144,210,WHITE);
    mcir(115,240,8,8);
    setfillstyle(SOLID_FILL,RED);
    floodfill(115,240,8);
    floodfill(165,256,8);

    //Right Rect
    dda(365,225,540,225);
    dda(365,255,540,255);
    ty=195;
    tx=395;
    for(i=0;i<5;i++)
    {
    ln(tx,ty,tx,ty+90);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(tx-1,ty+31,8);
    tx=tx+29;
    }
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(489,256,8);
    mcir(495,270,10,WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(495,270,WHITE);
    mcir(525,240,8,8);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(525,240,8);
    floodfill(480,196,8);

    getch();
    closegraph();
    return 0;

}


