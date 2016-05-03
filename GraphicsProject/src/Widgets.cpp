#include "Widgets.h"

Widgets::Widgets(int x, int y): _x(x), _y(y), focused(false)
{}

Widgets::~Widgets()
{}

int Widgets::x() {return _x;}
int Widgets::y() {return _y;}

using namespace genv;

void Widgets::handle(event ev){
    if (ev.type == ev_mouse && ev.button == btn_left) {
        focused = contains(ev.pos_x, ev.pos_y);
    }
}
