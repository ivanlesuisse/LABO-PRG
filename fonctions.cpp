//
// Created by ivbab on 17.11.2022.
//

#include <limits>
#include <algorithm>
#include <string>
#include "fonctions.h"

/**
 * Lit un fichier et place chaque ligne du fichier dans un vecteur
 *
 * @param nomFichier le nom du fichier à lire
 * @param vecteur le vecteur qui contiendra les lignes du fichier
 */
void lireFichier(const std::string& nomFichier, std::vector<std::string>& vecteur){

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


std::string essaiRestant(int nombreRestant,int choixLangue,int nombreMotRestants){
    std::string message="(";
    switch (nombreRestant) {
        case 0:
            message+="no guesses";
        case 1:
            message+= "1 guess";
        default:
            message+=std::to_string(nombreRestant)+" guesses";

    }
     message+=" for "+ std::to_string(nombreMotRestants)+" word";
    if (nombreRestant>1) message+="s";
    message+=" left)";

    return message;
}

    void regles() {
        std::cout   << "Regles du  jeu Wordle :\n\n"
                    << "Le but du jeu est de trouver un mot dans une grille de lettres.\n"
                    << "Le mot est choisi aléatoirement dans un dictionnaire.\n"
                    << "Vous avez 6 essais pour trouver le mot.\n"
                    << "Si vous trouvez une lettre qui est dans le mot et à la bonne place , elle sera affichée en majuscule à l'emplacement correcte.\n"
                    << "Si vous trouvez une lettre qui est dans le mot mais pas à la bonne place , elle sera affichée en minuscule à l'emplacement courant .\n"


                    << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n"
                    << "Rules of the game Wordle :\n\n"
                    << "The goal of the game is to find a word in a grid of letters.\n"
                    << "The word is chosen randomly from a dictionary.\n"
                    << "You have 6 attempts to find the word.\n"
                    << "If you find a letter that is in the word and in the right place, it will be displayed in uppercase at the correct place.\n"
                    << "If you find a letter that is in the word but not in the right place, it will be displayed in lowercase at the current place.\n"
                    << std::endl;

    }

/**
 * Elle renvoie true si la chaîne mot est dans le vecteur dico, et false sinon
 *
 * @param mot le mot à vérifier
 * @param dico le dictionnaire des mots
 *
 * @return Un booléen
 */
bool estDansDico(const std::string& mot,std::vector<std::string> dico){

    for (int i = 0; i < dico.size(); ++i) {
        if (dico[i]==mot) return true;
    }
    return false;
}

/**
 * Il imprime les mots restants dans le dictionnaire
 *
 * @param dicoCourant le dictionnaire actuel des mots
 */
void afficheListe(std::vector<std::string>dicoCourant){

    for (int i = 0; i < dicoCourant.size(); ++i) {
        std::cout<<dicoCourant[i]<<" ";
    }
    std::cout<<std::endl;

}

/**
 * Il prend un mot, un mot à trouver et une chaîne, et il met à jour la chaîne avec les lettres du mot à trouver qui sont
 * dans le mot
 *
 * @param mot le mot à trouver
 * @param motAtrouver le mot à trouver
 * @param chaineActuelle la chaîne qui sera affichée à l'utilisateur.
 */
void charTrouvee(const std::string& mot, const std::string& motAtrouver,std::string& chaineActuelle){

    for (int i = 0; i < mot.size() ; ++i) {

        // si lovercase ou tiret
        if(islower(mot[i]) or reinterpret_cast<const char *>(mot[i]) == "-"){

            //si même lettre même emplacement, ajouter lettre en upprecase à l'emplacement
            if (mot[i]==motAtrouver[i]) chaineActuelle[i]=toupper(motAtrouver[i]);

            //Si la lettre est dans le mot mais pas au même emplacement, lettre lowercase à l'emplacement
            else if (estDansMot(mot[i],motAtrouver))
                    chaineActuelle[i]=mot[i];

        }
    }
}




std::vector<std::string> miseAjourDico(const std::vector<std::string>& listeMotRestants,const std::string& reponseJoueur,const std::string& motIncomplet){
    std::vector<std::string> nouveauDico;

    for (int i = 0; i <listeMotRestants.size() ; ++i) {
        for (int j = 0; j < motIncomplet.length(); ++j) {
            // si maj enlever garder que celle qui sont a la meme poisition par la même chose
            if (std::isupper(motIncomplet[j])){
                nouveauDico.push_back(listeMotRestants[i]);
            }
            // si min enlever garder que celle qui contienne la laettre
            else if (std::islower(motIncomplet[j]) and listeMotRestants[i].find_first_not_of(motIncomplet[j]) != std::string::npos){
                nouveauDico.push_back(listeMotRestants[i]);

            }
            else if (listeMotRestants[i].find_first_of(reponseJoueur) == std::string::npos and motIncomplet[j]=='-'){
                nouveauDico.push_back(listeMotRestants[i]);
            }

        }

    }
    sort( nouveauDico.begin(), nouveauDico.end() );
    nouveauDico.erase( unique( nouveauDico.begin(), nouveauDico.end() ), nouveauDico.end() );
    return nouveauDico;
}

int checkUserInput(const std::string& mQuestion, int min, int max) {

    int userInput;

    do {
        std::cout << mQuestion;
        std::cin >> userInput;

        if (userInput < min or userInput > max ) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (userInput < min or userInput > max);
    return userInput;
}