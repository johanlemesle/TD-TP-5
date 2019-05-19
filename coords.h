#ifndef COORDS_H_INCLUDED
#define COORDS_H_INCLUDED

class Coords
{
    private :

        double m_x;
        double m_y;

    public :
        ///Constructeurs
        Coords();
        Coords(double x, double y);

        ///Destructeur
        ~Coords();

        ///Methodes
        void afficher() const;
        void saisir();

        ///Accesseurs
        double getX() const;
        double getY() const;

        //void setX(double x);
        //void setY(double y);

        friend Coords operator+(const Coords& c1, const Coords& c2);
        friend Coords operator*(double m, const Coords& c);
};

#endif // COORDS_H_INCLUDED
