#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

void menu()
{
   settextstyle(7 ,0,3);
   setcolor(9);
   outtextxy(50,50,"Welcome to X-O!");
   setcolor(4);
   outtextxy(200,100,"1. Play");
  setcolor(7);
   outtextxy(200,150,"2. Instructions");
   setcolor(2);
   outtextxy(200,200,"3. Credits");
   setcolor(11);
   outtextxy(200,250,"Press Q to Exit.");
   setcolor(9);
   outtextxy(45,350,"Copyright (C) Infect 2010 all rights reserved.");
   line(50,80,500,80);
   line(50,300,500,300);
}

void mode_selectq()
{
   settextstyle(7 ,0,3);
   setcolor(9);
   outtextxy(50,50,"Welcome to X-O!");
   setcolor(4);
   outtextxy(200,100,"1. Play");
  setcolor(7);
   outtextxy(200,150,"2. Introductions");
   setcolor(2);
   outtextxy(200,200,"3. Credits");
   setcolor(11);
   outtextxy(200,250,"Press Q to Exit.");
   setcolor(9);
   outtextxy(110,350,"Copyright (C) 2010 all rights reserved.");
   line(50,80,500,80);
   line(50,300,500,300);
}


void credits()
{
	  //cleardevice();
	  settextstyle(7 ,0,8);
	  outtextxy(170,10,"Credits:");
		  settextstyle(7 ,0,3);
		  setcolor(11);
	  outtextxy(230,150,"Ray");
		  settextstyle(7 ,0,3);
		  setcolor(4);
	  outtextxy(230,200,"(known as FightRay)");
		  setcolor(2);
		  settextstyle(3,0,2);
	  outtextxy(150,450,"Press any key to return to the Menu.");
}

void introductions()
{
  setcolor(10);
  settextstyle(4,0,5);
  outtextxy(200,10,"Introductions:");
  settextstyle(3,0,2);
  setcolor(3);
  outtextxy(50,100,"Each square has a number.");
  outtextxy(50,150,"to draw an X/O, you press one of the numbers.");
  outtextxy(50,200,"when you press a number, the turn goes to the other");
  outtextxy(50,250,"player. remember that you can't press the same number");
  outtextxy(50,300,"more than once.");
  setcolor(2);
  outtextxy(150,450,"Press any key to return to the Menu.");
}

