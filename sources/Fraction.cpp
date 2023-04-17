#include "Fraction.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
using namespace ariel;

// Constructors

Fraction::Fraction(int numerator, int denominator) : nume(numerator), deno(denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("Denominator cannot be 0");
    }
}
Fraction::Fraction(int numerator) : nume(numerator), deno(1) {}

// Functions

int Fraction::GetGcd(const int a, const int b) const
{
    int gcd = 1;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

int Fraction::GetLcm(const int a, const int b, int calculatedGcd = 0) const
{
    if (!calculatedGcd)
    {
        return (a * b) / GetGcd(a, b);
    }
    return (a * b) / calculatedGcd;
}

void Fraction::SimplfyFraction()
{
    int gcd = GetGcd(nume, deno);
    nume = nume / gcd;
    deno = deno / gcd;
}

int Fraction::getNumerator() const
{
    return nume;
}

void Fraction::setNumerator(int numerator)
{
    nume = numerator;
}

int Fraction::getDenominator() const
{
    return deno;
}

void Fraction::setDenominator(int denominator)
{
    deno = denominator;
}

// Operators

Fraction& Fraction::operator=(const float &f)
{
    int denominator = 1;
    while (f * denominator != floor(f * denominator))
    {
        denominator = denominator * 10;
    }
    this->nume = f * denominator;
    this->deno = denominator;
    return *this;
}


Fraction Fraction::operator+(const Fraction &other) const
{
    int new_deno = GetLcm(other.deno, this->deno);
    int new_nume = this->nume * (new_deno / this->deno) + other.nume * (new_deno / other.deno);
    Fraction new_frac(new_nume, new_deno);
    new_frac.SimplfyFraction();
    return new_frac;
}

Fraction operator+(const float &f, const Fraction &frac)
{
    Fraction floatFrac = f;
    return frac + floatFrac;
}

Fraction operator+(const Fraction &frac, const float &f)
{
    Fraction floatFrac = f;
    return frac + floatFrac;
}

Fraction Fraction::operator-(const Fraction &other) const
{
    int new_deno = GetLcm(other.deno, this->deno);
    int new_nume = this->nume * (new_deno / this->deno) - other.nume * (new_deno / other.deno);
    Fraction new_frac(new_nume, new_deno);
    new_frac.SimplfyFraction();
    return new_frac;
}

Fraction operator-(const float &f, const Fraction &frac)
{
    Fraction floatFrac = f;
    return floatFrac - frac;
}

Fraction operator-(const Fraction &frac, const float &f)
{
    Fraction floatFrac = f;
    return frac - floatFrac;
}

Fraction Fraction::operator*(const Fraction &other) const
{
    int new_nume = this->nume * other.nume;
    int new_deno = this->deno * other.deno;
    Fraction new_frac(new_nume, new_deno);
    new_frac.SimplfyFraction();
    return new_frac;
}

Fraction operator*(const float &f, const Fraction &frac)
{
    Fraction floatFrac = f;
    return frac * floatFrac;
}

Fraction operator*(const Fraction &frac, const float &f)
{
    Fraction floatFrac = f;
    return frac * floatFrac;
}

Fraction Fraction::operator/(const Fraction &other) const
{
    int new_nume = this->nume * other.deno;
    int new_deno = this->deno * other.nume;
    Fraction new_frac(new_nume, new_deno);
    new_frac.SimplfyFraction();
    return new_frac;
}

Fraction operator/(const float &f, const Fraction &frac)
{
    Fraction floatFrac = f;
    return floatFrac / frac;
}

Fraction operator/(const Fraction &frac, const float &f)
{
    Fraction floatFrac = f;
    return frac / floatFrac;
}

bool Fraction::operator==(const Fraction &other) const
{
    return this->nume == other.nume && this->deno == other.deno;
}

bool operator==(const float &f, const Fraction &frac){
    Fraction floatFrac = f;
    return floatFrac == frac;
}

bool operator==(const Fraction &frac, const float &f){
    Fraction floatFrac = f;
    return floatFrac == frac;
}

