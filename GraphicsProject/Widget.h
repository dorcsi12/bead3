#ifndef WIDGET_H
#define WIDGET_H
#include "graphics.hpp"

class Widget {
public:
    Widget(int x, int y,int sx, int sy);
    virtual ~Widget();
    int x(), y();
    virtual void draw() = 0;
    virtual void handle(genv::event);
    virtual bool contains(int x, int y) = 0;
    virtual void setTexti(std::string s)=0;
        bool irhatoe;
protected:
    bool focused;
    int sx,sy;

private:
    int _x, _y;
};

#endif // WIDGET_H
