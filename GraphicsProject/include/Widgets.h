#ifndef WIDGETS_H
#define WIDGETS_H
#include "graphics.hpp"

class Widgets
{
    public:
    Widgets(int x, int y);
    virtual ~Widgets();
    int x(), y();
    virtual void draw() = 0; // pure virtual member function
    virtual void handle(genv::event);
    virtual bool contains(int x, int y) = 0;

    protected:
    bool focused;

    private:
    int _x, _y;
};

#endif // WIDGET_H
