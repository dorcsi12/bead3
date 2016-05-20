#include "Application.h"
#include "graphics.hpp"
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

void Application::jatekvege(){
gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY)
<<move_to(XX/2-gout.twidth("Ügyes vagyok:)"),YY/2)<<color(255,31,143)<<text("Ügyes vagyok:)");
}

void Application::run() {

    srand(time(0));
    gout.open(XX,YY);
    event ev;
    Adat a;
    vector<vector<string>>adatok = a.elkeszit();
    vector<string>fasz;
    for(int i=0; i<adatok.size(); i++) {
        for(int j=0; j<adatok.size(); j++) {
            fasz.push_back(adatok[i][j]);
        }
    }
    vector<int>ures;
    vector<Widget*>w;

    int b=0;
    for(int i=0; i<adatok.size(); i++) {
        int a=0;
        int c=0;
        for(int j=0; j<adatok.size(); j++) {

            Text* t = new Text(100+b,50+a,50,50,adatok[i][j]);
            t->irhatoe=false;
            a=a+52;
            w.push_back(t);
            c++;
        }
        b=b+52;
    }
    for(int i=0; i<8; i++) {
        int d=rand() %w.size();
        w[d]->setTexti(" ");
        w[d]->irhatoe=true;
        ures.push_back(d);

    }
    background();
    for(int i=0; i<adatok.size(); i++) {
        for(int j=0; j<adatok.size(); j++) {
            cout<<adatok[i][j]<<" ";
        }
        cout<<endl;
    }
    bool hiba=true;
    bool happy=false;//:(


    while(gin >> ev && ev.keycode != key_escape) {
        for(int i=0; i<w.size(); i++) {
            if(!happy){
            w[i]->handle(ev);
            w[i]->draw();
            }
            if(Text* t=dynamic_cast<Text*>(w[i])) {
                if(t->getText()!="") {
                    for(int i=0; i<w.size(); i++) {
                        if(Text* tt=dynamic_cast<Text*>(w[i])) {
                            if(tt->getText()=="") {
                                hiba=true;
                                break;
                            } else {
                                hiba=false;
                            }
                        }
                    }
                    if (!hiba) {
                        for(int i=0; i<ures.size(); i++) {
                            if(Text* f=dynamic_cast<Text*>(w[ures[i]])) {
                                if(fasz[ures[i]]==f->getText()) {
                                    happy=true;
                                }
                                else{
                                    happy = false;
                                    break;
                                }
                            }
                        }
                    }

                }
            }
        }
        if(happy&& ev.type!=ev_mouse && ev.keycode==key_enter){
            jatekvege();

        }

        gout<<refresh;
    }



}



