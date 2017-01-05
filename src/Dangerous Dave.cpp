#include<graphics.h>
#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<ctype.h>
#include<bios.h>
#include<stdlib.h>     //randomize
#include<fstream.h>
#include<string.h>
#include<time.h>
#define GRAPHPATH"D:\TC:\BGI"

void esckey2();
void readx();
void bomb(int,int);
void load();
void story();
void checkcoin2();
int flag1=1,flag2=0;
void checkcoin();
int legflag=0;
void highscore();
void endscreen();
int game=1;
int key1=0,key2=0;
double score;
int eog1();
int eog2();
int eog2b();
int eog2c();
int movement2b();
int movement2c();
void plot2();
void plot2b();
void plot2c();
//int lives=3;
int level=1;
void grav2();
void instructions();
void controls();
void checkkb(int k);
void drawgem1();
int movement1();
int movement2();
int diff=1;
int up=18432;
int down=20480;
int left=19200;
int right=19712;          //controls
int pointer1=100;        //left pointer level1
int pointer2=380;      //top pointer   level1
// int pointer2=220;      //level2
// int pointer2=400;       // level3
// int pointer1=140;       // level3
int oldpt1=100;
int oldpt2=380;
void updatept();
void gravityup();

void SetupGraphics()
{
int gdriver=DETECT,gmode,error;
initgraph(&gdriver,&gmode,GRAPHPATH);
if((error=graphresult())!=grOk)//check for error
{
fprintf(stderr,"Graphics Error!%$\n",grapherrormsg(error));
exit(-1);
}//exit when error
}

struct coin
{
 int pointerx,pointery,knt;
 void plot(int x,int y)
 {
   setfillstyle(CLOSE_DOT_FILL,YELLOW);
   setcolor(YELLOW);
   pieslice(x,y,0,360,10);
 }
 void init(int x,int y)
 {
  pointerx=x;
  pointery=y;
 }
};

  coin coinx[10]={{100,200,0},{200,200,0},{300,200,0},{400,200,0},{540,200,0},{260,120,0},{160,120,0},{460,120,0}};
  coin coiny[]={{200,100,0},{100,160,0},{320,180,0},{400,280,0},
		{460,140,0},{560,220,0},{140,240,0}};
/*  coinx[0].init(100,200);
 coinx[1].init(200,200);
 coinx[2].init(300,200);
 coinx[3].init(400,200);
 coinx[4].init(540,200);
 coinx[5].init(260,120);
 coinx[6].init(160,120);
 coinx[7].init(460,120);     */
void drawlvl1() //level 1
{
cleardevice();
setbkcolor(BLACK);//set up colors
setcolor(BLACK);
setpalette(BLACK,0);
setfillstyle(XHATCH_FILL,RED);
setcolor(LIGHTBLUE);
  bar(600,80,40,40); //bar(left1,top1,left2,top2)
  bar(80,440,40,40);
  bar(600,440,80,400);
  bar(560,80,600,440); //border over
  bar(340,340,380,400);
  bar(340,300,520,340);
  bar(520,220,580,260);
  bar(80,220,120,260);
  bar(180,220,220,260);
  bar(280,220,320,260);
  bar(380,220,420,260);
  bar(140,140,180,180);
  bar(240,140,280,180);
  bar(340,140,380,180);
  bar(440,140,480,180);
  bar(140,320,300,360);
  char x[100]="SCORE:";

  char y[100]="LIVES:";
  char z[100]="0";
  char x1[100]="1";
  char x2[100]="2";
  char x3[100]="3";
/*  char x4[100]="1000";
  char x5[100]="2000";
  char x6[100]="3000";
  char x7[100]="4000";  */
  char x4[100];
  ultoa(score,x4,10);
  setcolor(GREEN);
  settextstyle(4,0,4);
  outtextxy(50,0,x);
/*  if(key1==0)
  outtextxy(200,0,z);   */
  outtextxy(200,0,x4);
  if((key1==1)&&(flag1==1))
 {
  score+=10000;
  flag1=0;
 }//outtextxy(200,0,x4);
/*  outtextxy(350,0,y);
  outtextxy(480,0,x1);
 /* for(int i=0;i<40;i++)
 for(int j=0;j<30;j++)
 rectangle(20*i,20*j,20,20);  */
 if(key1==0)
 { setcolor(YELLOW);
   setfillstyle(SOLID_FILL,YELLOW);
   circle(350,120,12);
   bar(362,116,380,124);
 }
 setfillstyle(INTERLEAVE_FILL,BROWN);
 bar(380,340,420,400);
 setfillstyle(SOLID_FILL,YELLOW);
 bar(410,366,420,376);
}

void drawlvl2()
{
 cleardevice();
 setbkcolor(BLACK);//set up colors
 setcolor(LIGHTBLUE);
 setpalette(BLACK,0);
 setfillstyle(XHATCH_FILL,RED);
  bar(600,80,40,40); //bar(left1,top1,left2,top2)
  bar(80,440,40,40);
  bar(80,420,120,440);
  bar(140,340,240,380);
  bar(120,260,200,300);
  bar(80,180,120,220);
  bar(160,120,240+40,160);
  bar(280,200,380,240);
  bar(310,260,350,440);
  bar(380,300,420+20,340);
  bar(440,360,480,400);
  bar(440,160,480+20,200);
  bar(480,200,520,440);
  bar(540,240,640,280);

  char x[100]="SCORE:";
 /* char y[100]="LIVES:";
  char z[100]="0";
  char x1[100]="1";
  char x2[100]="2";
  char x3[100]="3";
  char x4[100]="1000";
  char x5[100]="2000";
  char x6[100]="3000";
  char x7[100]="4000";  */
  char x4[100];
  ultoa(score,x4,10);
  setcolor(GREEN);
  settextstyle(4,0,4);
  outtextxy(50,0,x);
  outtextxy(200,0,x4);
/*  if(key2==0)
  outtextxy(200,0,x4);
  if(key2==1)
  { score+=10000; }//outtextxy(200,0,x6);        */
  if(key2==0)
  {
   setcolor(YELLOW);
   setfillstyle(SOLID_FILL,YELLOW);
   circle(450,340,12);
   bar(462,338,482,344);

  }
  if((key2==1)&&(flag2==1))
 {
  score+=10000;
  flag2=0;
 }

 /* for(int i=0;i<40;i++)
  for(int j=0;j<30;j++)
 rectangle(20*i,20*j,20,20);*/
}

void drawlvl2b()
{
cleardevice();
setbkcolor(BLACK);//set up colors
setcolor(LIGHTBLUE);
setpalette(BLACK,0);
setfillstyle(XHATCH_FILL,RED);
  bar(640,80,0,40); //bar(left1,top1,left2,top2)
  bar(0,240,120,280);
  bar(160,200,200,440);
  bar(160,200,240,240);
  bar(200,160,240,240);
  bar(200,160,280,200);
  bar(280,200,240,120);
  bar(240,120,380,160);
  bar(420,40,500,240);
  bar(320,200,640,240);
  bar(320,200,360,280);
  bar(280,240,360,280);
  bar(280,360,240,280);
  bar(160,420,640,440);
  bar(320,420,360,320);
  bar(320,320,400,360);
  bar(480,360,440,200);
  bar(600,420,560,300);
  bar(560,340,520,380);

  char x[100]="SCORE:";
  char x4[100];
  ultoa(score,x4,10);
  setcolor(GREEN);
  settextstyle(4,0,4);
  outtextxy(50,0,x);
  outtextxy(200,0,x4);
/* for(int i=0;i<40;i++)
 for(int j=0;j<30;j++)
 rectangle(20*i,20*j,20,20);  */
}

void drawlvl2c()
{
cleardevice();
setbkcolor(BLACK);//set up colors
setcolor(LIGHTBLUE);
setpalette(BLACK,0);
setfillstyle(XHATCH_FILL,RED);
  bar(640,80,0,40); //bar(left1,top1,left2,top2)
  bar(540,80,640,160);
  bar(640,160,120,120);
  bar(0,40,80,240);
  bar(0,200,180,240);
  bar(160,200,200,320);
  bar(240,320,280,280);
  bar(280,160,320,440);
  bar(320,440,0,420);
  bar(240,440,200,360);
  bar(120,440,80,300);
  bar(80,380,40,340);
  char x[100]="SCORE:";
  char x4[100];
  ultoa(score,x4,10);
  setcolor(GREEN);
  settextstyle(4,0,4);
  outtextxy(50,0,x);
  outtextxy(200,0,x4);

 setfillstyle(INTERLEAVE_FILL,BROWN);
 bar(500,80,540,120);
 setfillstyle(SOLID_FILL,YELLOW);
 bar(500,96,504,108);
 settextstyle(0,0,3);
 outtextxy(250,290,"W");
/* for(int i=0;i<40;i++)
 for(int j=0;j<30;j++)
 rectangle(20*i,20*j,20,20);  */
}

