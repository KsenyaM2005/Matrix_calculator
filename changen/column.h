#ifndef COLUMN_H
#define COLUMN_H
using namespace std;

#include <vector>

#include "matrix.h"

class Column : protected Matrix
{
public:
    Column() = delete;
    Column(int n); // empty Column
    Column(vector<long double>& num);

    Column operator+ (const Column& Column1) const; // sum of 2 Columns
    void operator+= (const Column& Column1); // sum of 2 Columns

    Column operator- (const Column& Column1) const; // difference of 2 Columns
    void operator-= (const Column& Column1); // difference of 2 Columns

    Column operator* (double num) const; // product of a Column and a number
    void operator*= (double num); // product of a Column and a number

    Column operator/ (double num) const; // quotient of a Column and a number
    void operator/= (double num); // quotient of a Column and a number

    long double operator[] (int i) const; // take a number of the Column


    vector<long double> get_num() const override;
    int get_width() const override;
    int get_length() const override;
};

ostream& operator<< (ostream& os, Column& r); // to print a Column in the console

#endif // COLUMN_H
