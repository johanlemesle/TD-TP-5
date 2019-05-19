#ifndef ASTRE_H_INCLUDED
#define ASTRE_H_INCLUDED

#include "coords.h"
#include "aspectSphere.h"
#include "svgfile.h"

class Astre
{
    private :
        Coords m_position;
        double m_masse;
        AspectSphere m_aspect;

    public:
        ///Constructeurs
        Astre();
        Astre(double x, double y, double masse, double rayon, std::string couleur);
        ///Destructeur
        ~Astre();
        ///Methodes
        void afficher() const;
        void saisir();

        void dessiner(Svgfile& svgout) const;
        Astre sommer(const Astre& b) const;

        friend Astre operator+(const Astre& a, const Astre& b);

};

#endif // ASTRE_H_INCLUDED