void plot()
{
 int knt=0;
 if((pointer1>=340)&&(pointer1<=360)&&(pointer2==120))
 {
  key1=1;
  score+=1000;
 }
 if((eog1()==0)&&(key1==1))
 {
  for(int i=0;i<9;i++)
  knt+=coinx[i].knt;
  score+=knt*1000;
  game=2;
  drawlvl2();
  plot2();
  level=2;
  pointer1=100;
  pointer2=380;
  oldpt1=pointer1;
  oldpt2=pointer2;
 }
 cleardevice();
 drawlvl1();
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 setcolor(LIGHTGRAY);
 int poly1[]={pointer1-4,pointer2-7*2,pointer1+2*2,pointer2-7*2,pointer1-2*2,pointer2-4*2,pointer1+2*2,pointer2-4*2};
 fillpoly(4,poly1);
 int poly2[]={pointer1-3.5*2,pointer2-8,pointer1+7,pointer2-8,pointer1+7,pointer2+6,pointer1-7,pointer2+6};
 setfillstyle(SOLID_FILL,YELLOW);
 setcolor(YELLOW);
 fillpoly(4,poly2);
 int poly3x1[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-12,pointer2+6.4,pointer1-13,pointer2+4};
 setfillstyle(SOLID_FILL,BROWN);
 setcolor(BROWN);
 int poly4x1[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+12,pointer2+6.4,pointer1+13,pointer2+4};
 int poly5[]={pointer1-6,pointer2+6,pointer1-6,pointer2+20,pointer1-2,pointer2+20,pointer1-2,pointer2+6};
 setfillstyle(SOLID_FILL,LIGHTBLUE);
 int poly6[]={pointer1+6,pointer2+6,pointer1+6,pointer2+20,pointer1+2,pointer2+20,pointer1+2,pointer2+6};
    int poly3x2[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-14,pointer2+5,pointer1-15,pointer2+3};
    int poly3x3[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-15.2,pointer2+2,pointer1-16,pointer2};
    int poly3x4[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-14.8,pointer2+3.6,pointer1-15.8,pointer2+1.6};
    int ax=random(4);
    if(ax==0)
    fillpoly(4,poly3x2);
    if(ax==1)
    fillpoly(4,poly3x3);
    if(ax==2)
    fillpoly(4,poly3x4);
    if(ax==3)
    fillpoly(4,poly3x1);
    int poly4x2[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+14,pointer2+5,pointer1+15,pointer2+3};
    int poly4x3[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+15.2,pointer2+2,pointer1+16,pointer2};
    int poly4x4[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+14.8,pointer2+3.6,pointer1+15.8,pointer2+1.6};
    int ax1=random(4);
    if(ax1==0)
    fillpoly(4,poly4x2);
    if(ax1==1)
    fillpoly(4,poly4x3);
    if(ax1==2)
    fillpoly(4,poly4x4);
    if(ax1==3)
    fillpoly(4,poly4x1);

  int ax2=random(2);
  int poly5x1[]={pointer1-6,pointer2+6,pointer1-11,pointer2+14,pointer1-7,pointer2+18,pointer1-2,pointer2+6};
  int poly6x1[]={pointer1+6,pointer2+6,pointer1+11,pointer2+14,pointer1+7,pointer2+18,pointer1+2,pointer2+6};
  if(legflag==1)
  {
   fillpoly(4,poly5x1);
   fillpoly(4,poly6);
   legflag=0;
  }
  else
  {
   legflag=1;
   fillpoly(4,poly5);
   fillpoly(4,poly6x1);
  }
 checkcoin();
 if(coinx[0].knt!=1)
 coinx[0].plot(100,200);
 if(coinx[1].knt!=1)
 coinx[1].plot(200,200);
 if(coinx[2].knt!=1)
 coinx[2].plot(300,200);
 if(coinx[3].knt!=1)
 coinx[3].plot(400,200);
 if(coinx[4].knt!=1)
 coinx[4].plot(540,200);
 if(coinx[5].knt!=1)
 coinx[5].plot(260,120);
 if(coinx[6].knt!=1)
 coinx[6].plot(160,120);
 if(coinx[7].knt!=1)
 coinx[7].plot(460,120);
}
/*  else
  {
   fillpoly(4,poly5);
   fillpoly(4,poly6);
  } */

 /*  int poly4x2[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+12,pointer2+6.4,pointer1+13,pointer2+4};					    */
 /*   setfillstyle(SOLID_FILL,BROWN);
    setcolor(BROWN);
    fillpoly(4,poly3);
    int poly4[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+12,pointer2+6.4,pointer1+13,pointer2+4};
    fillpoly(4,poly4);					      */
