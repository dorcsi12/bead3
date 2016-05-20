#include "Engine.h"


Engine::Engine() {}

void Engine::ellenorzes(std::vector<Widget*> &w, int ind, std::vector<int> ures, bool &vege, std::vector<std::string> sorvektor) {

    if(Text* t=dynamic_cast<Text*>(w[ind])) {
        if(t->getText()!="") {
            for(unsigned int i=0; i<w.size(); i++) {
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
                for(unsigned int i=0; i<ures.size(); i++) {
                    if(Text* f=dynamic_cast<Text*>(w[ures[i]])) {
                        if(sorvektor[ures[i]]==f->getText()) {
                            vege=true;
                        } else {
                            vege = false;
                            break;
                        }
                    }
                }
            }

        }
    }
}
bool ell(std::vector<Widget*> &w, int i, std::vector<int> ures, std::vector<std::string> sorvektor) {
    if(Text* f=dynamic_cast<Text*>(w[ures[i]])) {
        if(sorvektor[ures[i]]!=f->getText()) {
            return true;
        }
    }
    return false;
}
