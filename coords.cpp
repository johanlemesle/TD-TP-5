#include "coords.h"
#include <iostream>


Coords::Coords() : m_x{0}, m_y{0}
{
}
Coords::Coords(double x, double y) : m_x{x}, m_y{y}
{
}
Coords::~Coords()
{
    /*std::cout << "Destruction de ..." << std::endl;
    Coords::afficher();*/
}
void Coords::afficher() const
{
    std::cout << "X : " << m_x << " | " << "Y : " << m_y << std::endl;
}
void Coords::saisir()
{
    std::cout << "Saisir X et Y" << std::endl;
    std::cin >> m_x >> m_y;
}
double Coords::getX() const
{
    return m_x;
}
double Coords::getY() const
{
    return m_y;
}
/*
void Coords::setX(double x)
{
    m_x = x;
}

void Coords::setY(double y)
{
    m_y = y;
}

*/
/*
Coords operator+(const Coords& c1, const Coords& c2)
{
    double x = c1.getX() + c2.getX();
    double y = c1.getY() + c2.getY();

    Coords c(x, y);

    return c;
}
*/
Coords operator+(const Coords& c1, const Coords& c2)
{
    return {c1.m_x + c2.m_x, c1.m_y + c2.m_y};
}
Coords operator*(double m, const Coords& c)
{
    return {m*c.m_x, m*c.m_y};
}