/* bar(pointer1-6,pointer2-6,pointer1+6,pointer2+6);
 circle(pointer1,pointer2-12,3);
 bar(pointer1-6,pointer2+6,pointer1-4,pointer2+18);
 bar(pointer1+4,pointer2+6,pointer1+6,pointer2+18);
 bar(pointer1-6,pointer2+1,pointer1-15,pointer2-1);
 bar(pointer1+6,pointer2-1,pointer1+15,pointer2+1);  */

 void checkcoin()
{
 for(int i=0;i<8;i++)
 {
   if((pointer1<coinx[i].pointerx+10)&&(pointer1>coinx[i].pointerx-10)&&(pointer2==coinx[i].pointery))
   coinx[i].knt=1;
 }
}
void moveup(int a)
{

 if(level==1)
 {int k=15;
 while((oldpt2-pointer2<=a*20))
 {
   pointer2-=20;
  if(movement1()==0)
   {pointer2-=1;}
   if(movement1()==0)
   {pointer2+=1;}
  else
  {
  pointer2+=20;
  break;
  }
  checkkb(k);
  plot();
  delay(diff*50);
 }
k--;
checkkb(k);
updatept();
gravityup();
}
if(level==2)
{int k=15;
 while((oldpt2-pointer2<=a*20))
 {
   pointer2-=20;
  if(movement2()==0)
   {pointer2-=1;}
   if(movement2()==0)
   {pointer2+=1;}
  else
  {
  pointer2+=20;
  break;
  }
  checkkb(k);
  plot2();
  delay(diff*50);
  }
k--;
checkkb(k);
updatept();
gravityup(); }
if(level==3)
{int k=15;
 while((oldpt2-pointer2<=a*20))
 {
   pointer2-=20;
  if(movement2b()==0)
   {pointer2-=1;}
   if(movement2b()==0)
   {pointer2+=1;}
  else
  {
  pointer2+=20;
  break;
  }
  checkkb(k);
  plot2b();
  delay(diff*50);
 }
k--;
checkkb(k);
updatept();
gravityup(); }
if(level==4)
{int k=15;
 while((oldpt2-pointer2<=a*20))
 {
   pointer2-=20;
  if(movement2c()==0)
   {pointer2-=1;}
   if(movement2c()==0)
   {pointer2+=1;}
  else
  {
  pointer2+=20;
  break;
  }
  checkkb(k);
  plot2c();
  delay(diff*50);
 }
k--;
checkkb(k);
updatept();
gravityup();
}
}
void movedown(int a)
{
 if(level==1)
 {while((pointer2-oldpt2<=a*20))
 {
 pointer2+=20;
 if(movement1()==0)
 {pointer2+=1;}
 if(movement1()==0)
 {pointer2-=1;}
 else
 {
  pointer2-=20;
  break;
 }
 plot();
 delay(diff*100);
}
updatept();
}
if(level==2)
{while((pointer2-oldpt2<=a*20))
 {
 pointer2+=20;
 if(movement2()==0)
 {pointer2+=1;}
 if(movement2()==0)
 {pointer2-=1;}
 else
 {
  pointer2-=20;
  break;
 }
 plot2();
 delay(diff*100);
}
updatept(); }
if(level==3)
{while((pointer2-oldpt2<=a*20))
 {
 pointer2+=20;
 if(movement2b()==0)
 {pointer2+=1;}
 if(movement2b()==0)
 {pointer2-=1;}
 else
 {
  pointer2-=20;
  break;
 }
 plot2b();
 delay(diff*100);
}
}
if(level==4)
{while((pointer2-oldpt2<=a*20))
 {
 pointer2+=20;
 if(movement2c()==0)
 {pointer2+=1;}
 if(movement2c()==0)
 {pointer2-=1;}
 else
 {
  pointer2-=20;
  break;
 }
 plot2c();
 delay(diff*100);
 }
}
}
void moveleft(int a)
{
 if(level==1)
 {while(oldpt1-pointer1<a*20)
 {
 pointer1-=20;
 grav2();
 if(movement1()==0)
 {pointer1-=1;}
 if(movement1()==0)
 {
 pointer1+=1;
 }
 else
 {
 pointer1+=20;
 break;
 }
 plot();
 legflag=random(2);
 delay(diff*100);
}
updatept();
}
if(level==2)
{ while(oldpt1-pointer1<a*20)
 {
  pointer1-=20;
  grav2();
 if(movement2()==0)
 {pointer1-=1;}
 if(movement2()==0)
 {
 pointer1+=1;
 }
 else
 {
 pointer1+=20;
 break;
 }
 plot2();
 legflag=random(2);
 delay(diff*100);
}
updatept(); }
if(level==3)
{ while(oldpt1-pointer1<a*20)
 {
  pointer1-=20;
  grav2();
 if(movement2b()==0)
 {pointer1-=1;}
 if(movement2b()==0)
 {
 pointer1+=1;
 }
 else
 {
 pointer1+=20;
 break;
 }
 plot2b();
 legflag=random(2);
 delay(diff*100);
}
updatept(); }
if(level==4)
{ while(oldpt1-pointer1<a*20)
 {
  pointer1-=20;
  grav2();
 if(movement2c()==0)
 {pointer1-=1;}
 if(movement2c()==0)
 {
 pointer1+=1;
 }
 else
 {
 pointer1+=20;
 break;
 }
 plot2c();
 legflag=random(2);
 delay(diff*100);
}
updatept();
}
}
void moveright(int a)
{
 if(level==1)
 {
 while(pointer1-oldpt1<a*20)
 {
  pointer1+=20;
  if(movement1()==0)
  {pointer1+=5;
  grav2();
  }
  if(movement1()==0)
  pointer1-=5;
  else
  {
  pointer1-=20;
  break;
  }
  plot();
  legflag=random(2);
  delay(diff*100);
 }
updatept();
}
if(level==2)
{ while(pointer1-oldpt1<a*20)
 {
 pointer1+=20;
 if(movement2()==0)
 {pointer1+=10;
  grav2();
 }
 if(movement2()==0)
 pointer1-=10;
 else
 {
 pointer1-=20;
 break;
 }
 plot2();
 legflag=random(2);
 delay(diff*100);
}
updatept();
}
if(level==3)
{ while(pointer1-oldpt1<a*20)
 {
 pointer1+=20;
 if(movement2b()==0)
 {pointer1+=10;
  grav2();
 }
 if(movement2b()==0)
 pointer1-=10;
 else
 {
 pointer1-=20;
 break;
 }
 plot2b();
 legflag=random(2);
 delay(diff*100);
 }
updatept();
}
if(level==4)
{ while(pointer1-oldpt1<a*20)
 {
 pointer1+=20;
 if(movement2c()==0)
 {pointer1+=10;
  grav2();
 }
 if(movement2c()==0)
 pointer1-=10;
 else
 {
 pointer1-=20;
 break;
 }
 plot2c();
 legflag=random(2);
 delay(diff*100);
 }
updatept();
}
}
void updatept()
{
 oldpt1=pointer1;
 oldpt2=pointer2;
}
int eog1()
{
 if((pointer2==380)&&(pointer1>=360)&&(pointer1<=400))
 return 0;
 else return 1;
}
void movedgr()
{
 while((oldpt1-pointer1<=60)&&(pointer2-oldpt2<=80))
 {
  pointer1+=20;
 if(movement1()==0)
 {pointer1+=10;}
 if(movement1()==0)
 pointer1-=10;
 else
 {
 pointer1-=20;
 break;
 }
  pointer2-=20;
  if(movement1()==0)
   {pointer2-=1;}
   if(movement1()==0)
   {pointer2+=1;}
  else
  {
  pointer2+=20;
  break;
  }
 plot();
 delay(100);
}
updatept();
gravityup();
}
void movedgl()
{
 while((oldpt1-pointer1<=60)&&(oldpt2-pointer2<=80))
 {
   pointer2-=20;
  if(movement1()==0)
   {pointer2-=1;}
   if(movement1()==0)
   {pointer2+=1;}
  else
  {
  pointer2+=20;
  break;
  }
  pointer1-=20;
 if(movement1()==0)
 {pointer1-=1;}
 if(movement1()==0)
 pointer1+=1;
 else
 {
 pointer1+=20;
 break;
 }
 plot();
 delay(100);
}
updatept();
gravityup();
}
void grav2()
{
 if(level==1)
 {
  pointer2+=1;
 if(movement1()==0)
 {
 gravityup();
 pointer2-=1;
 }
 else
 pointer2-=1;
 }
 if(level==2)
 { pointer2+=1;
 if((movement2()==0)&&(eog2()!=0))
 {
 gravityup();
 pointer2-=1;
 }
 else
 pointer2-=1; }
 if(level==3)
 { pointer2+=1;
 if(movement2b()==0)
 {
 gravityup();
 pointer2-=1;
 }
 else
 pointer2-=1; }
 if(level==4)
 { pointer2+=1;
 if(movement2c()==0)
 {
 gravityup();
 pointer2-=1;
 }
 else
 pointer2-=1; }
}
void gravityup()
{
  int pseudopt=0;
  if(level==1)
  {
  while(movement1()!=1)
  {
   pseudopt++;
   pointer2+=1;
   //pointer2+=20;
   if(pseudopt%30==0)
   {
    plot();
    delay(diff*100);
   }
  }
  pointer2-=20;
  plot();
}
  if(level==2)
  {
  int pseudopt=0;
  while((movement2()!=1)&&(eog2()!=0))
  {
   pseudopt++;
   pointer2+=1;
   //pointer2+=20;
   if(pseudopt%30==0)
   {
    plot2();
    delay(diff*100);
   }
  }
  pointer2-=20;
  plot2();
}
 if(level==3)
 {int pseudopt=0;
  while((movement2b()!=1)&&(eog2b()!=0))
  {
   pseudopt++;
   pointer2+=1;
   //pointer2+=20;
   if(pseudopt%30==0)
   {
    plot2b();
    delay(diff*100);
   }
  }
  pointer2-=20;
  plot2b(); }
 if(level==4)
 {
 int pseudopt=0;
  while((movement2c()!=1)&&(eog2c()!=0))
  {
   pseudopt++;
   pointer2+=1;
   //pointer2+=20;
   if(pseudopt%30==0)
   {
    plot2c();
    delay(diff*100);
   }
  }
  pointer2-=20;
  plot2c(); }
}
 int movement1()
{
 if((pointer2<=80)&&(pointer2>=40)&&(pointer1<=600)||
    (pointer1<=80)&&(pointer1>=40)&&(pointer2<=440)||
    (pointer2<=440)&&(pointer2>=400)&&(pointer1<=600)||
    (pointer2<=440)&&(pointer2>=80)&&(pointer1>=560)||
    (pointer1>=340)&&(pointer1<=380)&&(pointer2>=340)&&(pointer2<=400)||
    (pointer1>=340)&&(pointer1<=520)&&(pointer2>=300)&&(pointer2<=340)||
    (pointer1>=520)&&(pointer1<=580)&&(pointer2>=220)&&(pointer2<=260)||
    (pointer1>=80)&&(pointer1<=120)&&(pointer2>=220)&&(pointer2<=260)||
    (pointer1>=180)&&(pointer1<=220)&&(pointer2>=220)&&(pointer2<=260)||
    (pointer1>=280)&&(pointer1<=320)&&(pointer2>=220)&&(pointer2<=260)||
    (pointer1>=380)&&(pointer1<=420)&&(pointer2>=220)&&(pointer2<=260)||
    (pointer1>=140)&&(pointer1<=180)&&(pointer2>=140)&&(pointer2<=180)||
    (pointer1>=240)&&(pointer1<=280)&&(pointer2>=140)&&(pointer2<=180)||
    (pointer1>=340)&&(pointer1<=380)&&(pointer2>=140)&&(pointer2<=180)||
    (pointer1>=440)&&(pointer1<=480)&&(pointer2>=140)&&(pointer2<=180)||
    (pointer1>=140)&&(pointer1<=300)&&(pointer2>=320)&&(pointer2<=360))
 return 1;
 else
 return 0;
}
int movement2()
{
 if((pointer2<=80)&&(pointer2>=40)&&(pointer1<=600)||
    (pointer1<=80)&&(pointer1>=40)&&(pointer2<=440)||
    (pointer1>=80)&&(pointer1<=120)&&(pointer2>=420)&&(pointer2<=440)||
    (pointer1>=140)&&(pointer1<=240)&&(pointer2>=340)&&(pointer2<=380)||
    (pointer1>=120)&&(pointer1<=200)&&(pointer2>=260)&&(pointer2<=300)||
    (pointer1>=80)&&(pointer1<=120)&&(pointer2>=180)&&(pointer2<=220)||
    (pointer1>=160)&&(pointer1<=240+40)&&(pointer2>=120)&&(pointer2<=160)||
    (pointer1>=280)&&(pointer1<=380)&&(pointer2>=200)&&(pointer2<=240)||
    (pointer1>=310)&&(pointer1<=350)&&(pointer2>=260)&&(pointer2<=440)||
    (pointer1>=380)&&(pointer1<=420+20)&&(pointer2>=300)&&(pointer2<=340)||
    (pointer1>=440)&&(pointer1<=480)&&(pointer2>=360)&&(pointer2<=400)||
    (pointer1>=440)&&(pointer1<=480)&&(pointer2>=160)&&(pointer2<=200)||
    (pointer1>=480)&&(pointer1<=520)&&(pointer2>=200)&&(pointer2<=440)||
    (pointer1>=480+20)&&(pointer1<=520)&&(pointer2>=200)&&(pointer2<=440)||
    (pointer1>=540)&&(pointer1<=640)&&(pointer2>=240)&&(pointer2<=280))
 return 1;
 else
 return 0;
}
int movement2b()
{
 if((pointer2<=80)&&(pointer2>=40)&&(pointer1<=600)||
    (pointer1>=0)&&(pointer1<=120)&&(pointer2>=240)&&(pointer2<=280)||
    (pointer1>=160)&&(pointer1<=200)&&(pointer2>=200)&&(pointer2<=240)||
    (pointer1>=160)&&(pointer1<=240)&&(pointer2>=200)&&(pointer2<=240)||
    (pointer1>=200)&&(pointer1<=240)&&(pointer2>=160)&&(pointer2<=240)||
    (pointer1>=200)&&(pointer1<=280)&&(pointer2>=160)&&(pointer2<=200)||
    (pointer1>=240)&&(pointer1<=280)&&(pointer2>=120)&&(pointer2<=200)||
    (pointer1>=240)&&(pointer1<=380)&&(pointer2>=120)&&(pointer2<=160)||
    (pointer1>=420)&&(pointer1<=500)&&(pointer2>=40)&&(pointer2<=240)||
    (pointer1>=320)&&(pointer1<=640)&&(pointer2>=200)&&(pointer2<=240)||
    (pointer1>=320)&&(pointer1<=360)&&(pointer2>=200)&&(pointer2<=280)||
    (pointer1>=280)&&(pointer1<=360)&&(pointer2>=240)&&(pointer2<=280)||
    (pointer1>=240)&&(pointer1<=280)&&(pointer2>=280)&&(pointer2<=360)||
    (pointer1>=160)&&(pointer1<=640)&&(pointer2>=420)&&(pointer2<=440)||
    (pointer1>=320)&&(pointer1<=360)&&(pointer2>=320)&&(pointer2<=420)||
    (pointer1>=320)&&(pointer1<=400)&&(pointer2>=320)&&(pointer2<=360)||
    (pointer1>=440)&&(pointer1<=480)&&(pointer2>=200)&&(pointer2<=360)||
    (pointer1>=560)&&(pointer1<=600)&&(pointer2>=300)&&(pointer2<=420)||
    (pointer1>=520)&&(pointer1<=560)&&(pointer2>=340)&&(pointer2<=380))
 return 1;
 else
 return 0;
}
int movement2c()
{
 if((pointer2<=80)&&(pointer2>=40)&&(pointer1<=600)||
    (pointer1>=540)&&(pointer1<=640)&&(pointer2>=80)&&(pointer2<=160)||
    (pointer1>=0)&&(pointer1<=80)&&(pointer2>=40)&&(pointer2<=240)||
    (pointer1>=0)&&(pointer1<=180)&&(pointer2>=200)&&(pointer2<=240)||
    (pointer1>=160)&&(pointer1<=200)&&(pointer2>=200)&&(pointer2<=320)||
    (pointer1>=240)&&(pointer1<=280)&&(pointer2>=280)&&(pointer2<=320)||
    (pointer1>=280)&&(pointer1<=320)&&(pointer2>=160)&&(pointer2<=440)||
    (pointer1>=0)&&(pointer1<=320)&&(pointer2>=420)&&(pointer2<=440)||
    (pointer1>=200)&&(pointer1<=240)&&(pointer2>=360)&&(pointer2<=440)||
    (pointer1>=80)&&(pointer1<=120)&&(pointer2>=300)&&(pointer2<=440)||
    (pointer1>=40)&&(pointer1<=80)&&(pointer2>=340)&&(pointer2<=380)||
    (pointer1>=120)&&(pointer1<=640)&&(pointer2>=120)&&(pointer2<=160))
 return 1;
 else
 return 0;
}
void checkkb(int k)
{
 char a;
 if(kbhit())
  {
  int a=bioskey(0);
  if(a==right)//isalnum(a & 0xFF))  8292=right 7777=left
  pointer1+=k*2.5;
  if(a==left)
  pointer1-=k*2.5;
  }
}
void load()
{
 char a[100]="DANGEROUS DAVE";
 char c[100]="MADE BY";
 char d[100]="THE ALIEN ";
 char e[100]="1.START THE GAME";
 char f[100]="2.INSTRUCTIONS";
 char g[100]="3.CONTROLS";
 char h[100]="GET READY !!!!";
 char u[2]="3";
 char v[2]="2";
 char w[2]="1";
  cleardevice();
  setcolor(GREEN);
  settextstyle(4,0,7);
  outtextxy(10,0,h);
  getch();//delay(2000);
  cleardevice();
  settextstyle(0,0,2);
  story();
  settextstyle(0,0,2);
  outtextxy(170,180,"DAVE LOADING");
  for(int i=0;i<300;i++)
  {
   delay(30);
   line(120+i,200,120+i,220);
  }
  cleardevice();
  setcolor(GREEN);
  settextstyle(4,0,20);
  outtextxy(250,100,u);
  getch();//delay(1000);
  cleardevice();
  outtextxy(250,100,v);
  getch();//delay(1000);
  cleardevice();
  outtextxy(250,100,w);
  getch();//delay(1000);
  plot();
 }
