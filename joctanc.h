#ifndef JOCTANC_H_INCLUDED
#define JOCTANC_H_INCLUDED
#include "engine.h"
class zid : public unit
{
private:
    static unsigned char name;
protected:
    void action(){};
    void behaviour(int a){};
public:
    zid(int a, int b);
public:
    void* gettip();

};

class bomba:public unit
{
private:
    static char nume ;
    int dirx;
    int diry;
protected:
    void action();
    void behaviour(int a);

public:
    bomba(int x,int y, int direX,int direY);
   void* gettip();
};


class tanc:public unit
{
public:
    static int cc;
private:
    char nume[20] ;
    int st,dr,sus,jos,foc;
    int pc;
protected:
    void action();
    void behaviour(int);
public:
    tanc(char* nume,int st,int dr,int sus,int jos,int foc,int a,int b);
    void *gettip();
};
#endif
