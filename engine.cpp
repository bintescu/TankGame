#include "engine.h"
#include <iostream>
using namespace std;
void engine::init(int a,int b)
{
    this->nl = a;
    this->nc = b;
}

int engine::getnc()
{
    return this->nc;
}

int engine::getnl()
{
    return this->nl;
}

int engine::getnu()
{
    return this->nu;
}

int engine::validxy(int x,int y)
{
    if(x>0 && x<nl-1 && y>0 && y <nc-1)
    {
        return 1;
    }
    return 0;
}

int engine::validpoz(int a)
{
    if(a>0 && a <nu)
    {
        return 1;
    }
    return 0;
}

unit * engine::getunitxy(int x,int y)
{

        if(unittab[x][y] != NULL)
        {
        return unittab[x][y];
        }
        else
        {
            return NULL;
        }
}

unit * engine::getunitpoz(int z)
{
    return unitvect[z];
}

void engine::next()
{
    for(int i=0;i<nu;i++)
    {
        (*unitvect[i]).action();
    }
    for(int i=0;i<nu;i++)
    {
        (*unitvect[i]).react();
    }
    for(int i=0;i<nu-1;i++)
    {
        if((*unitvect[i]).alive == 0 )
        {
            for(int j=i;j<nu;j++)
            {
                unitvect[j] = unitvect[j+1];
            }
            nu--;
            int x=(*unitvect[i]).x;
            int y=(*unitvect[i]).gety();
            unittab[x][y] = NULL;
            delete unittab[x][y] ;
        }
    }

}

void unit::react()
{
    for(int i=0;i<nm;i++)
    {
        if(alive)
        {
            behaviour(message[i]);
        }
    }
    nm=0;
}
engine unit::motor;

unit::unit(int a,int b)
{
    x=a;
    y=b;
    nm=0;
    alive =1;
   if(motor.nu < MAXNU && motor.unittab[a][b] == NULL)
        {
            motor.unitvect[motor.nu] = this;
            motor.unittab[a][b] = this;
            if(a > motor.nl) {motor.nl=a+2;}
            if(b > motor.nc) {motor.nc=b+2;}
            motor.nu++;
        }
    poz = motor.nu-1;
}

void unit::die()
{
    this->alive =0;
}

void unit::Move(int dx, int dy)
{
    if(motor.unittab[x+dx][y+dy] == NULL && motor.validxy(x+dx,y+dy))
      {
          motor.unittab[x][y] = NULL;
          delete motor.unittab[x][y];
          motor.unittab[x+dx][y+dy] = this;
            x=x+dx;
            y=y+dy;


      }

}

void unit::recept(int pm)
{
    if(nm < MAXNM-1)
    {
        message[nm] = pm;
        nm++;
    }
}
void unit::sendmes(int pm,unit &pu)
{
  pu.recept(pm);

}

int unit::getx()
{
   return x;
}

int unit::gety()
{
    return y;
}

unit &unit::operator=(const unit &a)
{
        this->x=a.x;
        this->y=a.y;
        this->poz = a.poz;
        this->alive = a.alive;
        this->nm = a.nm;
        for(int i=0;i<a.nm;i++)
        {
        this->message[i] = a.message[i];
        }
        return *this;

}
