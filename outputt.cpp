#include <conio.h>
#include <iostream>
#include "outputt.h"
#include "joctanc.h"
#include <windows.h>
using namespace std;
int outputt::npict=0;
int outputt::pictvect[MAXNU][2]={};
void outputt::init()
{
   int P=219;
   int c=0;
    for(int i=0; i<MAXNL; i++)
    {
        M[i][0]=P;
    }
    for(int i=0; i<MAXNL; i++)
    {
        M[i][MAXNC-1]=P;
    }
    for(int j=0; j<MAXNC; j++)
    {
        M[MAXNL-1][j]=P;
    }
    for(int j=0; j<MAXNC; j++)
    {
        M[0][j]=P;
    }

    //zidurile

    for(int i=MAXNL/8;i<(3*MAXNL)/4;i++)
    {
        M[i][MAXNC/6]=177;
        int a=i;
        int b=MAXNC/6;
        new zid(a,b);
        pictvect[c][0]=a;
        pictvect[c][1]=b;
        c++;
    }

    for(int i=1;i<(MAXNL/2-MAXNL/5);i++)
    {
        M[i][MAXNC/3]=177;
        int a=i;
        int b=MAXNC/3;
        new zid(a,b);
        pictvect[c][0]=a;
        pictvect[c][1]=b;
        c++;
    }
    for(int i=MAXNL-2;i>=(MAXNL/2);i--)
    {
        M[i][MAXNC/3]=177;
        int a=i;
        int b=MAXNC/3;
        new zid(a,b);
        pictvect[c][0]=a;
        pictvect[c][1]=b;
        c++;
    }

    for(int j=MAXNC/3+1;j<=(MAXNC/3+1+MAXNC/5);j++)
    {
        M[MAXNL/2][j]=177;
        int a=MAXNL/2;
        int b=j;
        new zid(a,b);
        pictvect[c][0]=a;
        pictvect[c][1]=b;
        c++;
    }

    for(int i=MAXNL/8;i<(3*MAXNL)/4;i++)
    {
        M[i][5*MAXNC/6]=177;
        int a=i;
        int b=5*MAXNC/6;
        new zid(a,b);
        pictvect[c][0]=a;
        pictvect[c][1]=b;
        c++;
    }

    for(int i=MAXNL/12;i<=(MAXNL/12+MAXNL/4);i++)
    {
        if(i!=(MAXNL/12+MAXNL/4)/2)
            {
                M[i][MAXNC/3+MAXNC/6]=177;
                int a=i;
                int b=MAXNC/3+MAXNC/6;
                new zid(a,b);
                pictvect[c][0]=a;
                pictvect[c][1]=b;
                c++;
            }
    }

    for(int i=(MAXNC/3+MAXNC/6+1);i<=(MAXNC/3+MAXNC/6+MAXNC/14);i++)
    {
        M[MAXNL/12][i]=177;
        int a=MAXNL/12;
        int b=i;
        new zid(a,b);
        pictvect[c][0]=a;
        pictvect[c][1]=b;
        c++;
    }

    for(int i=(MAXNC/3+MAXNC/6+1);i<=(MAXNC/3+MAXNC/6+MAXNC/14);i++)
    {
        M[MAXNL/12+MAXNL/4][i]=177;
        int a=MAXNL/12+MAXNL/4;
        int b=i;
        new zid(a,b);
        pictvect[c][0]=a;
        pictvect[c][1]=b;
        c++;
    }

  npict=c;
}

void outputt::close()
{
    cout<<"\n Am incheiat sesiunea!";
};
void outputt::desen()
{
    for(int i=0;i<MAXNL;i++)
    {
        cout<<"\n";
        for(int j=0;j<MAXNC;j++)
            cout<<M[i][j];
    }
}
void outputt::afisare()
{
  for(int i=0;i<npict;i++)
  {
      M[pictvect[i][0]][pictvect[i][1]]=' ';
  }
  npict=0;
  char *a;
  for(int i=0;i<motor.getnu();i++)
  {
      a=(char *)(*motor.getunitpoz(i)).gettip();
      if(a[0]==(char)177)
      {
          int x=(*motor.getunitpoz(i)).getx();
          int y=(*motor.getunitpoz(i)).gety();
          M[x][y]=177;
          pictvect[npict][0]=x;
          pictvect[npict][1]=y;
          npict++;
      }
      else if(a[0]==(char)42)
      {
          int x=(*motor.getunitpoz(i)).getx();
          int y=(*motor.getunitpoz(i)).gety();
          M[x][y]=42;
          pictvect[npict][0]=x;
          pictvect[npict][1]=y;
          npict++;
      }
      else
      {
          int x=(*motor.getunitpoz(i)).getx();
          int y=(*motor.getunitpoz(i)).gety();
          M[x][y]=(int)'X';
          pictvect[npict][0]=x;
          pictvect[npict][1]=y;
          npict++;
      }
      free(a);
      a=NULL;
  }
  cout<<"\n";
  system("cls");
  desen();
}


