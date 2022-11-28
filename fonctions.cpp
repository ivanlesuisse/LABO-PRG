//
// Created by ivbab on 17.11.2022.
//


#include "fonctions.h"




/**
 * Lit un fichier et place chaque ligne du fichier dans un vecteur
 *
 * @param nomFichier le nom du fichier à lire
 * @param vecteur le vecteur qui contiendra les lignes du fichier
 */
void lireFichier(std::string nomFichier, std::vector<std::string>& vecteur){

    std::string line;

    std::ifstream fichier (nomFichier);

    if(fichier.is_open())
    {
        while (fichier) {
            std::getline(fichier, line);
            vecteur.push_back(line);
        }
        fichier.close();

    }else std::cout<<"Error lors de l'ouverture du fichier"<<std::endl;
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
    return indices;
}

std::string essaiRestant(int nombreRestant){
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

    void regles(){
        std::cout << "Regles du  jeu Wordle :\n\n"
        << "Le but du jeu est de trouver un mot dans une grille de lettres.\n"
        << "Le mot est choisi aléatoirement dans un dictionnaire.\n"
        << "Vous avez 6 essais pour trouver le mot.\n"
        << "Si vous trouvez une lettre qui est dans le mot et à la bonne place , elle sera affichée de cette forme : -e--- .\n"
        << "Si vous trouvez une lettre qui est dans le mot mais pas à la bonne place , elle sera affichée de cette forme : -----   lettres trouvées : e,a .\n"
        << "Si vous avez d'autres questions, appellez Elon Musk .\n"

        << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "

        << "Rules of the game Wordle :\n\n";
        << "The goal of the game is to find a word in a grid of letters.\n"
        << "The word is chosen randomly from a dictionary.\n"
        << "You have 6 attempts to find the word.\n"
        << "If you find a letter that is in the word and in the right place, it will be displayed in this form: -e---.\n"
        << "If you find a letter that is in the word but not in the right place, it will be displayed in this form: ----- letters found: e, a.\n"
        << "If you have other questions, call Elon Musk.\n"; << std::endl;







