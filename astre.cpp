#include "astre.h"
#include "svgfile.h"
#include <iostream>

Astre::Astre() : m_position{0, 0}, m_masse{0}, m_aspect{0, "black"}
{
}
Astre::Astre(double x, double y, double masse, double rayon, std::string couleur) : m_position{x, y}, m_masse{masse}, m_aspect{rayon, couleur}
{
}
Astre::~Astre()
{
    /*std::cout << "Destruction de ..." << std::endl;
    Astre::afficher();*/
}
void Astre::afficher() const
{
    //std::cout << "Astre" << std::endl;
    m_position.afficher();
    std::cout << "Masse : " << m_masse << std::endl;
    m_aspect.afficher();
}
void Astre::saisir()
{
    //Demande a l'utilisateur de saisir l'astre
    m_position.saisir();
    std::cout << "Saisir masse :" << std::endl;
    std::cin >> m_masse;
    m_aspect.saisir();
}
void Astre::dessiner(Svgfile& svgout) const
{
    double rayon = m_aspect.getRayon();
    std::string couleur = m_aspect.getCouleur();
    double x = m_position.getX();
    double y = m_position.getY();

    //Si le rayon n'est pas nul on dessine un cercle
    if(rayon != 0)
        svgout.addDisk(x, y, rayon, couleur);
    //Sinon on dessine une croix
    else
        svgout.addCross(x, y, 25, couleur);
}
Astre Astre::sommer(const Astre& b) const
{
    Coords a1 = m_masse * m_position;
    Coords b1 = b.m_masse * b.m_position;
    Astre c;

    //Calcul de la masse du barycentre
    c.m_masse = m_masse + b.m_masse;
    //Si la masse n'est pas nulle on calcul le barycentre normalement
    if (c.m_masse != 0)
        c.m_position = {(a1.getX() + b1.getX())/c.m_masse,(a1.getY() + b1.getY())/c.m_masse};
    //Sinon on enleve la masse pour eviter une division par 0
    else
        c.m_position = {m_position.getX() + b.m_position.getX(),m_position.getY() + b.m_position.getY()};
    //On met le rayon a 0 et la couleur en noir
    c.m_aspect = {0, "black"};

    return c;
}
Astre operator+(const Astre& a, const Astre& b)
{
    Astre c = a;
    return c.sommer(b);
}
