//
// Created by ivbab on 17.11.2022.
//


#include "fonctions.h"


// Fonction qui permet de lire un fichier texte et de le mettre dans un vecteur
void lireFichier(std::string nomFichier, std::vector<std::string>& vecteur)

{
    std::ifstream fichier(nomFichier.c_str());
    std::string mot;
    if (fichier)
    {
        while (fichier >> mot)
        {
            vecteur.push_back(mot);
        }
    }
    else
    {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
    }
}

//Fonctionne qui affiche si une lettre est dans le mot
bool estDansMot(const char lettre,const std::string& mot)
{
    for (int i = 0; i < mot.size(); i++)
    {
        if (lettre == mot[i])
        {
            return true;
        }
    }
    return false;
}

/**
 * Il prend deux chaînes et renvoie un vecteur d'entier représentant l'indice des lettres qui sont identiquess
 *
 * @param mot1 Le premier mot à comparer
 * @param mot2 le deuxième mot à comparer
 *
 * @return Un vecteur d'entiers.
 */
std::vector<int> comparerMots(const std::string& mot1, const std::string& mot2)
{
    std::vector<int> indices;
    for (int i = 0; i < mot1.size(); i++)
    {
        if (mot1[i] == mot2[i])
        {
            indices.push_back(i);
        }
    }
    return indices;
}

std::string essaieRestant(int nombreRestant){
    std::string message="(";
    switch (nombreRestant) {
        case 0:
            message+="no guesses";
        case 1:
            message+= "1 guess";
        default:
            message+=nombreRestant+" guesses";

    }
    message+=" left)";

    return message;
}