void loadscreen()
{
 int i=0;
 int a1;
 char a[100]="DANGEROUS DAVE";
 char c[100]="MADE BY";
 char d[100]="THE ALIEN ";
 char e[100]="Start the Game";
 char f[100]="Instructions";
 char g[100]="Controls";
 char h[100]="GET READY !!!!";
 char u[2]="3";
 char v[2]="2";
 char w[2]="1";
 cleardevice();
 setbkcolor(BLACK);//set up colors
 setpalette(BLACK,0);
 settextstyle(4,0,7);
 //outtextxy(20,20,a);
 char x1[]={"D"};
 char x2[]={"A"};
 char x3[]={"N"};
 char x4[]={"G"};
 char x5[]={"E"};
 char x6[]={"R"};
 char x7[]={"O"};
 char x8[]={"U"};
 char x9[]={"S"};
 char x10[]={"D"};
 char x11[]={"A"};
 char x12[]={"V"};
 char x13[]={"E"};
 while(i<5)
 {
  cleardevice();
  i++;
  setcolor(GREEN);
  setbkcolor(random(11));
  settextstyle(0,0,9-i);
  outtextxy(48+32*i,100+20*i,c);
  delay(500);
 }
 i=0;
 delay(1000);
  while(i<5)
 {
 cleardevice();
 i++;
 setbkcolor(random(11));
 setcolor(YELLOW);
 settextstyle(0,0,9-i);
 outtextxy(0+32*i,100+20*i,d);
 delay(500);
 }
 delay(2000);
 i=0;
/*
 while(i<5)
 {
 cleardevice();
 i++;
 setbkcolor(random(11));
 setcolor(RED);
 settextstyle(4,0,7-i);
 outtextxy(50+32*i,100+20*i,a);
 delay(500);
 }       */
 cleardevice();
 setbkcolor(LIGHTBLUE);
 setcolor(LIGHTRED);
 settextstyle(0,0,9);
 outtextxy(0,100,x1);
 delay(500);
 outtextxy(70,100,x2);
 delay(500);
 outtextxy(140,100,x3);
 delay(500);
 outtextxy(210,100,x4);
 delay(500);
 outtextxy(280,100,x5);
 delay(500);
 outtextxy(350,100,x6);
 delay(500);
 outtextxy(420,100,x7);
 delay(500);
 outtextxy(490,100,x8);
 delay(500);
 outtextxy(560,100,x9);
 delay(200);
 settextstyle(0,0,13);
 setcolor(RED);
 outtextxy(100,200,x10);
 delay(1500);
 outtextxy(200,200,x11);
 delay(1500);
 outtextxy(300,200,x12);
 delay(1500);
 outtextxy(400,200,x13);
 delay(1500);
 setbkcolor(BLACK);
 setcolor(WHITE);
 settextstyle(4,0,7);
 cleardevice();
// outtextxy(10,0,a);
 char exit2[]={"Exit"};
 int a3=0,p=85;
 top:
 cleardevice();
 setbkcolor(BLACK);
 setcolor(RED);
 settextstyle(4,0,7);
 outtextxy(50,50,e);
 setcolor(GREEN);
 outtextxy(50,150,f);
 setcolor(YELLOW);
 outtextxy(50,250,g);
 setcolor(CYAN);
 outtextxy(50,350,exit2);
	 if(p>395) p=95;
	else if(p<95) p=395;
	a3=0; bomb(20,p);
	while(!kbhit())
		bomb(20,p);
	while(a3!=7181)
	{
	  if(kbhit()) a3=bioskey(0);
	  if(a3==20480)
	  {
		  cleardevice();
		  p+=100;a3=0;goto top;
	  }
	  else if(a3==18432)
	  {
		  cleardevice();
		  p-=100;a3=0;goto top;
	  }
	}
	if(p==95)
	{
		load();
	}
	if(p==195)
 instructions();
 if(p==295)
 controls();
 if(p==395)
 {
   cleardevice();
   char abc[]={"Are You Sure?"},ch;
   outtextxy(0,10,abc);
   ch=getch();
   if((ch=='y')||(ch=='Y'))
   { exit(-1);}
   else
   goto top;
 }
}
void controls()
{
 char choice[100];
 cleardevice();
 setbkcolor(BLACK);//set up colors
 setpalette(BLACK,0);
 settextstyle(4,0,6);
 setcolor(GREEN);
 char a[100]="Enter up key";
 outtextxy(0,50,a);
 settextstyle(4,0,6);
 setcolor(GREEN);
 up=bioskey(0);
 setcolor(GREEN);
 cleardevice();
 char b[100]="Enter down key";
 outtextxy(0,50,b);
 down=bioskey(0);
 cleardevice();
 char c[100]="Enter left key";
 outtextxy(0,50,c);
 left=bioskey(0);
 cleardevice();
 char d[100]="Enter right key";
 outtextxy(0,50,d);
 right=bioskey(0);
 cleardevice();
 char e[100]="Enter difficulty";
 outtextxy(0,50,e);
 cleardevice();
 char f[100]=" Noob, Amateur or Pro?";
 outtextxy(0,50,f);
 gets(choice);
 if(strcmpi(choice,"Noob")==0)
 {
 cleardevice();
 diff=3;
 char g2[100]="Learn to Play Fast Hehe";
 outtextxy(0,50,g2);
 delay(3000);
 }
 if(strcmpi(choice,"Amateur")==0)
 {
 cleardevice();
 diff=2;
 char g3[100]="Okay, try Pro next time";
 outtextxy(0,50,g3);
 delay(3000);
 }
 if(strcmpi(choice,"Pro")==0)
 {
  cleardevice();
  diff=1;
  char g[100]="Extreme Gravity";
  char h[100]="The Alien's Favourite";
  outtextxy(0,50,g);
  outtextxy(0,150,h);
  delay(3000);
 }
 if(level==1) plot();
 if(level==2) plot2();
 if(level==3) plot2b();
 if(level==4) plot2c();
 //loadscreen();
 //plot();
}
void story()
{
  cleardevice();
 setbkcolor(BLACK);//set up colors
 setpalette(BLACK,0);
 settextstyle(4,0,5);
 setcolor(CYAN);
 char a[100];
 fstream f("Story.txt",ios::in|ios::out);
 f.getline(a,100,'\n');
 int i=0;
 while(!f.eof())
 {
  setcolor(CYAN);
  cleardevice();
  outtextxy(0,0,a);
  f.getline(a,100,'\n');
  delay(5000);
  i++;
 }
}
 /*
  cleardevice();
  setcolor(GREEN);
  delay(2000);
  settextstyle(0,0,2);
   for(int i=0;i<300;i++)
  {
   delay(30);
   line(2i,400,2i,420);
  }					 */
