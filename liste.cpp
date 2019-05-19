#include "liste.h"

void supprimerAstre(std::vector<Astre*>& mesAstres)
{
    //On affiche a l'utilisateur la liste des astres
    afficher(mesAstres);
    size_t x;
    //On demande l'indice de l'astre a supprimer
    do{
        std::cout << "Saisir l'astre a supprimer" << std::endl;
        std::cin >> x;
    }while (x < 0 || x > mesAstres.size()-1);

    //On delete l'astre puis on le retire du vector
    delete mesAstres[x];
    mesAstres.erase(mesAstres.begin()+x);
}
void afficher(const std::vector<Astre*>& mesAstres)
{
    std::cout << std::endl;
    //On affiche tout les astre un par un ainsi que leur indice
    for (size_t i=0; i<mesAstres.size(); ++i)
    {
        std::cout << "Astre " << i << ":" << std::endl << std::endl;
        mesAstres[i]->afficher();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
Astre* initAstre()
{
    Astre *pa = nullptr;
    //On alloue un astre
    pa = new Astre;
    //On demande a l'utilisateur de saisir les informations relatives a l'astre
    pa->saisir();
    //On renvoi l'astre saisi
    return pa;
}
void afficherMenu()
{
    std::cout << "Collection d'astres" << std::endl << std::endl
              << "1) Ajouter un astre" << std::endl
              << "2) Dessiner les astres dans un fichier" << std::endl
              << "3) Afficher les astres sur la console" << std::endl
              << "4) Supprimer un astre" << std::endl
              << "5) Quitter" << std::endl << std::endl;
}
void dessiner(const std::vector<Astre*>& mesAstres)
{
    //Creation du fichier svg
    Svgfile svgout;
    //Ajout d'un quadrillage sur le fichier svg
    svgout.addGrid();
    //On dessine tout les astre un par un
    for(size_t i=0; i<mesAstres.size(); ++i)
    {
        mesAstres[i]->dessiner(svgout);
    }
    //On calcule le barycentre de tout les astres de la liste
    Astre barycentre = sommer(mesAstres);
    //On affiche le barycentre du systeme
    barycentre.dessiner(svgout);
}
Astre sommer(const std::vector<Astre*>& vec)
{
    Astre barycentre;
    //Si on a plus d'un element dans la liste on calcule le barycentre
    if (vec.size() > 1)
    {
        for (size_t i=0; i<vec.size(); ++i)
        {
            barycentre = barycentre + *vec[i];
        }
    }
    //Sinon on renvoi un barycentre nul

    return barycentre;
}
