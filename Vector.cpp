#include "Vector.h"


Vector::Vector(const Vector& other): v(other.v)
{

}

Vector& Vector::operator=(const Vector& rhs)
{
    if (this == &rhs) return *this;
    v=rhs.v;
    return *this;
}


Numar_intreg_mare Vector::maxim(bool abs)
{
    Numar_intreg_mare rez;
    rez = v[0];
    for(int i=1; i<v.size(); i++)
    {
        if(compar(v[i],rez,abs)==1) rez=v[i];
    }

    return rez;
}

std::ostream& operator<<(std::ostream& out, const Vector &t)
{
    out<<"["<<t.v.size()<<"]: ";

    for(int i=0; i<t.v.size(); i++)
    {
        out<<t.v[i]<<" ";
    }

    out<<"\n";

    return out;
}

std::istream& operator>>(std::istream& in, Vector &t)
{
    int nr;
    Numar_intreg_mare k;

    in>>nr;

    for(int i=0; i<nr; i++)
    {
        in>>k;
        t.v.push_back(k);
    }

    return in;
}

Numar_intreg_mare Vector::operator*(const Vector t)
{
    Numar_intreg_mare rez;

    for(int i=0; i<v.size();i++)
    {
        rez=rez+v[i]*t.v[i];
    }

    return rez;
}
