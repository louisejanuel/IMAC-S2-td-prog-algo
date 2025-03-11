#pragma once
#include <iostream>

struct Fraction {
    int numerator;
    int denominator;

    void display();

    Fraction& operator+=(Fraction const& f1);
    
    // exercice6
    float to_float() const;
    operator float() const;
};

Fraction add(Fraction const& f1, Fraction const& f2);
Fraction sub(Fraction const& f1, Fraction const& f2);
Fraction mul(Fraction const& f1, Fraction const& f2);
Fraction div(Fraction const& f1, Fraction const& f2);


// exercice1
Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

// exercice2
std::ostream& operator<<(std::ostream& os, Fraction const& f);

// exercice3
bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

// exercice4
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);

// exercice5
Fraction operator-=(Fraction f1, Fraction const& f2);
Fraction operator*=(Fraction f1, Fraction const& f2);
Fraction operator/=(Fraction f1, Fraction const& f2);

// exercice6 cf. struct