void instructions()
{
 cleardevice();
 setbkcolor(BLACK);//set up colors
 setpalette(BLACK,0);
 settextstyle(4,0,4);
 setcolor(CYAN);
 char a[100];
 fstream f("Instructions.txt",ios::in|ios::out);
 f.getline(a,100,'\n');
 while(!f.eof())
 {
  cleardevice();
  outtextxy(0,0,a);
  f.getline(a,100,'\n');
  getch(); //delay(5000);
 }
 controls();
}
int eog2()
{
 if(((pointer1>=120)&&(pointer1<=310)&&(pointer2>=415))||
    ((pointer1>360)&&(pointer1<=500)&&(pointer2>=400))||
    ((pointer1>=500)&&(pointer2>=320))||
    ((pointer1>=140)&&(pointer1<=310)&&(pointer2>=400)))
    return 0;
  if((pointer1>=540)&&(pointer2>=210)&&(pointer2<=230))
  return 2;
  if((pointer1>=440)&&(pointer1<=480)&&(pointer2>=340)&&(pointer2<=360))
  key2=1;
  else
  return 1;
 }
int eog2b()
{
 if((pointer1>=120)&&(pointer1<=160)&&(pointer2>=280))
 return 0;
 if((pointer1>=600)&&(pointer2>=290))
 return 2;
 else return 1;
}
int eog2c()
{
 if((pointer1>=500)&&(pointer2>=80))
 {
  return 0;
 }
 else return 1;
}
void plot2()
{
 cleardevice();
 drawlvl2();
/* setfillstyle(SOLID_FILL,CYAN);
 setcolor(CYAN);
 bar(pointer1-6,pointer2-6,pointer1+6,pointer2+6);
 circle(pointer1,pointer2-12,3);
 bar(pointer1-6,pointer2+6,pointer1-4,pointer2+18);
 bar(pointer1+4,pointer2+6,pointer1+6,pointer2+18);
 bar(pointer1-6,pointer2+1,pointer1-15,pointer2-1);
 bar(pointer1+6,pointer2-1,pointer1+15,pointer2+1);  */
  setfillstyle(SOLID_FILL,LIGHTGRAY);
 setcolor(LIGHTGRAY);
 int poly1[]={pointer1-4,pointer2-7*2,pointer1+2*2,pointer2-7*2,pointer1-2*2,pointer2-4*2,pointer1+2*2,pointer2-4*2};
 fillpoly(4,poly1);
 int poly2[]={pointer1-3.5*2,pointer2-8,pointer1+7,pointer2-8,pointer1+7,pointer2+6,pointer1-7,pointer2+6};
 setfillstyle(SOLID_FILL,YELLOW);
 setcolor(YELLOW);
 fillpoly(4,poly2);
 int poly3x1[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-12,pointer2+6.4,pointer1-13,pointer2+4};
 setfillstyle(SOLID_FILL,BROWN);
 setcolor(BROWN);
 int poly4x1[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+12,pointer2+6.4,pointer1+13,pointer2+4};
 int poly5[]={pointer1-6,pointer2+6,pointer1-6,pointer2+20,pointer1-2,pointer2+20,pointer1-2,pointer2+6};
 setfillstyle(SOLID_FILL,LIGHTBLUE);
 int poly6[]={pointer1+6,pointer2+6,pointer1+6,pointer2+20,pointer1+2,pointer2+20,pointer1+2,pointer2+6};
    int poly3x2[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-14,pointer2+5,pointer1-15,pointer2+3};
    int poly3x3[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-15.2,pointer2+2,pointer1-16,pointer2};
    int poly3x4[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-14.8,pointer2+3.6,pointer1-15.8,pointer2+1.6};
    int ax=random(4);
    if(ax==0)
    fillpoly(4,poly3x2);
    if(ax==1)
    fillpoly(4,poly3x3);
    if(ax==2)
    fillpoly(4,poly3x4);
    if(ax==3)
    fillpoly(4,poly3x1);
    int poly4x2[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+14,pointer2+5,pointer1+15,pointer2+3};
    int poly4x3[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+15.2,pointer2+2,pointer1+16,pointer2};
    int poly4x4[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+14.8,pointer2+3.6,pointer1+15.8,pointer2+1.6};
    int ax1=random(4);
    if(ax1==0)
    fillpoly(4,poly4x2);
    if(ax1==1)
    fillpoly(4,poly4x3);
    if(ax1==2)
    fillpoly(4,poly4x4);
    if(ax1==3)
    fillpoly(4,poly4x1);

  int poly5x1[]={pointer1-6,pointer2+6,pointer1-11,pointer2+14,pointer1-7,pointer2+18,pointer1-2,pointer2+6};
  int poly6x1[]={pointer1+6,pointer2+6,pointer1+11,pointer2+14,pointer1+7,pointer2+18,pointer1+2,pointer2+6};
  if(legflag==1)
  {
   fillpoly(4,poly5x1);
   fillpoly(4,poly6);
   legflag=0;
  }
  else
 {
   legflag=1;
   fillpoly(4,poly5);
   fillpoly(4,poly6x1);
  }
 checkcoin2();
 if(coiny[0].knt!=1)
 coiny[0].plot(200,100);
 if(coiny[1].knt!=1)
 coiny[1].plot(100,160);
 if(coiny[2].knt!=1)
 coiny[2].plot(320,180);
 if(coiny[3].knt!=1)
 coiny[4].plot(400,280);
 if(coiny[5].knt!=1)
 coiny[5].plot(460,140);
 if(coiny[6].knt!=1)
 coiny[6].plot(560,220);
 if(coiny[7].knt!=1)
 coiny[7].plot(140,240);
 if(eog2()==0)
 {
 endscreen();
 game=0;
 }

 if((eog2()==2)&&(key2==1))
 {
  int knt=0;
  for(int i=0;i<9;i++)
  knt+=coiny[i].knt;
  score+=knt*1000;
  game=3;
  drawlvl2b();
//  plot2b();
  level=3;
  pointer1=100;
  pointer2=220;
  plot2b();
  oldpt1=pointer1;
  oldpt2=pointer2;
 }
}
 void checkcoin2()
{
 for(int i=0;i<8;i++)
 {
   if((pointer1<coiny[i].pointerx+10)&&(pointer1>coiny[i].pointerx-10)&&(pointer2<=coiny[i].pointery+10)&&(pointer2>=coiny[i].pointery-10))
   coiny[i].knt=1;
 }
}
void plot2b()
{
 if(eog2b()==0)
 {
  endscreen();
  game=0;
 }
 /* circle(450,340,12);
   bar(462,338,482,344);      */
 if((pointer1>=420)&&(pointer1<=490)&&(pointer2>=320)&&(pointer2<=360))
 key2=1;
 cleardevice();
 drawlvl2b();
  setfillstyle(SOLID_FILL,LIGHTGRAY);
 setcolor(LIGHTGRAY);
 int poly1[]={pointer1-4,pointer2-7*2,pointer1+2*2,pointer2-7*2,pointer1-2*2,pointer2-4*2,pointer1+2*2,pointer2-4*2};
 fillpoly(4,poly1);
 int poly2[]={pointer1-3.5*2,pointer2-8,pointer1+7,pointer2-8,pointer1+7,pointer2+6,pointer1-7,pointer2+6};
 setfillstyle(SOLID_FILL,YELLOW);
 setcolor(YELLOW);
 fillpoly(4,poly2);
 int poly3x1[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-12,pointer2+6.4,pointer1-13,pointer2+4};
 setfillstyle(SOLID_FILL,BROWN);
 setcolor(BROWN);
 int poly4x1[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+12,pointer2+6.4,pointer1+13,pointer2+4};
 int poly5[]={pointer1-6,pointer2+6,pointer1-6,pointer2+20,pointer1-2,pointer2+20,pointer1-2,pointer2+6};
 setfillstyle(SOLID_FILL,LIGHTBLUE);
 int poly6[]={pointer1+6,pointer2+6,pointer1+6,pointer2+20,pointer1+2,pointer2+20,pointer1+2,pointer2+6};
    int poly3x2[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-14,pointer2+5,pointer1-15,pointer2+3};
    int poly3x3[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-15.2,pointer2+2,pointer1-16,pointer2};
    int poly3x4[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-14.8,pointer2+3.6,pointer1-15.8,pointer2+1.6};
    int ax=random(4);
    if(ax==0)
    fillpoly(4,poly3x2);
    if(ax==1)
    fillpoly(4,poly3x3);
    if(ax==2)
    fillpoly(4,poly3x4);
    if(ax==3)
    fillpoly(4,poly3x1);
    int poly4x2[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+14,pointer2+5,pointer1+15,pointer2+3};
    int poly4x3[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+15.2,pointer2+2,pointer1+16,pointer2};
    int poly4x4[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+14.8,pointer2+3.6,pointer1+15.8,pointer2+1.6};
    int ax1=random(4);
    if(ax1==0)
    fillpoly(4,poly4x2);
    if(ax1==1)
    fillpoly(4,poly4x3);
    if(ax1==2)
    fillpoly(4,poly4x4);
    if(ax1==3)
    fillpoly(4,poly4x1);
  int poly5x1[]={pointer1-6,pointer2+6,pointer1-11,pointer2+14,pointer1-7,pointer2+18,pointer1-2,pointer2+6};
  int poly6x1[]={pointer1+6,pointer2+6,pointer1+11,pointer2+14,pointer1+7,pointer2+18,pointer1+2,pointer2+6};
  if(legflag==1)
  {
   fillpoly(4,poly5x1);
   fillpoly(4,poly6);
   legflag=0;
  }
  else
 {
   legflag=1;
   fillpoly(4,poly5);
   fillpoly(4,poly6x1);
  }
					       /*
 setfillstyle(SOLID_FILL,CYAN);
 setcolor(CYAN);
 bar(pointer1-6,pointer2-6,pointer1+6,pointer2+6);
 circle(pointer1,pointer2-12,3);
 bar(pointer1-6,pointer2+6,pointer1-4,pointer2+18);
 bar(pointer1+4,pointer2+6,pointer1+6,pointer2+18);
 bar(pointer1-6,pointer2+1,pointer1-15,pointer2-1);
 bar(pointer1+6,pointer2-1,pointer1+15,pointer2+1);    */
if(eog2b()==2)
 {
//   cleardevice();
//  game=4;
//  drawlvl2c();
//  plot2c();
//  level=4;
  game=4;
  drawlvl2c();
//  plot2b();
  level=4;
  pointer1=180;
  pointer2=400;
  plot2c();
  pointer1+=1;
  pointer1-=1;
  plot2c();
  pointer1-=1;
  pointer1+=1;
  plot2c();
  updatept();
 }

}
void plot2c()
{
 cleardevice();
 drawlvl2c();
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 setcolor(LIGHTGRAY);
 int poly1[]={pointer1-4,pointer2-7*2,pointer1+2*2,pointer2-7*2,pointer1-2*2,pointer2-4*2,pointer1+2*2,pointer2-4*2};
 fillpoly(4,poly1);
 int poly2[]={pointer1-3.5*2,pointer2-8,pointer1+7,pointer2-8,pointer1+7,pointer2+6,pointer1-7,pointer2+6};
 setfillstyle(SOLID_FILL,YELLOW);
 setcolor(YELLOW);
 fillpoly(4,poly2);
 int poly3x1[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-12,pointer2+6.4,pointer1-13,pointer2+4};
 setfillstyle(SOLID_FILL,BROWN);
 setcolor(BROWN);
 int poly4x1[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+12,pointer2+6.4,pointer1+13,pointer2+4};
 int poly5[]={pointer1-6,pointer2+6,pointer1-6,pointer2+20,pointer1-2,pointer2+20,pointer1-2,pointer2+6};
 setfillstyle(SOLID_FILL,LIGHTBLUE);
 int poly6[]={pointer1+6,pointer2+6,pointer1+6,pointer2+20,pointer1+2,pointer2+20,pointer1+2,pointer2+6};
    int poly3x2[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-14,pointer2+5,pointer1-15,pointer2+3};
    int poly3x3[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-15.2,pointer2+2,pointer1-16,pointer2};
    int poly3x4[]={pointer1-7,pointer2-4,pointer1-7,pointer2,pointer1-14.8,pointer2+3.6,pointer1-15.8,pointer2+1.6};
    int ax=random(4);
    if(ax==0)
    fillpoly(4,poly3x2);
    if(ax==1)
    fillpoly(4,poly3x3);
    if(ax==2)
    fillpoly(4,poly3x4);
    if(ax==3)
    fillpoly(4,poly3x1);
    int poly4x2[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+14,pointer2+5,pointer1+15,pointer2+3};
    int poly4x3[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+15.2,pointer2+2,pointer1+16,pointer2};
    int poly4x4[]={pointer1+7,pointer2-4,pointer1+7,pointer2,pointer1+14.8,pointer2+3.6,pointer1+15.8,pointer2+1.6};
    int ax1=random(4);
    if(ax1==0)
    fillpoly(4,poly4x2);
    if(ax1==1)
    fillpoly(4,poly4x3);
    if(ax1==2)
    fillpoly(4,poly4x4);
    if(ax1==3)
    fillpoly(4,poly4x1);
  int poly5x1[]={pointer1-6,pointer2+6,pointer1-11,pointer2+14,pointer1-7,pointer2+18,pointer1-2,pointer2+6};
  int poly6x1[]={pointer1+6,pointer2+6,pointer1+11,pointer2+14,pointer1+7,pointer2+18,pointer1+2,pointer2+6};
  if(legflag==1)
  {
   fillpoly(4,poly5x1);
   fillpoly(4,poly6);
   legflag=0;
  }
   else
  {
   legflag=1;
   fillpoly(4,poly5);
   fillpoly(4,poly6x1);
  }
  if((pointer1>=240)&&(pointer2>=160)&&(pointer1<=280)&&(pointer2==180))
 {
   pointer1=100;
   pointer2=180;
 }
 if(eog2c()==0)
 endscreen();
}
 /* if(pointer1==520)
 {
  endscreen();
  game=0;
 } */
			    /*
 setfillstyle(SOLID_FILL,CYAN);
 setcolor(CYAN);
 bar(pointer1-6,pointer2-6,pointer1+6,pointer2+6);
 circle(pointer1,pointer2-12,3);
 bar(pointer1-6,pointer2+6,pointer1-4,pointer2+18);
 bar(pointer1+4,pointer2+6,pointer1+6,pointer2+18);
 bar(pointer1-6,pointer2+1,pointer1-15,pointer2-1);
 bar(pointer1+6,pointer2-1,pointer1+15,pointer2+1); */
