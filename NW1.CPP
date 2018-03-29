#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<iomanip.h>

int level=0,life,maxx,maxy,ck=0,bt,cx,cy,blcol,brcol,x,l,y,t,bgcol,bcol,x1,y1,xm2,ym2,xm1,ym1,xl1,xl2,yl1,yl2,speed;
char c1,c2,ch1,ch2;
float m1,m2;
char g[]={"VIRTUAL TENNIS"},w[][20]={"1. Begin Game","2. Select Level","3. Settings","4. Exit"};

void startgame();
void movebar();
void setvalues();
void border();
void checkball();
void set();
void welcome();
void wpage();
void settings();
void levels();
void scrcrd();

void main()
{
  clrscr();
  int gd=DETECT,gm;
  initgraph(& gd,&gm,"");
  setvalues();
  welcome();
  wpage();
}

void welcome()
{
  setfillstyle(SOLID_FILL,4);
  bar(0,0,getmaxx(),20);
  bar(0,20,20,getmaxy());
  bar(20,getmaxy()-20,getmaxx(),getmaxy());
  bar(getmaxx()-20,20,getmaxx(),getmaxy()-20);
  setfillstyle(SOLID_FILL,8);
  bar(25,25,getmaxx()-25,30);
  bar(25,25,30,getmaxy()-25);
  bar(25,getmaxy()-25,getmaxx()-25,getmaxy()-30);
  bar(getmaxx()-30,25,getmaxx()-25,getmaxy()-25);
}

void levels()
{
   /*char lv[]={"!! Levels under construction :) !!"};
   settextstyle(7,HORIZ_DIR,3);
   setcolor(8);
   outtextxy((getmaxx()-textwidth(lv))/2,getmaxy()/2-50,lv);
   char ch1;
   while(ch1!=13&&ch1!=27)
   {
     ch1=getch();
   }        */

   cleardevice();
   wpage();
}

void scrcrd()
{
  setcolor(4);
  outtextxy(bt+40,maxy+15,"SCORE");
  setfillstyle(SOLID_FILL,11);
  bar(bt,maxy+5,maxx,getmaxy()-5);
  settextstyle(8,HORIZ_DIR,2);
  setcolor(4);
  outtextxy(bt+40,maxy+15,"SCORE");

}

void settings()
{

  char st[]={"SETTINGS"};
  cleardevice();
  welcome();
  settextstyle(4,HORIZ_DIR,6);
  setcolor(12);
  outtextxy((getmaxx()-textwidth(st))/2,70,st);
  settextstyle(7,HORIZ_DIR,3);
  setcolor(8);
  outtextxy((getmaxx()-textwidth("Loading. . . Please wait :)"))/2,getmaxy()/2-50,"Loading. . . Please wait :)");
  char ch1;
  while(ch1!=13&&ch1!=27)
  {
    ch1=getch();
  }
  cleardevice();
  wpage();
}
void wpage()
{
  welcome();
  int chck=1,in=0;
  settextstyle(4,HORIZ_DIR,6);
  setcolor(12);
  outtextxy((getmaxx()-textwidth(g))/2,70,g);
  settextstyle(7,HORIZ_DIR,3);
  setcolor(15);
  outtextxy((getmaxx()-textwidth(w[in]))/2,150+50,w[in]);
  in++;
  setcolor(8);
  outtextxy((getmaxx()-textwidth(w[in]))/2,150+50+40,w[in]);
  in++;
  outtextxy((getmaxx()-textwidth(w[in]))/2,150+50+80,w[in]);
  in++;
  outtextxy((getmaxx()-textwidth(w[in]))/2,150+50+120,w[in]);
  in=0;
  int a=0;
  while(1)
  {
    ch1=getch();
    if(ch1==0)
    {
     settextstyle(7,HORIZ_DIR,3);
     ch2=getch();
     if(ch2==72)
     {
       setcolor(8);
       outtextxy((getmaxx()-textwidth(w[in]))/2,150+50+40*(in),w[in]);
       if(in!=0)
	 in--;
       else
	 in=3;
       setcolor(15);
       outtextxy((getmaxx()-textwidth(w[in]))/2,150+50+40*(in),w[in]);
     }
     if(ch2==80)
     {
       setcolor(8);
       outtextxy((getmaxx()-textwidth(w[in]))/2,150+50+40*(in),w[in]);
       if(in!=3)
	 in++;
       else
	 in=0;
       setcolor(15);
       outtextxy((getmaxx()-textwidth(w[in]))/2,150+50+40*(in),w[in]);
     }
    }
    if(ch1==13)
     break;
  }
  if(in==0)
  {
    cleardevice();
    border();
    startgame();
  }
  if(in==1)
  {
   cleardevice();
   welcome();
   levels();
  }
  if(in==2)
  {
    settings();
  }
  if(in==3)
    exit(0);
}

