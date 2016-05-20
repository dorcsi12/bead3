#ifndef ADAT_H
#define ADAT_H
#include <vector>
#include <iostream>


class Adat
{
    public:
        Adat();
        virtual ~Adat();
        void beolvas();
        void kever();
        std::vector<std::vector<std::string>> elkeszit();
    private:
        std::vector<std::vector<std::string> >n;
};

#endif // ADAT_H
