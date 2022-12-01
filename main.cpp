/**
 * @description: Ce programme est un jeu wordle qui permet de trouver des mots dans une grille de lettres

 *
 */

#include "fonctions.h"
#include <limits>
#include <random>

using namespace std;

// fichier de dictionnaire en string
string dico_fr = "../dictionnaire_francais.txt";
string dico_en = "../dictionnaire_anglais.txt";
const string MESSAGE_ERREUR = "The input isn't in the dictionary !";


int main() {

    int choixLangue;
    int nombreEssaies = 6;
    const string QUESTON_UTILISATEUR="Play wordle !\n Which language do you want to play ?\n 0. Jouer en francais\n 1. Play in English (hard)\n 2. Regles / Rules \n";

    choixLangue=checkUserInput(QUESTON_UTILISATEUR,0,2);

    using dico = vector<string>;
    dico dictionnaire;

    if (choixLangue == 0) {
        lireFichier(dico_fr, dictionnaire);
        cout << "You have "<<nombreEssaies<<" guesses." << endl;

    } else if (choixLangue == 1) {
        lireFichier(dico_en, dictionnaire);
        cout << "You have " << nombreEssaies << " guesses to find 1 in " << dictionnaire.size() << " words." << endl;
    } else {
        regles();
    }



    /* Génération d'un nombre aléatoire entre 1 et la taille du dictionnaire. */
    std::default_random_engine generator;

    std::uniform_int_distribution<int> distribution(1, dictionnaire.size());

    int nbrAleatoire = distribution(generator);

    //string motADeviner = dictionnaire[nbrAleatoire];

    string motADeviner="tests";


    string choixUtilisateur;
    string motIncomplet = "-----";
    vector<string> dicoCourant = dictionnaire;

    do {
        cin >> choixUtilisateur;

        if (estDansDico(choixUtilisateur, dictionnaire)) {

            --nombreEssaies;

            charTrouvee(choixUtilisateur, motADeviner, motIncomplet);


            /* Mise à jour du dictionnaire quand le jeu est en anglais. */
            if (choixLangue == 1) {
                dicoCourant = miseAJourDico(dicoCourant, choixUtilisateur, motIncomplet);
               // dicoCourant = miseAJourDico2(dicoCourant, motIncomplet, motIncomplet);
            }

            /* Vérifier si l'utilisateur a deviné le mot correctement. Si c'est le cas, il imprime le mot et félicite
            l'utilisateur. */
            if (choixUtilisateur == motADeviner) {
                cout << motIncomplet << " - Congratulations !";
                return 0;
            }

            cout << motIncomplet << " " << essaiRestant(nombreEssaies,choixLangue,dicoCourant.size()) << endl;
            motIncomplet = "-----";

        /* Ceci est un code de triche. Il permet à l'utilisateur de voir la liste des mots encore possibles. */
        } else if (choixUtilisateur == "h" and choixLangue == 1) {
            cin.clear();
            cin.ignore(numeric_limits<long>::max(), '\n');
            afficheListe(dicoCourant);

        } else {
            cout << MESSAGE_ERREUR << endl;
            cin.clear();
            cin.ignore(numeric_limits<long>::max(), '\n');
        }

        choixUtilisateur = "";

    } while (choixUtilisateur != motADeviner and nombreEssaies > 0);


    cout << "Vous avez perdu, le mot etait : " << motADeviner << endl;


    return 0;
}