void endscreen()
{
 char a1[100]="CONGRATULATIONS";
 char a2[100]="YOU HAVE";
 char a3[100]="FINISHED";
 char a4[100]="THE GAME";
 char a5[100]="IS OVER";
 char a6[100]="***********";
 if((game==4)&&(level==4)&&(eog2c()==0))
 {
  cleardevice();
  setcolor(GREEN);
  settextstyle(4,0,6);
  outtextxy(10,0,a1);
  setcolor(YELLOW);
  outtextxy(10,100,a2);
  setcolor(CYAN);
  outtextxy(340,100,a3);
  setcolor(MAGENTA);
  outtextxy(10,200,a4);
  setcolor(RED);
  settextstyle(4,0,11);
  outtextxy(10,250,a6);
  delay(5000);
  game=0; }
  else
  {
  setcolor(YELLOW);
  settextstyle(4,0,9);
  outtextxy(50,50,a4);
  settextstyle(4,0,10);
  outtextxy(30,200,a5);
  //getch();
  delay(5000);
  game=0;
//  exit(-1);
 }
//  highscore();
}
double time()
{
  time_t t;
  t=time(NULL);
  return t;
}

void bomb(int x,int y)
{
	line(x,y-15,x+10,y-25);
	setfillstyle(9,8);
	bar(x-5,y-15,x+5,y-5);
	setfillstyle(8,8);
	fillellipse(x,y,10,10);

}
void esckey()
{
 char a1[100]="Continue";
 char a2[100]="Reset Controls/Diff";
 char a3x[100]="Restart Game";
 char a4[100]="Exit the Game";
/* settextstyle(0,0,4);
 setcolor(YELLOW);
 outtextxy(0,50,a);
 outtextxy(0,150,a2);
 outtextxy(0,250,a3);
 outtextxy(0,350,a4);
 int ax1=bioskey(0);
 if(ax1==561)
 {
   if(level==1) plot();
   if(level==2) plot2();
   if(level==3) plot2b();
   if(level==4) plot2c();
 }
 if(ax1==818)
 controls();
 if(ax1==1075)
 loadscreen();
 if(ax1==1332)
 {
   char abc[]={"Are You Sure?"},ch;
   cleardevice();
   outtextxy(0,10,abc);
   ch=getch();
   if((ch=='y')||(ch=='Y'))
   { exit(-1);}
   else
   esckey();
}
}         */
 char exit2[]={"Exit"};
 int a3=0,p=85;
 top:
 cleardevice();
 setbkcolor(BLACK);
 setcolor(RED);
 settextstyle(4,0,7);
 outtextxy(50,50,a1);
 setcolor(GREEN);
 outtextxy(50,150,a2);
 setcolor(YELLOW);
 outtextxy(50,250,a3x);
 setcolor(CYAN);
 outtextxy(50,350,exit2);
	 if(p>395) p=95;
	else if(p<95) p=395;
	a3=0; bomb(20,p);
	while(!kbhit())
		bomb(20,p);
	while(a3!=7181)
	{
	  if(kbhit()) a3=bioskey(0);
	  if(a3==20480)
	  {
		  cleardevice();
		  p+=100;a3=0;goto top;
	  }
	  else if(a3==18432)
	  {
		  cleardevice();
		  p-=100;a3=0;goto top;
	  }
	}
	if(p==95)
	{
		plot();
	}
	if(p==195)
 controls();
 if(p==295)
 loadscreen();
 if(p==395)
 {
   cleardevice();
   char abc[]={"Are You Sure?"},ch;
   outtextxy(0,10,abc);
   ch=getch();
   if((ch=='y')||(ch=='Y'))
   { exit(-1);}
   else
   goto top;
 }
}
   /*
	int a,p=205;
	cleardevice();
	top:
	if(p>355) p=205;
	else if(p<205) p=355;
	setbkcolor(BLACK);
	settextstyle(0,0,2);
	setcolor(WHITE);
	outtextxy(100,200,a1);
	outtextxy(100,250,a2);
	outtextxy(100,300,a3);
	outtextxy(100,350,a4);
	a=0; bomb(80,p);
	while(!kbhit())
		bomb(80,p);
	while(a!=7181)
	{
	  if(kbhit()) a=bioskey(0);
	  if(a==20480)
	  {
		  cleardevice();
		  p+=50;a=0;goto top;
	  }
	  else if(a==18432)
	  {
		  cleardevice();
		  p-=50;a=0;goto top;
	  }
	}
	if(p==205)
	{
   if(level==1) plot();
   if(level==2) plot2();
   if(level==3) plot2b();
   if(level==4) plot2c();
	}
	if(p==255)
 controls();
 if(p==305)
 loadscreen();
 if(p==355)
 {
   char abc[]={"Are You Sure?"},ch;
   cleardevice();
   outtextxy(0,10,abc);
   ch=getch();
   if((ch=='y')||(ch=='Y'))
   { exit(-1);}
   else
   goto top;
}
}  */
/*void esckey()
{
 char a[100]="1. Continue";
 char a2[100]="2. Reset Controls";
 char a3[100]="3. Restart Game";
 char a4[100]="4. Exit the Game";
 settextstyle(0,0,4);
 setcolor(YELLOW);
 outtextxy(0,50,a);
 outtextxy(0,150,a2);
 outtextxy(0,250,a3);
 outtextxy(0,350,a4);
 int ax1=bioskey(0);
 if(ax1==561)
 {
   if(level==1) plot();
   if(level==2) plot2();
   if(level==3) plot2b();
   if(level==4) plot2c();
 }
 if(ax1==818)
 controls();
 if(ax1==1075)
 loadscreen();
 if(ax1==1332)
 {
   char abc[]={"Are You Sure?"},ch;
   cleardevice();
   outtextxy(0,10,abc);
   ch=getch();
   if((ch=='y')||(ch=='Y'))
   { exit(-1);}
   else
   esckey();
}
} */