void setvalues()
{
  level=1;
  life=5;
  maxx=getmaxx()-20;
  maxy=getmaxy()-100;
  xm1=maxx-50;
  ym1=50;
  xm2=50;
  ym2=maxy-50;
  y=maxy/2;
  cx=maxx-20;
  speed=3;
  l=70;
  m1=-1.0;
  x1=getmaxx()-50;
  y1=50;
  bgcol=0;
  bcol=8;
  t=20;
  bt=20;
  blcol=14;
  brcol=9;
}
void border()
{
  setfillstyle(1,brcol);
  bar(0,0,getmaxx(),bt);
  bar(0,0,bt,getmaxy());
  bar(0,maxy,getmaxx(),getmaxy());
  bar(maxx,0,getmaxx(),getmaxy());
}

void movebar()
{
     c2=getch();
     if(c2==80&&y+l+2<maxy-10)
     {
      setfillstyle(1,bgcol);
      bar(25,y,25+t,y+l);
      y=y+10;
      setfillstyle(1,bcol);
      bar(25,y,25+t,y+l);
     }
     if(c2==72&&y>bt+2+7)
     {
      setfillstyle(1,bgcol);
      bar(25,y,25+t,y+l);
      y=y-10;
      setfillstyle(1,bcol);
      bar(25,y,25+t,y+l);
     }
}

void startgame()
{
  while(1)
  {
    if(kbhit())
    {
      c1=getch();
      if(c1==0)
	movebar();
      if(c1==13)
	break;
    }
    setfillstyle(1,bcol);
    bar(25,y,25+t,y+70);
    setfillstyle(1,bgcol);
    setcolor(bgcol);
    cy=1.0*m1*(cx-x1)+y1;
    fillellipse(cx,cy,10,10);
    checkball();
    if(m1>1.5)
      m1=1;
    if(m1<-1.5)
      m1=-1;
    if(ck==1)
      cx++;
    if(ck==0)
      cx--;
    setfillstyle(1,blcol);
    setcolor(blcol);
    cy=m1*(cx-x1)+y1;
    fillellipse(cx,cy,10,10);
    scrcrd();
    delay(speed);
  }
}

void checkball()
{
    int mr=rand()%5;
    if(cx==25+t+2+10&&cy>y&&cy<y+l)
    {
      m1=-m1+mr*0.1;
      ck=1;
      set();
    }
    else if(cx<25+t+10+2&&cx>25+t+2&&cy>y-10&&cy<y)
    {
      m1=m1-1+mr*0.1;
      ck=1;
      set();
    }
    else if(cx<25+t+10+2&&cx>25+t+2&&cy<y+l+10&&cy>y+l)
    {
      m1=-(m1-1)+mr*0.1;
      ck=1;
      set();
    }
    else if(cy+10+2>=maxy)
    {
      m1=-m1+mr*0.1;
      set();
    }
    else if(cy<=bt+10+2)
    {
      m1=-m1+mr*0.1;
      set();
      y1=cy+3;
    }
    else if(cx+10+2>=maxx)
    {
      m1=-m1+mr*0.1;
      ck=0;
      set();
    }
    else if(cx<=bt+10+2)
    {
      delay(500);
      exit(0);
    }
}

void set()
{
  x1=cx;
  y1=cy;
}