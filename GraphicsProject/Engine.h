#ifndef ENGINE_H
#define ENGINE_H
#include "Text.h"
#include <vector>


class Engine
{
    public:
        Engine();
        ~Engine(){};
        bool ell(std::vector<Widget*> &w, int ind, std::vector<int> ures, std::vector<std::string> sorvektor);
        void ellenorzes(std::vector<Widget*> &w, int ind, std::vector<int> ures, bool &vege, std::vector<std::string> sorvektor);
    protected:
        bool hiba=true;
    private:
};

#endif // ENGINE_H
