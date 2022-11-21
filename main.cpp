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

int choixLangue;
int tailleDico;
int NbrAleatoire = rand() % tailleDico;

    do {
        cout << "Bienvenue dans le jeu Wordle !\n\n"
             << "0. Jouer en français\n"
             << "1. Play in English (hard)\n" ;
        cin >> choixLangue;
    }while((choixLangue != 0) and (choixLangue != 1));

    if (choixLangue == 0){
        cout << "Vous avez choisi le français\n";
        // lire le fichier dico_fr et le mettre dans un vecteur

        using caracteres = vector<string> ;
        using mot = vector<caracteres>;
        mot dico;
        lireFichier(dico_fr, );
        tailleDico = dico.size();
        cout << "Le dictionnaire contient " << tailleDico << " mots\n";
        cout << "Le mot choisi est " << vecteur[NbrAleatoire] << endl;

    }
    else if (choixLangue == 1){
        cout << "You chose English\n";
        lireFichier(dico_eng, );
    }



    vector<string> MotADeviner;

    lireFichier("dictionnaire.txt", vecteur);





    return 0;
}
