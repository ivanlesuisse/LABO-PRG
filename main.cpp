/**
 * @description:  Ce programme est un jeu wordle qui permet de trouver des mots dans une grille de lettres

 *
 */

#include "fonctions.h"
#include<string.h>
using namespace std;

// fichier de dictionnaire en string
string dico_fr = "../dictionnaire_francais.txt";
string dico_en = "../dictionnaire_anglais.txt";

bool estDansMot(char &i, string basicString);

int main() {
    srand (time(NULL));

    // Déclaration des variables
    int choixLangue=-1;
    string lettresTrouvees=" ";

    const int nombreEssaies= 6;

    using dico = vector<string>;
    dico dictionnaire;


    // Choix de la langue
    do {
        cout << "Play wordle !\n"
             <<"Which language do you want to play ?\n"
             << "0. Jouer en francais\n"
             << "1. Play in English (hard)\n"
             << "2. Regles / Rules \n";
        cin >> choixLangue;
    }while((choixLangue != 0) and (choixLangue != 1) and (choixLangue != 2));

    // à utiliser:      iterator find(first,last,val);   ceci nous renvoie un iterateur
    // ex auto it = find(vecteur.begin(), vecteur.end(), "mot");    vecteur = { "mot", "mot2", "mot3" }
    // ça nous renvoie un iterateur qui pointe sur le mot "mot" dans le vecteur

    // Lecture du fichier de dictionnaire
    if (choixLangue == 0){
        lireFichier(dico_fr,dictionnaire);
        cout<<"You have 6 guesses."<<endl;
    }
    else if (choixLangue == 1){
       lireFichier(dico_en, dictionnaire);
        cout<<"You have "<<nombreEssaies<<" guesses to find 1 in "<<dictionnaire.size()<<" words."<<endl;
    }else{
       regles();
    }


    // Choix du mot aléatoire
    int nbrAleatoire = rand() % dictionnaire.size();
    string motADeviner=dictionnaire[nbrAleatoire];

    // Comparaison des mots
    string choixUtilisateur="";
    string motIncomplet = "-----";

    //

    do{
//       cout<< essaiRestant(nombreEssaies)<<endl;
    cin >> choixUtilisateur;
            //  ((((  contrôle du choix de l'utilisateur (suite de char de 5 de long, pas de nombre, pas de caractères spéciaux) )))) bellek
        if (estDansDico){


        } else if (choixUtilisateur=="h"){

        }else{

            }
            //controler si le mot est dans le dictionnaire si il l est faire : essaiRestant--; , sinon
            // si le choix est "h" (help) on affiche le dico (possibilités restantes)
            // sinon on affiche entree invalide et on recommence

                //fonction qui trouve les possibilités restantes de mot et !!supprime!! les mots qui ne sont pas possibles et
                // retourne le nombre de mots restants dans le dictionnaire


                choixUtilisateur="";

        }while(choixUtilisateur != motADeviner and nombreEssaies > 0);

        if (choixUtilisateur == motADeviner){
            cout << "Bravo, vous avez gagne !\n";
        }else{
            cout << "Vous avez perdu, le mot etait : " << motADeviner << endl;
        }










    return 0;
}
