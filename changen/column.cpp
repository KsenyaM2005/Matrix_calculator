#include "Column.h"

/// Constructors
Column::Column(vector <long double>& num) :
    Matrix{num, (int)num.size(), 1}
{}

Column::Column(int n) : // empty Column
    Matrix{1, n}
{}

/// Methods
vector<long double> Column::get_num() const
{
    return numbers;
}

int Column::get_width() const
{
    return width;
}

int Column:: get_length() const
{
    return length;
}

///Operators
long double Column::operator[] (int i) const // take a number of the Column
{
    return numbers[i];
}

Column Column::operator+ (const Column& col) const // sum of 2 Columns
{
    Column result{length};

    if (col.length != length)
    {
        throw Impossible_operation();
    }
    else if (numbers.empty())
    {
        throw Impossible_operation();
    }

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i] + col.numbers[i]);
    return result;
}

void Column::operator+= (const Column& Column1) // sum of 2 Columns
{
    *this = *this + Column1;
}

Column Column::operator- (const Column& col) const // difference of 2 Columns
{
    Column result{length};

    if (col.length != length)
    {
        throw Impossible_operation();
    }
    else if (numbers.empty())
    {
        throw Impossible_operation();
    }

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i] - col.numbers[i]);
    return result;
}

void Column::operator-= (const Column& Column1) // difference of 2 Columns
{
    *this = *this - Column1;
}

Column Column::operator* (double num) const // product of a Column and a number
{
    Column result{length};
    if (numbers.empty())
    {
        throw Impossible_operation();
    }
    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i]*num);
    return result;
}

void Column::operator*= (double num) // product of a Column and a number
{
    *this = *this * num;
}

Column Column::operator/ (double num) const // quotient of a Column and a number
{
    Column result{length};
    if (numbers.empty())
    {
        throw Impossible_operation();
    }
    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i]/num);
    return result;
}

void Column::operator/= (double num) // quotient of a Column and a number
{
    *this = *this / num;
}

ostream& operator<< (ostream& os, Column& c) // to print a Column in the console
{
    for (int i = 0; i < c.get_width() * c.get_length(); ++i)
    {
        os << c.get_num()[i] << " ";
        if ((i + 1) % c.get_width() == 0)
            os << endl;
    }
    os << endl;
    return os;
}
