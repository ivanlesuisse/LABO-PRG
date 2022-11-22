/**
 * @description:  Ce programme est un jeu wordle qui permet de trouver des mots dans une grille de lettres

 *
 */

#include "fonctions.h"
#include<string.h>
using namespace std;

// fichier de dictionnaire en string
string dico_fr = "liste_francais.txt";
string dico_en = "dictionnaire_anglais.txt";




int main() {
    srand (time(NULL));

    // Déclaration des variables
    int choixLangue=-1;
    int tailleDico;
    int nbrAleatoire = rand() % tailleDico;

    const int essaieRestant= 6;

    using dico = vector<string> ;
    dico dictionnaire;


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
        lireFichier(dico_fr,dictionnaire);
    }
    else if (choixLangue == 1){
        cout << "You chose English\n";
        lireFichier(dico_en, dictionnaire);
    }
    tailleDico = dictionnaire.size();


    string motADeviner=dictionnaire[nbrAleatoire];
    string choixUtilisateur="";

    do {
        for (int i = essaieRestant; i > 0 ; --i) {
            cout<<essaieRestant(i);
        }


    } while (choixUtilisateur!=motADeviner);








    return 0;
}
