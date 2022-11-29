#ifndef Vector_H
#define Vector_H
#include "column.h"
#include <vector>
using namespace std;
class Vector: private Column
{
public:
    Vector (vector<long double>& num);
    double length() const;

    void operator+= (Vector& vec);
    Vector operator+ (Vector& vec);

    void operator-= (Vector& vec);
    Vector operator- (Vector& vec);

    void operator*=(Vector& vec);
    Vector operator*(Vector& vec);

    void operator*= (double num);
    Vector operator* (double num);

    void operator/= (double num);
    Vector operator/ (double num);

    long double scal_prod(const Vector& vec);
    Vector vec_prod(const Vector& vec);

    long double length();
    void show();

    using Column::operator[];
};

#endif // Vector_H
