#include "Fraction.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel{

Fraction floatToFraction(const float &num)
{
    int denominator = 1;
    while (num * denominator != floor(num * denominator))
    {
        denominator = denominator * 10;
    }
    return Fraction(static_cast<int>(num * denominator), denominator);
}

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

// Math Operators

Fraction Fraction::operator+(const Fraction &other) const
{
    int new_deno = GetLcm(other.deno, this->deno);
    int new_nume = this->nume * (new_deno / this->deno) + other.nume * (new_deno / other.deno);
    Fraction new_frac(new_nume, new_deno);
    new_frac.SimplfyFraction();
    return new_frac;
}

Fraction operator+(const float &num, const Fraction &frac)
{
    Fraction floatFrac = floatToFraction(num);
    return frac + floatFrac;
}

Fraction operator+(const Fraction &frac, const float &num)
{
    Fraction floatFrac = floatToFraction(num);
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

Fraction operator-(const float &num, const Fraction &frac)
{
    Fraction floatFrac = floatToFraction(num);
    return floatFrac - frac;
}

Fraction operator-(const Fraction &frac, const float &num)
{
    Fraction floatFrac = floatToFraction(num);
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

Fraction operator*(const float &num, const Fraction &frac)
{
    Fraction floatFrac = floatToFraction(num);
    return frac * floatFrac;
}

Fraction operator*(const Fraction &frac, const float &num)
{
    Fraction floatFrac = floatToFraction(num);
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

Fraction operator/(const float &num, const Fraction &frac)
{
    Fraction floatFrac = floatToFraction(num);
    return floatFrac / frac;
}

Fraction operator/(const Fraction &frac, const float &num)
{
    Fraction floatFrac = floatToFraction(num);
    return frac / floatFrac;
}

// Boolean Operators

bool Fraction::operator==(const Fraction &other) const
{
    Fraction this_frac(this->nume, this->deno);
    Fraction other_frac(other.nume, other.deno);
    this_frac.SimplfyFraction();
    other_frac.SimplfyFraction();
    return this_frac.nume == other_frac.nume && this_frac.deno == other_frac.deno;
}

bool operator==(const float &num, const Fraction &frac){
    if(frac.getNumerator() == 0 && num == 0){
        return true;
    }
    Fraction floatFrac = floatToFraction(num);
    return floatFrac == frac;
}

bool operator==(const Fraction &frac, const float &num){
    if(frac.getNumerator() == 0 && num == 0){
        return true;
    }
    Fraction floatFrac = floatToFraction(num);
    return floatFrac == frac;
}

bool Fraction::operator>(const Fraction &other) const
{
    int lcm = GetLcm(other.deno, this->deno);
    return this->nume * (lcm / this->deno) > other.nume * (lcm / other.deno);
}

bool operator>(const float &num, const Fraction &frac){
    Fraction floatFrac = floatToFraction(num);
    return floatFrac > frac;
}

bool operator>(const Fraction &frac, const float &num){
    Fraction floatFrac = floatToFraction(num);
    return frac > floatFrac;
}

bool Fraction::operator<(const Fraction &other) const
{
    int lcm = GetLcm(other.deno, this->deno);
    return this->nume * (lcm / this->deno) < other.nume * (lcm / other.deno);
}

bool operator<(const float &num, const Fraction &frac){
    Fraction floatFrac = floatToFraction(num);
    return floatFrac < frac;
}

bool operator<(const Fraction &frac, const float &num){
    Fraction floatFrac = floatToFraction(num);
    return frac < floatFrac;
}

bool Fraction::operator>=(const Fraction &other) const
{
    int lcm = GetLcm(other.deno, this->deno);
    return this->nume * (lcm / this->deno) >= other.nume * (lcm / other.deno);
}

bool operator>=(const float &num, const Fraction &frac){
    Fraction floatFrac = floatToFraction(num);
    return floatFrac >= frac;
}

bool operator>=(const Fraction &frac, const float &num){
    Fraction floatFrac = floatToFraction(num);
    return frac >= floatFrac;
}

bool Fraction::operator<=(const Fraction &other) const
{
    int lcm = GetLcm(other.deno, this->deno);
    return this->nume * (lcm / this->deno) <= other.nume * (lcm / other.deno);
}

bool operator<=(const float &num, const Fraction &frac){
    Fraction floatFrac = floatToFraction(num);
    return floatFrac <= frac;
}

bool operator<=(const Fraction &frac, const float &num){
    Fraction floatFrac = floatToFraction(num);
    return frac <= floatFrac;
}

Fraction& Fraction::operator++(int increment_flag){
    this->nume += this->deno;
    return *this;
}

Fraction& Fraction::operator--(int decrement_flag){
    this->nume-= this->deno;
    return *this;
}

Fraction& Fraction::operator++(){
    this->nume += this->deno;
    return *this;
}

Fraction& Fraction::operator--(){
    this->nume-= this->deno;
    return *this;
}

// Stream Operators

ostream& operator<<(ostream& os, const Fraction& frac){
    os << frac.getNumerator() << "/" << frac.getDenominator();
    return os;
}

istream& operator>>(istream& is, Fraction& frac){
    int nume, deno;
    is >> nume >> deno;
    frac.setNumerator(nume);
    frac.setDenominator(deno);
    return is;
}
};