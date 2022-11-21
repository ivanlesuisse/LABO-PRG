/**
 * @description:  Ce programme est un jeu wordle qui permet de trouver des mots dans une grille de lettres

 *
 */

#include "fonctions.h"
using namespace std;

// fichier de dictionnaire en string
string dico_fr = "dictionnaire_francais.txt";
string dico_en = "dictionnaire_anglais.txt";




int main() {
    srand (time(NULL));

    // Déclaration des variables
    int choixLangue;
    int tailleDico;
    int NbrAleatoire = rand() % tailleDico;


    // Choix de la langue
    do {
        cout << "Bienvenue dans le jeu Wordle !\n\n"
             << "0. Jouer en français\n"
             << "1. Play in English (hard)\n" ;
        cin >> choixLangue;
    }while((choixLangue != 0) and (choixLangue != 1));


    // à utiliser:      iterator find(first,last,val);   ceci nous renvoie un iterateur
    // ex auto it = find(vecteur.begin(), vecteur.end(), "mot");    vecteur = { "mot", "mot2", "mot3" }
    // ça nous renvoie un iterateur qui pointe sur le mot "mot" dans le vecteur


    if (choixLangue == 0){
        cout << "Vous avez choisi le français\n";
        // lire le fichier dico_fr et le mettre dans un vecteur

        using caracteres = vector<string> ;
        using mot = vector<caracteres>;
        mot dico;
        lireFichier(dico_fr, );
        tailleDico = dico.size();


    }
    else if (choixLangue == 1){

        cout << "You chose English\n";
        // lire le fichier dico_en et le mettre dans un vecteur
        using caracteres = vector<string> ;
        using mot = vector<caracteres>;
        mot dico2;
        lireFichier(dico_en, dico2);
    }


    srand (time(NULL));

    vector<string> MotADeviner;






    return 0;
}
