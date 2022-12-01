#include "sqr_matrix.h"

#include <cmath>

using namespace std;

/// Constructors
Sqr_matrix::Sqr_matrix (int n)  : // empty matrix
    dimension{n}, Matrix{n, n}
{}

Sqr_matrix::Sqr_matrix (const vector<long double>& num) :
    dimension{trunc(sqrt(num.size()))}, Matrix{num, trunc(sqrt(num.size())), trunc(sqrt(num.size()))}
{}

Sqr_matrix::Sqr_matrix (const vector<vector<long double>>& num) :
    dimension{num.size()}, Matrix(num)
{}

Sqr_matrix::Sqr_matrix(const Matrix& m) :
    dimension{m.get_length()}, Matrix{m.get_num(), m.get_length(), m.get_width()}
{}

Sqr_matrix::Sqr_matrix(int n, long double x) :
    dimension{n}, Matrix{n, n, x}
{}

/// Methods
Sqr_matrix Sqr_matrix::triangle() const // returns matrix in triangle form
{
    Sqr_matrix m((*this).dimension, 0);
    for (int j = 0; j < width; ++j)
        m.numbers[j] = (*this).numbers[j];
    for (int i = 1; i < length; ++i)
        for (int j = i; j < width; ++j)
            m.numbers[i*width + j] = (m.numbers[i*width + j] * m.numbers[(i-1)*width + i] -
                                      m.numbers[(i-1)*width + j] * m.numbers[i*width + i]); // Bareiss's method
    return m;
}
Sqr_matrix Sqr_matrix::diagonalization() const // returns matrix in diagonale forn
{}
Sqr_matrix Sqr_matrix::inverse() const // returns inverse matrix
{}
Sqr_matrix Sqr_matrix::symmetric() const // returns symmetric matrix
{}
Sqr_matrix Sqr_matrix::skew_symmetric() const // returns skew symmetric matrix
{}
void Sqr_matrix::zeros()
{
    for (int i = 0; i < numbers.size(); ++i)
        numbers[i] = 0;
}

Sqr_matrix Sqr_matrix::T() const // returns transpose matrix
{
    Sqr_matrix m((*this).dimension, 0);
    for (int i = 0; i < dimension; ++i)
        for (int j = 0; j < dimension; ++j)
            m.numbers[i * dimension + j] = numbers[j * dimension + i];
    return m;
}

long double Sqr_matrix::det() // calculation of determination
{
    if (numbers.size() == 1)
        return numbers[0];

    (*this).triangle();

    vector<long double> num;
    for (int j = 0; j < dimension * dimension; ++j)
        if (!(j < dimension || (j % dimension == 0))) // if not (first row or first column)
            num.push_back(numbers[j]);

    Sqr_matrix m{num};
    return numbers[0] * m.det();
}

vector<long double> Sqr_matrix::get_num() const
{
    return numbers;
}

int Sqr_matrix::get_width() const
{
    return dimension;
}

int Sqr_matrix::get_length() const
{
    return dimension;
}

/// Operators
Sqr_matrix Sqr_matrix::operator+ (const Sqr_matrix& mat) const // sum of 2 matrixes
{
    return Sqr_matrix(Matrix(*this) + Matrix(mat));
}

void Sqr_matrix::operator+= (const Sqr_matrix& mat) // sum of 2 matrixes
{
    *this = *this + mat;
}

Sqr_matrix Sqr_matrix::operator- (const Sqr_matrix& mat) const // difference of 2 matrixes
{
    return Sqr_matrix(Matrix(*this) - Matrix(mat));
}

void Sqr_matrix::operator-= (const Sqr_matrix& mat) // difference of 2 Smatrixes
{
    *this = *this - mat;
}

Sqr_matrix Sqr_matrix::operator* (const Sqr_matrix& mat) const // product of 2 matrixes
{
    return Matrix(*this) * Matrix(mat);
}

void Sqr_matrix::operator*= (const Sqr_matrix& mat) // product of 2 matrixes
{
    *this = (*this) * mat;
}

Sqr_matrix Sqr_matrix::operator* (const double& number) const // product of every numbers of a matrix and a number
{
    return Matrix(*this) * number;
}

void Sqr_matrix::operator*= (const double& number) // product of every numbers of a matrix and a number
{
    *this = (*this) * number;
}

Sqr_matrix Sqr_matrix::operator/ (const double& number) const // qoutient of every numbers of a matrix and a number
{
    return Sqr_matrix(Matrix(*this) / number);
}

void Sqr_matrix::operator/= (const double& number) // quotient of every numbers of a matrix and a number
{
    *this = (*this) / number;
}

Row Sqr_matrix::operator[] (const int index) const // take a row of the matrix
{
    return Matrix(*this)[index];
}

ostream& operator<< (ostream& os, Sqr_matrix& mat) // to print a matrix in the console
{
    for (int i = 0; i < mat.get_width() * mat.get_length(); ++i)
    {
        os << mat.get_num()[i] << " ";
        if ((i + 1) % mat.get_width() == 0)
            os << endl;
    }
    os << endl;
    return os;
}
