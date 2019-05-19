#ifndef ASPECTSPHERE_H_INCLUDED
#define ASPECTSPHERE_H_INCLUDED

#include <string>

class AspectSphere
{
    private:

        double m_rayon;
        std::string m_couleur;

    public :
        ///Constructeurs
        AspectSphere();
        AspectSphere(double r, std::string c);
        ///Destructeur
        ~AspectSphere();
        ///Methode
        void afficher() const;
        void saisir();
        //accesseurs
        double getRayon()  const;
        std::string getCouleur()   const;

        //void setRayon(double rayon);
        //void setCouleur(std::string couleur);

};

#endif // ASPECTSPHERE_H_INCLUDED