void main()
{
 int a;
 //int i=0,j=0;
 clrscr();
 SetupGraphics();
 cleardevice();
 int x;
//  loadscreen();
//  endscreen();
//  highscore();
//  loadscreen();
  time_t scorei,scoref;
  scorei=time();
  level=1;
  game=1;
  plot();

//  plot();
//  controls();
//  instructions();
//  plot();
//  esckey2();
 while(game!=0)
 {
  a=bioskey(0);
  if(a==up)
  //{
  moveup(3);
  /*while(i<10)
  {
  sound(100+10*i);
  delay(40);
  nosound();
  i++;
  }
  while(j<10)
  {
   sound(200-10*j);
   delay(40);
   nosound();
   j++;
  }
  } */
  if(a==down)
  movedown(3);
  if(a==left)
  moveleft(1);
  if(a==right)
  moveright(1);
  /*if(a=='q')
  movedgl();
  if(a=='e')
  movedgr();*/
  if(a==7777)
  break; //exit(0);
  if(a==283)
  esckey2();
  }
  scoref=time();
  //clrscr();
  //cleardevice();
  int score2;
  score2=(scoref-scorei)*100;
  cleardevice();
  char abc[]="You have obtained a score of : ";
  char abc2[100];
  settextstyle(10,0,2);
  // cout<<score<<score2;
  score=score+score2;
  //score=40;
  ultoa(score,abc2,10);
  outtextxy(0,50,abc);
  outtextxy(510,52,abc2);
  readx();
  getch();
}
/* struct score1
{
 int lvl,scr;
 char name[100];
 void accept()
 {
  gets(name);
  lvl=level;
  scr=score;
 }
 void display()
 {
  cleardevice();
  setbkcolor(BLACK);
  setcolor(RED);
  settextstyle(4,0,7);
  outtextxy(10,0,name);
  delay(1000);
 }
};*/

struct player
{
 double score1;
 char name[100];
 void accept()
 {
  outtextxy(50,0,"Enter Your name");
  gets(name);
  score1=score;
 }
 void display()
 {
  cout<<name<<" "<<score<<endl;
 }
};
void readx()
{
 cleardevice();
 setbkcolor(BLACK);
 setcolor(YELLOW);
 settextstyle(10,0,2);
 fstream f1("Highscore.dat",ios::in|ios::out|ios::binary);
 f1.seekg(0);
 player r,t,s,a[100];
 char hs1[]="Highscores";
 int k=0,ki=0;
 int i=0,j=0,n=0,y=0;
 r.accept();
 cleardevice();
 outtextxy(200,0,hs1);
 f1.read((char*)&t,sizeof(t));
 while(!f1.eof())
 {
  a[k++]=t;
  f1.read((char*)&t,sizeof(t));
 }
  a[k++]=r;
/*f1.close();
  a[k++]=r;
  f1.write((char*)&r,sizeof(r));      */
 for(i=0;i<k;i++)
 {
  for(j=0;j<k;j++)
  {
	 if(a[j].score1<a[i].score1)
   {
     s=a[i];
     a[i]=a[j];
     a[j]=s;
   }
  }
 }
  f1.close();
  f1.open("Highscore.dat",ios::in|ios::out|ios::binary|ios::trunc);
  f1.seekp(0);

    while(k>=0)
   {
    t=a[k];
    f1.write((char*)&t,sizeof(t));
    k--;
   }
   y+=97;
   char hs[100];
      while(n<7)
   {
   // cout<<n;
    delay(100);
    settextstyle(0,0,2);
    itoa(a[n].score1,hs,10);
    outtextxy(50,y,a[n].name);
    outtextxy(500,y,hs);
    y+=47;
    n++;

   }
 }

#define ON 1
#define OFF 0
#define YES 1
#define NO 2
#define CANCEL 3
#define CLOSE 4
#define OK 5
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<alloc.h>

union REGS i,o;
struct SREGS s;

displaymenuv(char **menu,int count,int width,int x1,int y1,int bk_color);

highlight (char **menu,int ch,int x1,int y1)
{
   int xc=x1,tw,tw1,i;
   for(i=1;i<=ch;i++)
  { xc=xc+textwidth(menu[i-1])+10; }
    tw=textwidth(menu[ch-1]);
    setcolor(WHITE);
    line(xc-10-tw,y1,xc,y1);
    line(xc-10-tw,y1,xc-10-tw,y1+17);
    setcolor(8);
    line(xc-10-tw,y1+17,xc,y1+17);
    line(xc,y1,xc,y1+17);
}

highlightv(char **menu,int ch,int width,int x1,int y1,int color)
{
    int h;
    h=textheight(menu[0]);
    setfillstyle(SOLID_FILL,color);
    bar(x1,y1+(ch-1)*(h+10),x1+width+9,y1+(ch-1)*(h+10)+12);
    setcolor(WHITE);
    outtextxy(x1+10,y1+(ch-1)*(h+10),menu[ch-1]);
}
dehighlightv(char **menu,int ch,int width,int x1,int y1,int bk_color)
{
    int h;
    h=textheight(menu[0]);
    setfillstyle(SOLID_FILL,bk_color);
    bar(x1,y1+(ch-1)*(h+10),x1+width+9,y1+(ch-1)*(h+10)+12);
    setcolor(BLACK);
    outtextxy(x1+10,y1+(ch-1)*(h+10),menu[ch-1]);
}
corner_button(int x,int y)
{
  setcolor(WHITE);
  setfillstyle(SOLID_FILL,7);
  settextstyle(SMALL_FONT,0,6);
  rectangle(x-5,y-3,x+8,y+8);
  setcolor(8);
  rectangle(x-4,y-2,x+9,y+9);
  bar(x-4,y-2,x+8,y+8);
}
close_button(int x,int y)
{
  corner_button(x,y);
  setcolor(BLACK);
  outtextxy(x-1,y-9,"x");
  outtextxy(x-2,y-9,"x");
}
minimise_button(int x,int y)
{
  corner_button(x,y);
  setcolor(WHITE);
  outtextxy(x-1,y-9,"_");
  setcolor(BLACK);
  outtextxy(x-1,y-10,"_");
}
maximize_button(int x,int y)
{
   corner_button(x,y);
   setcolor(WHITE);
   line(x-2,y-1,x+6,y-1);
   setcolor(BLACK);
   rectangle(x-2,y,x+6,y+7);
}
initmouse()
{
  i.x.ax=0;
  int86(0x33,&i,&o);
  return(o.x.ax);
}

showmouseptr()
{
  i.x.ax=1;
  int86(0x33,&i,&o);
  return(o.x.ax);
}

hidemouseptr()
{
  i.x.ax=2;
  int86(0x33,&i,&o);
  return(o.x.ax);
}
getmousepos(int *button,int *x,int *y)
{
  i.x.ax=3;
  int86(0x33,&i,&o);
  *button=o.x.bx; *x=o.x.cx; *y=o.x.dx;
}
getresponsev(char **menu,int count,int width,int x1,int y1,int color,int bk_color)
{
  int choice=1,prevchoice=0,x,y,x2,y2,button,in,i,h,tw,xc,area;
  long int *buffer;
  h=textheight(menu[0]);
  y2=y1+count*(h+10);
  x2=x1+width+10;
  hidemouseptr();
  area=imagesize(x1-6,y1-11,x1+width+13,y1+count*(h+10)+10);
	 buffer=(long int *)malloc(area);
  getimage(x1-6,y1-11,x1+width+13,y1+count*(h+10)+10,buffer);
  displaymenuv(menu,count,width,x1,y1,bk_color); showmouseptr();
  settextstyle(SMALL_FONT,0,4);
  while(1)

  {
       getmousepos(&button,&x,&y);
	if(x<x1 || x>x2 || y<y1 || y>y2)
	{  if((button & 1)==1)
	 {
	    hidemouseptr();
	    putimage(x1-6,y1-11,buffer,COPY_PUT);
	    free(buffer);
	    return(0);
	 }
	}
    if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
     {
	 in=1;
   for(i=1;i<=count;i++)
     {
       if(y<=y1+i*(h+10))
     {
      choice=i;
      break;
     }
   }
if(prevchoice!=choice)
{
 hidemouseptr();
 if(prevchoice)
 dehighlightv(menu,prevchoice,width,x1,y1,bk_color);
 highlightv(menu,choice,width,x1,y1,color);
 prevchoice=choice;
 showmouseptr();
}
if((button & 1)==1)
{
 while((button & 1)==1)
 getmousepos(&button,&x,&y);
 if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
 {     hidemouseptr();
       putimage(x1-6,y1-11,buffer,COPY_PUT);
       free(buffer)	;
       return(choice);
}
}
}

else
{
   if(in==1)
 {
  in=0; prevchoice=0;
  hidemouseptr();
  dehighlightv(menu,choice,width,x1,y1,bk_color);
  showmouseptr();
}
}
}
}