void DrawGame()
{
    setcolor(3);
    settextstyle(4,0,5);
    outtextxy(80,10,"Press a number to continiue");
    settextstyle(3,0,2);
    //outtextxy(80,70,"Waiting for player:");
    settextstyle(3,0,5);
    setcolor(6);
    outtextxy(120,100,"1");
    outtextxy(310,100,"2");
    outtextxy(500,100,"3");
    outtextxy(120,200,"4");
    outtextxy(310,200,"5");
    outtextxy(500,200,"6");
    outtextxy(120,300,"7");
    outtextxy(310,300,"8");
    outtextxy(500,300,"9");
    line(50,100,600,100);
    line(50,200,600,200);
    line(50,300,600,300);
    line(50,400,600,400);
    line(50,100,50,400);
    line(220,100,220,400);
    line(430,100,430,400);
    line(600,100,600,400);
    setcolor(2);
    settextstyle(3,0,2);
    outtextxy(150,450,"Press 'R' to return to the Menu.");
}
void DrawX(int x,int y)
{
   settextstyle(3,0,6);
   setcolor(7);
   outtextxy(x,y,"X");
}
void DrawO(int x,int y)
{
   settextstyle(3,0,6);
   setcolor(7);
   outtextxy(x,y,"O");
}
void TogglePlayer(char turn)
{
 if(turn=='X')
 {
  turn='O';
 }
 else if(turn=='O')
 {
  turn='X';
 }
}
void DrawXwin()
{
   settextstyle(7 ,0,8);
   setcolor(10);
   outtextxy(140,180,"X Wins!!!");
}
void DrawOwin()
{
   settextstyle(7 ,0,8);
   setcolor(10);
   outtextxy(140,180,"O Wins!!!");
}
void main()
{
  int gd,gm;
  int xmax, ymax, cod,r,i,x1,x,y1,y,xmid,ymid,c,w,t,m;
  char turn;
  int totalsquares;
  int screenstate = 1; // 1-menu, 2-game, 3-introductions, 4-credits, 5-mode select.

  int board[10];

  gd=DETECT;

  initgraph(&gd,&gm,"c:/tc/bgi");
  xmax=getmaxx();
  ymax=getmaxy();
  ymid=ymax/2;
  xmid=xmax/2;
  randomize();
  cleardevice();

do{
if (screenstate==1)
{
for(i=0;i<10;i++)
  {
     board[i]=0;
  }
turn='X';
totalsquares=0;
//cod=getche();
  menu();
  cod=getche();
if(cod=='1')
{
 cleardevice();
 screenstate=2;
 cod='78';
}
if(cod=='3')
  {
  cleardevice();
  screenstate=4;
  cod='78';
  }
if(cod=='2')
  {
  cleardevice();
  screenstate=3;
  cod='78';
  }
  /*
if(cod=='q')
  {
  cleardevice();
  close();
  }
  */
}

else if (screenstate==2)
{
  //0-empty, 1-'X', 2-'O'.
  //char turn='X';
  //int totalsquares=0;
  DrawGame();
  cod=getche();
  if (cod=='1' && board[1]==0)
  {
    if(turn=='X')
    {
     DrawX(120,130);
     board[1]=1;
     turn='O';
    }
    else if(turn=='O')
    {
     DrawO(120,130);
     board[1]=2;
     turn='X';
    }
    //TogglePlayer(turn);
  }
  else if (cod=='2' && board[2]==0)
  {
    if(turn=='X')
    {
     DrawX(310,130);
     board[2]=1;
     turn='O';
    }
    else if(turn=='O')
    {
     DrawO(310,130);
     board[2]=2;
     turn='X';
    }
    //TogglePlayer(turn);
  }
  else if (cod=='3' && board[3]==0)
  {
    if(turn=='X')
    {
     DrawX(500,130);
     board[3]=1;
     turn='O';
    }
    else if(turn=='O')
    {
     DrawO(500,130);
     board[3]=2;
     turn='X';
    }
    //TogglePlayer(turn);
  }
  else if (cod=='4' && board[4]==0)
  {
    if(turn=='X')
    {
     DrawX(120,230);
     board[4]=1;
     turn='O';
    }
    else if(turn=='O')
    {
     DrawO(120,230);
     board[4]=2;
     turn='X';
    }
    //TogglePlayer(turn);
  }
  else if (cod=='5' && board[5]==0)
  {
    if(turn=='X')
    {
     DrawX(310,230);
     board[5]=1;
     turn='O';
    }
    else if(turn=='O')
    {
     DrawO(310,230);
     board[5]=2;
     turn='X';
    }
    //TogglePlayer(turn);
  }
  else if (cod=='6' && board[6]==0)
  {
    if(turn=='X')
    {
     DrawX(500,230);
     board[6]=1;
     turn='O';
    }
    else if(turn=='O')
    {
     DrawO(500,230);
     board[6]=2;
     turn='X';
    }
    //TogglePlayer(turn);
  }
  else if (cod=='7' && board[7]==0)
  {
    if(turn=='X')
    {
     DrawX(120,330);
     board[7]=1;
     turn='O';
    }
    else if(turn=='O')
    {
     DrawO(120,330);
     board[7]=2;
     turn='X';
    }
    //TogglePlayer(turn);
  }
  else if (cod=='8' && board[8]==0)
  {
    if(turn=='X')
    {
     DrawX(310,330);
     board[8]=1;
     turn='O';
    }
    else if(turn=='O')
    {
     DrawO(310,330);
     board[8]=2;
     turn='X';
    }
    //TogglePlayer(turn);
  }
  else if (cod=='9' && board[9]==0)
  {
    if(turn=='X')
    {
     DrawX(500,330);
     board[9]=1;
     turn='O';
    }
    else if(turn=='O')
    {
     DrawO(500,330);
     board[9]=2;
     turn='X';
    }
    //TogglePlayer(turn);
  }
  if(board[1]==1 && board[4]==1 && board[7]==1)
  {
   cod='78';
   cleardevice();
   DrawXwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }
  else if(board[1]==2 && board[4]==2 && board[7]==2)
  {
   cod='78';
   cleardevice();
   DrawOwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }

  if(board[2]==1 && board[5]==1 && board[8]==1)
  {
   cod='78';
   cleardevice();
   DrawXwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }
  else if(board[2]==2 && board[5]==2 && board[8]==2)
  {
   cod='78';
   cleardevice();
   DrawOwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }

  if(board[3]==1 && board[6]==1 && board[9]==1)
  {
   cod='78';
   cleardevice();
   DrawXwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }
  else if(board[3]==2 && board[6]==2 && board[9]==2)
  {
   cod='78';
   cleardevice();
   DrawOwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }

  if(board[1]==1 && board[2]==1 && board[3]==1)
  {
   cod='78';
   cleardevice();
   DrawXwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }
  else if(board[1]==2 && board[2]==2 && board[3]==2)
  {
   cod='78';
   cleardevice();
   DrawOwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }

  if(board[4]==1 && board[5]==1 && board[6]==1)
  {
   cod='78';
   cleardevice();
   DrawXwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }
  else if(board[4]==2 && board[5]==2 && board[6]==2)
  {
   cod='78';
   cleardevice();
   DrawOwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }

  if(board[7]==1 && board[8]==1 && board[9]==1)
  {
   cod='78';
   cleardevice();
   DrawXwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }
  else if(board[7]==2 && board[8]==2 && board[9]==2)
  {
   cod='78';
   cleardevice();
   DrawOwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }

  if(board[1]==1 && board[5]==1 && board[9]==1)
  {
   cod='78';
   cleardevice();
   DrawXwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }
  else if(board[1]==2 && board[5]==2 && board[9]==2)
  {
   cod='78';
   cleardevice();
   DrawOwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }

  if(board[3]==1 && board[5]==1 && board[7]==1)
  {
   cod='78';
   cleardevice();
   DrawXwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }
  else if(board[3]==2 && board[5]==2 && board[7]==2)
  {
   cod='78';
   cleardevice();
   DrawOwin();
   cod=getche();
   while(cod=='78');
   cleardevice();
   screenstate=1;
  }

  if(cod=='r')
  {
  cleardevice();
  screenstate=1;
  }
}
else if (screenstate==3)
{
  introductions();
  cod=getche();
  while(cod=='78');
  cleardevice();
  screenstate=1;
}
else if (screenstate==4)
{
  credits();
  cod=getche();
  while(cod=='78');
  cleardevice();
  screenstate=1;
}



}   while(cod!='q');
    closegraph();
    close(0);
 }




/*
 {
   cleardevice();
   setcolor(6);
   setfillstyle (3,4);
   circle (xmax/2, ymax/2, 150);
   floodfill(xmax/2, ymax/2, 6);

   while (!kbhit());
   cleardevice();

 }

 */









