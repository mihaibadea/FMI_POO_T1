#ifndef VECTOR_H
#define VECTOR_H

#include "Numar_intreg_mare.h"

#include <vector>

class Vector
{
    public:
        Vector();
        virtual ~Vector();
        Vector(const Vector& other);
        Vector& operator=(const Vector& other);
        Numar_intreg_mare maxim(bool abs);
        Numar_intreg_mare operator*(const Vector t);
        friend std::ostream &operator<<(std::ostream& out, const Vector &t);
        friend std::istream &operator>>(std::istream& in, Vector &t);

    protected:

    private:
        std::vector<Numar_intreg_mare> v;

};

#endif // VECTOR_H
