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
 cout<<"WASD si Q pentru primul tanc :)\n";
 cout<<"IJKL si N pentru al doilea :)\n";
 cout<<"\n Introduceti numele tancului nr 1 : ";
 cin>>nume;
 cout<<"\n Introduceti numele tancului nr 2: ";
 cin>>nume2;
 cout<<"ENTER BOSS\n";
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
