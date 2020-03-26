#ifndef NUMAR_INTREG_MARE_H
#define NUMAR_INTREG_MARE_H

#include <list>
#include <iostream>
#include <string>
#include <algorithm>

class Numar_intreg_mare
{
    public:
        Numar_intreg_mare();
        ~Numar_intreg_mare()=default;
        Numar_intreg_mare(const Numar_intreg_mare& other);
        std::string tostr();
        Numar_intreg_mare operator+(const Numar_intreg_mare nr);
        Numar_intreg_mare operator-(const Numar_intreg_mare nr);
        Numar_intreg_mare operator*(const Numar_intreg_mare nr);
        Numar_intreg_mare operator=(const Numar_intreg_mare &nr);
        friend Numar_intreg_mare maxim(Numar_intreg_mare a, Numar_intreg_mare b, bool abs);
        friend short int compar(Numar_intreg_mare a, Numar_intreg_mare b, bool abs);
        friend std::ostream &operator<<(std::ostream& out, const Numar_intreg_mare &nr);
        friend std::istream &operator>>(std::istream& in, Numar_intreg_mare &nr);
        friend class Vector;
    protected:

    private:
        short int semn;
        std::list<short int> cifre;
};



#endif
