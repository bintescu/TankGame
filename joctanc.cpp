#include <iostream>
#include <cstring>
#include "joctanc.h"
using namespace std;
unsigned char zid::name = 177;
zid::zid(int a,int b):unit(a,b)
{
}

void *zid::gettip()
{
    return &name;
}
char bomba::nume = 42;

void bomba::action()
{
    int xn = getx() + dirx;
    int yn = gety() + diry;

    if(motor.validxy(xn,yn))
    {
        if(motor.getunitxy(xn,yn)==NULL)
        {
            Move(dirx,diry);
        }
        else
        {
            sendmes(1,*motor.getunitxy(xn,yn));
            die();
        }
    }
    else
        die();
}

void bomba::behaviour(int a)
{
    if(a==1) die();
}

bomba::bomba(int x,int y, int direX,int direY): unit(x,y)
{
        dirx = direX;
        diry = direY;
}

void * bomba::gettip()
{
       return &nume;
}

int tanc::cc = 0;


void tanc::action()
{
    if(cc == st)
        {
            if(motor.getunitxy(this->getx(),this->gety()-1) == NULL)
            {
                Move(0,-1);
                pc = cc;
            }
        }

    if(cc == dr)
        {
            if(motor.getunitxy(this->getx(),this->gety()+1) == NULL)
            {
                Move(0 , 1);
                pc = cc;
            }
        }

    if(cc == sus)
        {
            if(motor.getunitxy(this->getx()-1,this->gety()) == NULL)
            {
                Move(-1 , 0);
               pc = cc;
            }
        }
    if(cc == jos)
        {
            if(motor.getunitxy(this->getx()+1,this->gety()) == NULL)
            {
                Move(+1, 0);
                pc = cc;
            }
        }
       /// DACA COMANDA ESTE FOC!!
        if(cc == foc)
        {
                if(pc == st)
                {
                    int bx,by;
                    bx = this->getx();
                    by = this->gety()-1;
                    if(motor.getunitxy(bx,by) == NULL)
                    {
                        new bomba(bx,by,0,-1);
                    }
                    else
                    {
                        sendmes(1,*motor.getunitxy(bx,by));
                    }
                }

                if(pc == dr)
                {
                    int bx,by;
                    bx = this->getx();
                    by = this->gety()+1;
                    if(motor.getunitxy(bx,by) == NULL)
                    {
                        new bomba(bx,by,0,+1);
                    }
                    else
                    { cout<<"\n moare ";
                        sendmes(1,*motor.getunitxy(bx,by));
                    }
                }
                if(pc == sus)
                {
                    int bx,by;
                    bx = this->getx()-1;
                    by = this->gety();
                    if(motor.getunitxy(bx,by) == NULL)
                    {
                        new bomba(bx,by,-1,0);
                    }
                    else
                    {
                        sendmes(1,*motor.getunitxy(bx,by));
                    }
                }
                if(pc == jos)
                {
                    int bx,by;
                    bx = this->getx()+1;
                    by = this->gety();
                    if(motor.getunitxy(bx,by) == NULL)
                    {
                        new bomba(bx,by,+1,0);
                    }
                    else
                    {
                        sendmes(1,*motor.getunitxy(bx,by));
                    }
                }
        }
    }

void tanc::behaviour(int a)
{
    if(a==1) die();
}

tanc::tanc(char* nume,int st,int dr,int sus,int jos,int foc,int a,int b): unit(a,b)
{
    strcpy(this->nume,nume);
    this->st = st;
    this->dr = dr;
    this->sus = sus;
    this->jos = jos;
    this->foc=foc;
}

void * tanc::gettip()
{
    return &nume;
}
