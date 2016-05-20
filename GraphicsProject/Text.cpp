#include "Text.h"
#include "graphics.hpp"


Text::Text(int x, int y, int sx, int sy ,std::string t)
    : Widget(x,y,sx,sy), _text(t) {}

Text::~Text() {
}

std::string Text::getText() {
    return _text;
}
void Text::setTexti(std::string s) {
    _text = s;
}

void Text::setText(int t) {
    _text = t;
}

using namespace genv;

void Text::draw() {
    gout <<move_to(x()+sx/2-gout.twidth(_text)/2,y()+gout.cascent()/2+(sy/2))<< color(255,255,255) << text(_text);
}

bool Text::contains(int xx, int yy) {
    /*return x() < xx
           && xx < x() + gout.twidth(_text)
           && y() - gout.cascent() < yy
           && y() + gout.cdescent() > yy;
           */

    if(xx>x() && xx< x()+sx && yy>y() && yy<y()+sy) {
        return true;
    } else {
        return false;
    }
}
void Text::handle(event ev) {
    Widget::handle(ev);
      if(irhatoe) {
          gout<<move_to(x(),y())<<color(255,153,204)<<box(sx,sy);
      } else {
          gout<<move_to(x(),y())<<color(255,31,143)<<box(sx,sy);
      }
      if(irhatoe && focused) {
          gout<<move_to(x(),y())<<color(92,255,255)<<box(sx,sy);
          if (focused && ev.type == ev_key) {
              if (49 <= ev.keycode && ev.keycode <= 58) {
                  setText(ev.keycode);
              }
          }
      }/*
    if(irhatoe) {
        gout<<move_to(x(),y())<<color(255,153,204)<<box(sx,sy);
        if(focused && ev.type == ev_key) {
            gout<<move_to(x(),y())<<color(92,255,255)<<box(sx,sy);
            if (49 <= ev.keycode && ev.keycode <= 58) {
                setText(ev.keycode);
            }
        } else {
            gout<<move_to(x(),y())<<color(255,31,143)<<box(sx,sy);
        }
    }*/
}

