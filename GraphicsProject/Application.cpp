#include "Application.h"


using namespace genv;
using namespace std;

Application::Application(int XX, int YY) : XX(XX), YY(YY) {}

void Application::background() {
    gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);
}

void Application::jatekvege() {
    string grt="Gratulálok, nyertél!";
    gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY)
        <<move_to(XX/2-gout.twidth(grt),YY/2)<<color(255,31,143)<<text(grt);

}
void Application::hibas(int i) {
    gout<<move_to(w[i]->x(),w[i]->y())<<color(0,0,255)<<line_to(w[i]->x()+w[i]->getSx(),w[i]->y()+w[i]->getSy());
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

    for(unsigned int i=0; i<adatok.size(); i++) {
        int a=0;
        int c=0;
        for(unsigned int j=0; j<adatok.size(); j++) {
            Text* t = new Text(100+b,50+a,50,50,adatok[i][j]);
            t->irhatoe=false;
            a=a+52
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
        if(ev.keycode==key_space && ev.type==ev_key) {
            for(unsigned int i=0; i<ures_index.size(); i++) {
                bool rossze = e.ell(w,i,ures_index,sorvektor);
                if(rossze) {
                    hibas(ures_index[i]);
                }
            }
        }
        if(vege&& ev.type!=ev_mouse && ev.keycode==key_enter) {
            jatekvege();
        }
        gout<<refresh;
    }
}



