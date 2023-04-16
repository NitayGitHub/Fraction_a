#ifndef FRAC_H
#define FRAC_H
#include <iostream>
using namespace std;
namespace ariel
{
class Fraction
{
private:
    int deno; // denominator
    int nume; // numerator
    void gcd(int a, int b);
public:
    // constructors
    Fraction(int numerator, int denominator);
    Fraction(int numerator);
    
    // functions
    void SimplfyFraction();

    // operators
    Fraction operator+(const Fraction &other) const;
    friend Fraction operator+(const float &f, const Fraction &frac);
    Fraction operator-(const Fraction &other) const;
    friend Fraction operator-(const float &f, const Fraction &frac);
    Fraction operator*(const Fraction &other) const;
    friend Fraction operator*(const float &f, const Fraction &frac);
    Fraction operator/(const Fraction &other) const;
    friend Fraction operator/(const float &f, const Fraction &frac);
    bool operator==(const Fraction &other) const;
    friend bool operator==(const float &f, const Fraction &frac);
    bool operator>(const Fraction &other) const;
    friend bool operator>(const float &f, const Fraction &frac);
    bool operator<(const Fraction &other) const;
    friend bool operator<(const float &f, const Fraction &frac);
    bool operator>=(const Fraction &other) const;
    friend bool operator>=(const float &f, const Fraction &frac);
    bool operator<=(const Fraction &other) const;
    friend bool operator<=(const float &f, const Fraction &frac);
    Fraction& operator++(int increment_flag);
    Fraction& operator++();
    Fraction& operator--(int increment_flag);
    Fraction& operator--();
    friend ostream& operator<< (ostream& os, const Fraction& frac);
    friend istream& operator>> (istream& is, Fraction& frac);

    
};


}



#endif