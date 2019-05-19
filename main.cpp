#include <iostream>

#include "coords.h"
#include "aspectSphere.h"
#include "svgfile.h"
#include "astre.h"
#include "liste.h"

int main()
{
    std::vector<Astre*> mesAstres;
    int x;

    Svgfile sv;
    sv.addRect(50,50,30,30,"black");

    Coords a(8,6);
    Coords b(4,2);
    Coords c;
    c=2*a;
    c.afficher();

    //Boucle du menu
    do{
        //Affiche le menu puis demande a l'utilisateur l'action désirée
        afficherMenu();

        std::cin >> x;

        switch(x)
        {
        case 1:
            ///Ajouter un astre
            mesAstres.push_back(initAstre());
            break;
        case 2:
            ///Dessiner astres dans fichier
            dessiner(mesAstres);
            break;
        case 3:
            ///Afficher astres sur console
            afficher(mesAstres);
            break;
        case 4:
            ///Supprimer un astre
            supprimerAstre(mesAstres);
            break;
        case 5:
            ///Quitter
            //On delete tout les astres un par un avant de quitter le programme
            for (size_t i=0; i<mesAstres.size(); ++i)
            {
                delete mesAstres[i];
            }
            break;
        case 6:
            {
                Astre test;
                test = sommer(mesAstres);
                test.afficher();
            }
            break;
        default :
            std::cout << "Erreur, reessayez." << std::endl;
            break;
        }

    }while(x != 5);

    return 0;
}
