#ifndef TEXT_H
#define TEXT_H
#include <string>
#include "Widget.h"

class Text: public Widget {
public:
    Text(int x, int y, int sx, int sy ,std::string);
    virtual ~Text();
    std::string getText();
    void setText(int s);
    virtual void draw();
    bool contains(int x, int y) override;
    virtual void handle(genv::event) override;
    void setTexti(std::string s);

protected:


private:
    std::string _text;
};

#endif // TEXT_H
