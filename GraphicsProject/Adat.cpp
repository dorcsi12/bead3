#include "Adat.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include  <time.h>
using namespace std;


Adat::Adat() {}

Adat::~Adat() {}

void Adat:: beolvas() {
    string a = "";
    ifstream f("alap.txt");
    while(f.good()) {
        getline(f,a);
        vector<string>sor;
        for(unsigned int i=0; i<a.length(); i++) {
            string vmi="";
            vmi += a[i];
            sor.push_back(vmi);
        }
        n.push_back(sor);
        sor.clear();
    }
}

void Adat::kever() {
    srand(time(0));
    std::string s1;
    int sor1 = rand()%2;
    int sor2 = rand()%2+3;
    int sor3 = rand()%2+6;
    int oszlop1 = rand()%2;
    int oszlop2 = rand()%2+3;
    int oszlop3 = rand()%2+6;
    int tombo = rand()%2;

    switch(sor1) {
    case 0:
        for(int i=0; i<9; i++) {
            s1=n[1][i];
            n[1][i]=n[2][i];
            n[2][i]=s1;
        }
        break;
    case 1:
        for(int i=0; i<9; i++) {
            s1=n[0][i];
            n[0][i]=n[2][i];
            n[2][i]=s1;
        }
        break;
    case 2:
        for(int i=0; i<9; i++) {
            s1=n[0][i];
            n[0][i]=n[1][i];
            n[1][i]=s1;
        }
        break;
    }
    switch(sor2) {
    case 3:
        for(int i=0; i<9; i++) {
            s1=n[4][i];
            n[4][i]=n[5][i];
            n[5][i]=s1;
        }
        break;
    case 4:
        for(int i=0; i<9; i++) {
            s1=n[3][i];
            n[3][i]=n[5][i];
            n[5][i]=s1;
        }
        break;
    case 5:
        for(int i=0; i<9; i++) {
            s1=n[3][i];
            n[3][i]=n[4][i];
            n[4][i]=s1;
        }
        break;
    }
    switch(sor3) {
    case 6:
        for(int i=0; i<9; i++) {
            s1=n[7][i];
            n[7][i]=n[8][i];
            n[8][i]=s1;
        }
        break;
    case 7:
        for(int i=0; i<9; i++) {
            s1=n[6][i];
            n[6][i]=n[8][i];
            n[8][i]=s1;
        }
        break;
    case 8:
        for(int i=0; i<9; i++) {
            s1=n[6][i];
            n[6][i]=n[7][i];
            n[7][i]=s1;
        }
        break;
    }
    switch(oszlop1) {
    case 0:
        for(int i=0; i<9; i++) {
            s1=n[i][1];
            n[i][1]=n[i][2];
            n[i][2]=s1;
        }
        break;
    case 1:
        for(int i=0; i<9; i++) {
            s1=n[i][0];
            n[i][0]=n[i][2];
            n[i][2]=s1;
        }
    case 2:
        for(int i=0; i<9; i++) {
            s1=n[i][0];
            n[i][0]=n[i][1];
            n[i][1]=s1;
        }
        break;
    }
    switch(oszlop2) {
    case 3:
        for(int i=0; i<9; i++) {
            s1=n[i][4];
            n[i][4]=n[i][5];
            n[i][5]=s1;
        }
        break;
    case 4:
        for(int i=0; i<9; i++) {
            s1=n[i][3];
            n[i][3]=n[i][5];
            n[i][5]=s1;
        }
        break;
    case 5:
        for(int i=0; i<9; i++) {
            s1=n[i][3];
            n[i][3]=n[i][4];
            n[i][4]=s1;
        }
        break;
    }
    switch(oszlop3) {
    case 6:
        for(int i=0; i<9; i++) {
            s1=n[i][7];
            n[i][7]=n[i][8];
            n[i][8]=s1;
        }
        break;
    case 7:
        for(int i=0; i<9; i++) {
            s1=n[i][6];
            n[i][6]=n[i][8];
            n[i][8]=s1;
        }
        break;
    case 8:
        for(int i=0; i<9; i++) {
            s1=n[i][6];
            n[i][6]=n[i][8];
            n[i][8]=s1;
        }
        break;
    }

vector<vector<string> >seged = n;
    for(unsigned int i = 0; i < n.size(); i++){
        for(unsigned int j = 0; j < n.size(); j++){
            n[i][j] = seged[j][i];
        }
    }
}

vector<vector<string>> Adat:: elkeszit(){
beolvas();
srand(time(0));
int szam=rand()%7;
for(int i=0;i<szam;i++){
    kever();
}
return n;
}
