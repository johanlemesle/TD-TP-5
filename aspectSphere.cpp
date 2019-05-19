#include "aspectSphere.h"

#include <iostream>

AspectSphere::AspectSphere() : m_rayon{0}, m_couleur{"black"}
{
}
AspectSphere::AspectSphere(double r, std::string c) : m_rayon{r}, m_couleur{c}
{
}
AspectSphere::~AspectSphere()
{
    /*std::cout << "Destruction de ..." << std::endl;
    AspectSphere::afficher();*/
}
void AspectSphere::afficher() const
{
    std::cout << "rayon : " << m_rayon << " | " << "couleur: " << m_couleur << std::endl;
}
void AspectSphere::saisir()
{
    std::cout << "Saisir rayon et couleur" << std::endl;
    std::cin >> m_rayon >> m_couleur;
}
double AspectSphere::getRayon()  const
{
    return m_rayon;
}
std::string AspectSphere::getCouleur()  const
{
    return m_couleur;
}
/*
void AspectSphere::setRayon(double rayon)
{
    m_rayon = rayon;
}

void AspectSphere::setCouleur(std::string couleur)
{
    m_couleur = couleur;
}
*/
