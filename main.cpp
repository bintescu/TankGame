#include <stdio.h>
#include <iostream>
#include "engine.h"
#include "joctanc.h"
#include "outputt.h"
#include "input.h"
#include <conio.h>
#include <windows.h>
#include <cstring>
using namespace std;
input intrare;
outputt iesire(tanc::motor);

int main()
{
 tanc::motor.init(29,99);
 char nume[30];
 char nume2[30];
 strcpy(nume2,"Esteban");
 strcpy(nume,"Alin");
 tanc *T=new tanc(nume,97,100,119,115,113,13,6);
 tanc *T2= new tanc(nume2,106,108,105,107,110,13,90);
 intrare.init();
 iesire.init();
 do
 {
     tanc::cc=intrare.getc();
     tanc::motor.next();
     iesire.afisare();
 }while(tanc::cc!=27);
 intrare.close();
 iesire.close();
 return 0;
}
