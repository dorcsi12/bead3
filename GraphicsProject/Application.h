#ifndef APPLICATION_H
#define APPLICATION_H

class Application {
public:
    Application(int XX, int YY);
    virtual void run();
    virtual void background();
    virtual void jatekvege();
protected:
    int XX, YY;
private:
};

#endif // APPLICATION_H
