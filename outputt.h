#ifndef OUTPUTT_H_INCLUDED
#define OUTPUTT_H_INCLUDED
#include "engine.h"
class outputt
{
private:
    engine &motor;
    static int pictvect[MAXNU][2],npict;
    char M[MAXNL][MAXNC]={};
public:
    outputt(engine &pm):motor(pm){};
    void init();
    void close();
    void afisare();
    void desen();
    int getNpict(){return npict;}

};


#endif // OUTPUTT_H_INCLUDED
