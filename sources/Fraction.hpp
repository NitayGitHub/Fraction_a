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
    int GetGcd(int num1, int num2) const;
    int GetLcm(int num1, int num2, int calculatedGcd) const;
    Fraction GetFractionFromFloat(const float &num) const;
public:
    // constructors
    Fraction(int numerator, int denominator);
    Fraction(int numerator);
    
    // functions
    void SimplfyFraction();
    int getNumerator() const;
    void setNumerator(int numerator);
    int getDenominator() const;
    void setDenominator(int denominator);

    // math operators
    Fraction operator+(const Fraction &other) const;
    friend Fraction operator+(const float &num, const Fraction &frac);
    friend Fraction operator+(const Fraction &frac, const float &num);
    Fraction operator-(const Fraction &other) const;
    friend Fraction operator-(const float &num, const Fraction &frac);
    friend Fraction operator-(const Fraction &frac, const float &num);
    Fraction operator*(const Fraction &other) const;
    friend Fraction operator*(const float &num, const Fraction &frac);
    friend Fraction operator*(const Fraction &frac, const float &num);
    Fraction operator/(const Fraction &other) const;
    friend Fraction operator/(const float &num, const Fraction &frac);
    friend Fraction operator/(const Fraction &frac, const float &num);
    // boolean operators
    bool operator==(const Fraction &other) const;
    friend bool operator==(const float &num, const Fraction &frac);
    friend bool operator==(const Fraction &frac, const float &num);
    bool operator>(const Fraction &other) const;
    friend bool operator>(const float &num, const Fraction &frac);
    friend bool operator>(const Fraction &frac, const float &num);
    bool operator<(const Fraction &other) const;
    friend bool operator<(const float &num, const Fraction &frac);
    friend bool operator<(const Fraction &frac, const float &num);
    bool operator>=(const Fraction &other) const;
    friend bool operator>=(const float &num, const Fraction &frac);
    friend bool operator>=(const Fraction &frac, const float &num);
    bool operator<=(const Fraction &other) const;
    friend bool operator<=(const float &num, const Fraction &frac);
    friend bool operator<=(const Fraction &frac, const float &num);
    // unary operators
    Fraction& operator++(int increment_flag);
    Fraction& operator++();
    Fraction& operator--(int increment_flag);
    Fraction& operator--();
    // stream operators
    friend ostream& operator<< (ostream& ost, const Fraction& frac);
    friend istream& operator>> (istream& ist, Fraction& frac);

    
};
}


#endif