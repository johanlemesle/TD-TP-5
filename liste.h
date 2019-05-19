#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include <iostream>
#include <vector>
#include "astre.h"

///Supprime un astre (astre delete et retirer de la liste)
void supprimerAstre(std::vector<Astre*>& mesAstres);
///Affichage de tout les astres
void afficher(const std::vector<Astre*>& mesAstres);
///Alloue et demande la saisi d'un astre
Astre* initAstre();
///Affichage du menu principal
void afficherMenu();
///Dessine les astres sur le fichier .svg
void dessiner(const std::vector<Astre*>& vec);
///Retourne le barycentre de tout les astres de la liste
Astre sommer(const std::vector<Astre*>& vec);


#endif // LISTE_H_INCLUDED
