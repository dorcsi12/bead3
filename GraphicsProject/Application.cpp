#include "Application.h"
#include "graphics.hpp"
#include "Engine.h"
#include "Adat.h"
#include "Widget.h"
#include "Text.h"
#include  <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace genv;
using namespace std;

Application::Application(int XX, int YY) : XX(XX), YY(YY) {}

void Application::background() {
    gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);
}

void Application::jatekvege() {
    gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY)
        <<move_to(XX/2-gout.twidth("Ügyes vagyok:)"),YY/2)<<color(255,31,143)<<text("Ügyes vagyok:)");
}

void Application::run() {

    srand(time(0));
    gout.open(XX,YY);
    event ev;
    Adat a;
    vector<vector<string>>adatok = a.elkeszit();
    vector<string>sorvektor;

    for(unsigned int i=0; i<adatok.size(); i++) {
        for(unsigned int j=0; j<adatok.size(); j++) {
            sorvektor.push_back(adatok[i][j]);
        }
    }
    vector<int>ures_index;
    vector<Widget*>w;

    for(unsigned int i=0; i<adatok.size(); i++) {
        int a=0;
        int c=0;
        for(unsigned int j=0; j<adatok.size(); j++) {
            Text* t = new Text(100+b,50+a,50,50,adatok[i][j]);
            t->irhatoe=false;
            a=a+52;
            w.push_back(t);
            c++;
        }
        b=b+52;
    }

    for(unsigned int i=0; i<adatok.size(); i++) {
        d=rand() %w.size();
        w[d]->setTexti(" ");
        w[d]->irhatoe=true;
        ures_index.push_back(d);
    }

    background();
    Engine e;
    while(gin >> ev && ev.keycode != key_escape) {
        for(unsigned int i=0; i<w.size(); i++) {
            if(!vege) {
                w[i]->handle(ev);
                w[i]->draw();
            }
            e.ellenorzes(w,i,ures_index,vege,sorvektor);
        }
        for(unsigned int i=0; i<ures.size(); i++) {
            bool rossze = e->ell(w,i,ures_index,vege,sorvektor);
            if(rossze) {


            }

        }


        if(vege&& ev.type!=ev_mouse && ev.keycode==key_enter) {
            jatekvege();
        }

        gout<<refresh;
    }



}