main_g_window(char *str,int x1,int y1,int x2,int y2,int c)
{
      int button,x,y;
      setcolor(BLACK);
      //rectangle(x1,y1+1,x2+1,y2+1);
      setcolor(8);
      //rectangle(x1,y1+1,x2,y2);
      setcolor(WHITE);
      //rectangle(x1,y1,x2-1,y2-1);
      setfillstyle(SOLID_FILL,LIGHTBLUE);
      bar(x1+1,y1+1,x2-1,y2-1);  //main bar     7
      setcolor(WHITE);
      setfillstyle(SOLID_FILL,c);
      bar(x1+3,y1+3,x2-3,y1+19);  //  sub bar
      settextstyle(SMALL_FONT,0,5);
      setcolor(WHITE);
      outtextxy(x1+25,y1+2,str);
      setcolor(YELLOW);
      outtextxy(x1+7,y1,"/");
      outtextxy(x1+8,y1,"/");
      outtextxy(x1+9,y1+2,"/");
      outtextxy(x1+10,y1+2,"/");
      outtextxy(x1+11,y1+4,"/");
      outtextxy(x1+12,y1+4,"/");
      minimise_button(x2-48,y1+8);
      maximize_button(x2-32,y1+8);
      close_button(x2-15,y1+8);
      setfillstyle(SOLID_FILL,LIGHTGREEN);
      bar(x1+5,y1+42,x2-7,y2-23);    //  sub sub bar   7
      setcolor(8);
      line(x1+4,y1+41,x2-5,y1+41);
      line(x1+4,y1+41,x1+4,y2-21);
      setcolor(BLACK);
      line(x1+5,y1+42,x2-6,y1+42);
      line(x1+5,y1+42,x1+5,y2-22);
      setcolor(WHITE);
      line(x1+4,y2-20,x2-5,y2-20);
      line(x2-4,y1+41,x2-4,y2-20);
      getmousepos(&button,&x,&y);

   if(x>=x2-20 && x<=x2-6 && y>=y1+5 && y<=y1+17)
   {
     if((button & 1)==1)
    { hidemouseptr(); exit(0); }
  }
}


highlight_select(char **menu,int ch,int x1,int y1)
{   
 int xc=x1,tw,tw1,i;
 for(i=1;i<=ch;i++)
 { xc=xc+textwidth(menu[i-1])+10; }
 tw=textwidth(menu[ch-1]);
 setcolor(8);
 line(xc-10-tw,y1,xc,y1);
 line(xc-10-tw,y1,xc-10-tw,y1+17);
 setcolor(WHITE);
 line(xc-10-tw,y1+17,xc,y1+17);
 line(xc,y1,xc,y1+17);
}
dehighlight(char **menu,int ch,int x1,int y1)
 {   
  int xc=x1,tw,tw1,i;
  for(i=1;i<=ch;i++)
  { xc=xc+textwidth(menu[i-1])+10; } 
  tw=textwidth(menu[ch-1]);
  setcolor(7);
  line(xc-10-tw,y1,xc,y1);
  line(xc-10-tw,y1,xc-10-tw,y1+17);
  setcolor(7);
  line(xc-10-tw,y1+17,xc,y1+17);
  line(xc,y1,xc,y1+17);
}

displaymenuh(char **menu,int count,int x1,int y1)
{
      int i,tw,xc;
      xc=x1;
      setfillstyle(SOLID_FILL,7);
       //	bar(x1-3,y1,x1+500,y1+17);
      bar(20,y1,612,y1+17);
      settextstyle(SMALL_FONT,0,4);
       setcolor(BLACK);
      for(i=0;i<count;i++)
      {     tw=textwidth(menu[i]);
	    outtextxy(xc,y1+2,menu[i]);
	    xc=xc+tw+10;
      }
}
displaymenuv(char **menu,int count,int width,int x1,int y1,int bk_color)
{  
   int i,h;
 setcolor(0);
 h=textheight(menu[0]);
 rectangle(x1-5,y1-10,x1+width+12,y1+count*(h+10)+10);
 setcolor(8);
 rectangle(x1-5,y1-10,x1+width+11,y1+count*(h+10)+9);
 setcolor(WHITE);
 rectangle(x1-5,y1-10,x1+width+10,y1+count*(h+10)+8);
 setfillstyle(SOLID_FILL,bk_color);
 bar(x1-4,y1-9,x1+width+10,y1+count*(h+10)+8);
 settextstyle(SMALL_FONT,0,4);
 setcolor(BLACK); 
 for(i=0;i<count;i++)
 { outtextxy(x1+10,y1+i*(h+10),menu[i]); }

}

getresponseh(char **menu,int count,int x1,int y1)
{ 
int choice=1,prevchoice=0,x,y,x2,y2,button;
 int in,i,h,tw,xc;
 h=textheight(menu[0]);
 y2=y1+h+6; x2=x1;
 displaymenuh(menu,count,x1,y1);
 for(i=0;i<count;i++)
 {x2=x2+textwidth(menu[i])+10;}
 showmouseptr();
 while(1)
 {
  getmousepos(&button,&x,&y);
  getmousepos(&button,&x,&y);
  if(x>=630-20 && x<=630-6 && y>=5+5 && y<=5+17)
      {     if((button & 1)==1)
      {
       hidemouseptr();
	       exit(0);
      } 
     }
  settextstyle(SMALL_FONT,0,4);
  if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
  {     in=1;
        xc=x1;
         for(i=1;i<=count;i++)
         {
          settextstyle(SMALL_FONT,0,4);
         xc=xc+textwidth(menu[i-1])+10;
         if(x<=xc)
         {
 		 choice=i;
           break;
           }
        }
 if(prevchoice!=choice)
{ 
   hidemouseptr();
  if(prevchoice)
  dehighlight(menu,prevchoice,x1,y1);
  highlight(menu,choice,x1,y1);
  prevchoice=choice; showmouseptr();
}
if((button & 1)==1)
{  
  //  outtextxy(100,300,"YES");
  while((button & 1)==1)
  getmousepos(&button,&x,&y);
  if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
  {
   // outtextxy(100,300,"NO***");
   hidemouseptr();
   highlight_select(menu,choice,x1,y1);
   return(choice);
   }
  }
 }
 else
  {
     if(in==1) 
    { 
     in=0; prevchoice=0;hidemouseptr();
     dehighlight(menu,choice,x1,y1);
     showmouseptr();
    }
  }
 }
}


drop_down_menu(char **menu,int count,int x1,int y1,int color,int bk_color)
{     int i,width=0;
      for(i=0;i<count;i++)
      {
	    if(textwidth(menu[i])>width)
	    { width=textwidth(menu[i]); }
      }
      width=width+30;
      showmouseptr();
     // displaymenuv(menu,count,x1,y1,bk_color,7);
      getresponsev(menu,count,width,x1,y1,color,bk_color);
    /*  displaymenuv(menuvF,countvF,xco1,yco1,BLUE,7);
      exit(-1);    */
}

void esckey2()
{
char *menu[]={" File"," Edit","----------------- Dangerous Dave developed by The Alien v2.0.1.1----------------------" };
char *menuvF[]={"New Game","Continue Game","Start level again","Quit"};
char *menuvE[]={"Difficulty","Controls","Instructions","Quit"};
/*char *menuvR[]={"Run","Go to Cursor","Trace into"};
char *menuvC[]={"Compile","Make","Link","Build All"};
char *menuvP[]={"Open Project","Close Project"};   */
{
 int gd=DETECT,gm,choice,i,count,countvF,countvE,countvR,countvC,countvP;
 int choicev,xco=20,yco=27,xco1=22,yco1=56,xco2=60,yco2=56,ch;
 //initgraph(&gd,&gm,"c:\\tc\\bgi");
 //setbkcolor(BLACK);
  main_g_window("Pause Menu",5,5,630,175,BLUE);
  if(initmouse()==0)
  {     cout<<"\n Unable to initialise Mouse";  exit(0);
  }
 showmouseptr();
 count=sizeof(menu)/sizeof(char*);
 countvF=sizeof(menuvF)/sizeof(char*);
 countvE=sizeof(menuvE)/sizeof(char*);
/*countvR=sizeof(menuvR)/sizeof(char*);
countvC=sizeof(menuvC)/sizeof(char*);
countvP=sizeof(menuvP)/sizeof(char*);   */

  settextstyle(SMALL_FONT,0,6);
  setcolor(BLACK);
  displaymenuh(menu,count,xco,yco);
/* displaymenuv(menuvF,countvF,50,100,100,BLUE);    */
  showmouseptr();
// outtextxy(120,25,"Dangerous Dave developed by The Alien");
int lpvar=1;
      while(lpvar)
{     choice=getresponseh(menu,count,xco,yco);

switch(choice)
{
case 1:
 choicev=drop_down_menu(menuvF,countvF,xco1,xco2,BLUE,7);
 //displaymenuv(menuvF,countvF,xco1,yco1,BLUE,7);
 if(choicev==1)
 {
  cleardevice();
  loadscreen();
  lpvar=0;
 }
 if(choicev==2)
 {
  cleardevice();
  plot();
  lpvar=0;
 }
 if(choicev==3)
 {
  cleardevice();
  plot();
  lpvar=0;
 }
 if(choicev==4)
 {
  exit(-1);
  endscreen();
  lpvar=0;
 }
break;
case 2: choicev=drop_down_menu(menuvE,countvE,xco2,yco2,BLUE,7);
 if(choicev==1)
 { controls();lpvar=0; }
 if(choicev==2)
 { controls();lpvar=0;}
 if(choicev==3)
 { instructions();lpvar=0;}
 if(choicev==4)
 { endscreen(); lpvar=0; }
break;
}
}
}
}
