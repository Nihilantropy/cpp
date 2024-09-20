#include <iostream>
#include "Point.h"

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p1(1, 1); // Punto dentro il triangolo
    Point p2(5, 5); // Punto fuori dal triangolo
    Point p3(0, 0); // Punto sul vertice del triangolo

    std::cout << "Is p1 inside the triangle? " << (bsp(a, b, c, p1) ? "Yes" : "No") << std::endl;
    std::cout << "Is p2 inside the triangle? " << (bsp(a, b, c, p2) ? "Yes" : "No") << std::endl;
    std::cout << "Is p3 inside the triangle? " << (bsp(a, b, c, p3) ? "Yes" : "No") << std::endl;

    return 0;
}