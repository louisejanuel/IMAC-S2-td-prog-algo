#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = ";
    f1.display();
    std::cout << " f2 = ";
    f2.display();
    std::cout << std::endl;

    Fraction f3 { add(f1, f2) };

    std::cout << "add(f1, f2) = ";
    f3.display();

    std::cout << std::endl << "sub(f1, f2) = ";
    (sub(f1, f2)).display();

    std::cout << std::endl << "mul(f1, f2) = ";
    (mul(f1, f2)).display();

    std::cout << std::endl << "div(f1, f2) = ";
    (div(f1, f2)).display();

    std::cout << std::endl << "add(1/6, 2/6) = "<< std::endl;
    (add({1, 6}, {2, 6})).display();


    // test de mes operateurs
    std::cout << "f1 + f2 = " << (f1 + f2) << std::endl;
    std::cout << "f1 - f2 = " << (f1 - f2) << std::endl;
    std::cout << "f1 * f2 = " << (f1 * f2) << std::endl;
    std::cout << "f1 / f2 = " << (f1 / f2) << std::endl;

    std::cout << "Comparisons:" << std::endl;
    std::cout << "f1 == f2 ? " << (f1 == f2) << std::endl;
    std::cout << "f1 != f2 ? " << (f1 != f2) << std::endl;
    std::cout << "f1 < f2 ? " << (f1 < f2) << std::endl;
    std::cout << "f1 <= f2 ? " << (f1 <= f2) << std::endl;
    std::cout << "f1 > f2 ? " << (f1 > f2) << std::endl;
    std::cout << "f1 >= f2 ? " << (f1 >= f2) << std::endl;

    std::cout << "Conversion en float: " << std::endl;
    std::cout << "f1 en float = " << static_cast<float>(f1) << std::endl;
    std::cout << "f2 en float = " << static_cast<float>(f2) << std::endl;

    return 0;

}