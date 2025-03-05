#include "fraction.hpp"
#include "utils.hpp"

// l'ensemble des exercices sont dans l'ordre, en fin de ce fichier, j'ai noté l'exercice conserné pour chacune des fonctions !

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}

Fraction add(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction sub(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction mul(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction div(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}



// exercice1
Fraction operator+(Fraction const& f1, Fraction const& f2){
    Fraction temp{
        f1.numerator * f2.denominator + f2.numerator *f1.denominator,
        f1.denominator * f2.denominator
    };
    temp = simplify(temp);
    return temp;
}

Fraction operator-(Fraction const& f1, Fraction const& f2){
    Fraction temp{
        f1.numerator * f2.denominator - f2.numerator *f1.denominator,
        f1.denominator * f2.denominator
    };
    temp = simplify(temp);
    return temp;
}

Fraction operator*(Fraction const& f1, Fraction const& f2){
    Fraction temp{
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    };
    temp = simplify(temp);
    return temp;
}

Fraction operator/(Fraction const& f1, Fraction const& f2){
    Fraction temp{
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    };
    temp = simplify(temp);
    return temp;
}

// exercice2
std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << "/" << f.denominator;
}

// exercice3
bool operator==(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator == f1.denominator * f2.numerator;
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}

// exercice4
bool operator<(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator < f1.denominator * f2.numerator;
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return (f1 == f2 || f1 < f2);
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2 || f1 < f2);
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2);
}

//exercice5
Fraction& Fraction::operator+=(Fraction const& f) //l'operator += est une methode de Fraction
{
    numerator = numerator * f.denominator + f.numerator * denominator ;
    denominator = denominator * f.denominator;

    return *this;
}

Fraction operator-=(Fraction f1, Fraction const& f2) //on def le reste des operators avec des fonctions.
{
    Fraction temp{
        f1.numerator * f2.denominator - f2.numerator *f1.denominator,
        f1.denominator * f2.denominator
    };
    temp = simplify(temp);
    f1 = temp;
    return f1;
}

Fraction operator*=(Fraction f1, Fraction const& f2){
    Fraction temp{
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    };
    temp = simplify(temp);
    f1 = temp;
    return f1;
}

Fraction operator/=(Fraction f1, Fraction const& f2){
    Fraction temp{
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    };
    temp = simplify(temp);
    f1 = temp;
    return f1;
}


//les defs des 4 prochaines fonctions foncionnent malgré le fait que ces operateurs sont déjà def à l'exercice 1 car les signatures ne sont pas les mêmes mais c'est pas une très bonne pratique..
Fraction operator+(Fraction f1, Fraction const& f2) 
{
    f1 += f2;
    return f1;
}

Fraction operator-(Fraction f1, Fraction const& f2) {
    f1 -= f2;
    return f1;
}

Fraction operator*(Fraction f1, Fraction const& f2) {
    f1 *= f2;
    return f1;
}

Fraction operator/(Fraction f1, Fraction const& f2) {
    f1 /= f2;
    return f1;
}
// on constate que ces definitions sont beaucoup plus efficaces que les premières, notamment car nous n'avons pas besoin ici de definir une autre Fraction 'temp'.


// exercice6
float Fraction::to_float() const {
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}

Fraction::operator float() const {
    return to_float();
}