//outputt.cpp
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "outputt.h"
#include "joctanc.h"

using namespace std;

int outputt::npict = 0;
int outputt::pictvect[MAXNU][2] = {};

void outputt::init() {
    int simbolBord = 219;
    int contor = 0;

    // Inițializează toată matricea cu spații
    for (int i = 0; i < MAXNL; i++) {
        for (int j = 0; j < MAXNC; j++) {
            M[i][j] = ' ';
        }
    }
    // Desenează bordurile
    for (int i = 0; i < MAXNL; i++) {
        M[i][0] = simbolBord;
        M[i][MAXNC - 1] = simbolBord;
    }
    for (int j = 0; j < MAXNC; j++) {
        M[0][j] = simbolBord;
        M[MAXNL - 1][j] = simbolBord;
    }

    // Ziduri verticale și orizontale cu salvare în pictvect

    // Zid vertical stânga
    for (int i = MAXNL / 8; i < (3 * MAXNL) / 4; i++) {
        M[i][MAXNC / 6] = 177;
        new zid(i, MAXNC / 6);
        pictvect[contor][0] = i;
        pictvect[contor][1] = MAXNC / 6;
        contor++;
    }

    // Zid vertical centru-sus
    for (int i = 1; i < (MAXNL / 2 - MAXNL / 5); i++) {
        M[i][MAXNC / 3] = 177;
        new zid(i, MAXNC / 3);
        pictvect[contor][0] = i;
        pictvect[contor][1] = MAXNC / 3;
        contor++;
    }

    // Zid vertical centru-jos
    for (int i = MAXNL - 2; i >= (MAXNL / 2); i--) {
        M[i][MAXNC / 3] = 177;
        new zid(i, MAXNC / 3);
        pictvect[contor][0] = i;
        pictvect[contor][1] = MAXNC / 3;
        contor++;
    }

    // Zid orizontal centru
    for (int j = MAXNC / 3 + 1; j <= (MAXNC / 3 + 1 + MAXNC / 5); j++) {
        M[MAXNL / 2][j] = 177;
        new zid(MAXNL / 2, j);
        pictvect[contor][0] = MAXNL / 2;
        pictvect[contor][1] = j;
        contor++;
    }

    // Zid vertical dreapta
    for (int i = MAXNL / 8; i < (3 * MAXNL) / 4; i++) {
        M[i][5 * MAXNC / 6] = 177;
        new zid(i, 5 * MAXNC / 6);
        pictvect[contor][0] = i;
        pictvect[contor][1] = 5 * MAXNC / 6;
        contor++;
    }

    // Zid vertical cu pauză la mijloc
    for (int i = MAXNL / 12; i <= (MAXNL / 12 + MAXNL / 4); i++) {
        if (i != (MAXNL / 12 + MAXNL / 4) / 2) {
            M[i][MAXNC / 3 + MAXNC / 6] = 177;
            new zid(i, MAXNC / 3 + MAXNC / 6);
            pictvect[contor][0] = i;
            pictvect[contor][1] = MAXNC / 3 + MAXNC / 6;
            contor++;
        }
    }

    // Zid orizontal sus dreapta
    for (int j = MAXNC / 3 + MAXNC / 6 + 1; j <= (MAXNC / 3 + MAXNC / 6 + MAXNC / 14); j++) {
        M[MAXNL / 12][j] = 177;
        new zid(MAXNL / 12, j);
        pictvect[contor][0] = MAXNL / 12;
        pictvect[contor][1] = j;
        contor++;
    }

    // Zid orizontal jos dreapta
    for (int j = MAXNC / 3 + MAXNC / 6 + 1; j <= (MAXNC / 3 + MAXNC / 6 + MAXNC / 14); j++) {
        M[MAXNL / 12 + MAXNL / 4][j] = 177;
        new zid(MAXNL / 12 + MAXNL / 4, j);
        pictvect[contor][0] = MAXNL / 12 + MAXNL / 4;
        pictvect[contor][1] = j;
        contor++;
    }

    npict = contor;
}

void outputt::close() {
    cout << "\n Am incheiat sesiunea!";
}

void outputt::desen() {
    for (int i = 0; i < MAXNL; i++) {
        cout << "\n";
        for (int j = 0; j < MAXNC; j++) {
            cout << M[i][j];
        }
    }
}

void outputt::afisare() {
    // Curățare elemente vechi
    for (int i = 0; i < npict; i++) {
        M[pictvect[i][0]][pictvect[i][1]] = ' ';
    }
    npict = 0;

    for (int i = 0; i < motor.getnu(); i++) {
        char* tip = (char*)(*motor.getunitpoz(i)).gettip();
        int x = (*motor.getunitpoz(i)).getx();
        int y = (*motor.getunitpoz(i)).gety();

        if (tip[0] == (char)177) {
            M[x][y] = 177;
        } else if (tip[0] == '*') {
            M[x][y] = '*';
        } else {
            M[x][y] = 'X';
        }

        pictvect[npict][0] = x;
        pictvect[npict][1] = y;
        npict++;

        free(tip);
        tip = NULL;
    }

    cout << "\n";
    system("cls");
    desen();
}
