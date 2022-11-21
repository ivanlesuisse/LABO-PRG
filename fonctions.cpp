//
// Created by ivbab on 17.11.2022.
//


#include "fonctions.h"

using namespace std;

// Fonction qui permet de lire un fichier texte et de le mettre dans un vecteur
void lireFichier(string nomFichier, vector<string> &vecteur)

{
    ifstream fichier(nomFichier.c_str());
    string mot;
    if (fichier)
    {
        while (fichier >> mot)
        {
            vecteur.push_back(mot);
        }
    }
    else
    {
        cout << "Erreur lors de l'ouverture du fichier" << endl;
    }
}
//Fonctionne qui affiche si une lettre est dans le mot
bool estDansMot(char lettre, string mot)
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
//Fonction qui permet de comparer deux mots et retourne l'indice des lettres qui sont identiques
vector<int> comparerMots(string mot1, string mot2)
{
    vector<int> indices;
    for (int i = 0; i < mot1.size(); i++)
    {
        if (mot1[i] == mot2[i])
        {
            indices.push_back(i);
        }
    }
    return indices;
}
