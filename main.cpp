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

bool estDansMot(char &i, string basicString);

int main() {
    srand (time(NULL));

    // Déclaration des variables
    int choixLangue=-1;
    int tailleDico;
    int nbrAleatoire = rand() % tailleDico;
    string lettresTrouvees=" ";

    const int essaiRestant= 6;

    using dico = vector<string>;
    dico dictionnaire;


    // Choix de la langue
    do {
        cout << "Bienvenue dans le jeu Wordle  !\n\n"
             << "0. Jouer en francais\n"
             << "1. Play in English (hard)\n"
             << "2. Regles / Rules \n";
        cin >> choixLangue;
    }while((choixLangue != 0) and (choixLangue != 1));

    // à utiliser:      iterator find(first,last,val);   ceci nous renvoie un iterateur
    // ex auto it = find(vecteur.begin(), vecteur.end(), "mot");    vecteur = { "mot", "mot2", "mot3" }
    // ça nous renvoie un iterateur qui pointe sur le mot "mot" dans le vecteur

    // Lecture du fichier de dictionnaire
    if (choixLangue == 0){
        cout << "Vous avez choisi le francais\n";
        //lireFichier(dico_fr,dictionnaire);
    }
    else if (choixLangue == 1){
        cout << "You chose English\n";
       // lireFichier(dico_en, dictionnaire);
    }else{
       regles();
    }

    tailleDico = dictionnaire.size();

    // Choix du mot aléatoire
    string motADeviner=dictionnaire[nbrAleatoire];
    string choixUtilisateur="";

    cout << "à vos marques, prêt, devinez le mot  !\n\n";

    // Comparaison des mots
    string motIncomplet = "-----";

    do{
            cout << "Il vous reste " << essaiRestant << " essais\n";
            cout << "Quel est le mot ? "  << endl;
            cin >> choixUtilisateur;


                for (int j = 0; j < motADeviner.size(); ++j) {
                    if( choixUtilisateur[j] == motADeviner[j]){
                        motIncomplet[j] = choixUtilisateur[j];

                    }else if(estDansMot( choixUtilisateur[j], motADeviner) ){
                        lettresTrouvees.push_back(j);
                    }

                }
                cout << "mot provisoire : " motIncomplet << "   lettres trouvees: " << lettresTrouvees <<  endl;

                cout << "Ce n'est pas le bon mot, essayez encore :) !\n";
                choixUtilisateur="";

                essaiRestant--;
        }while(choixUtilisateur != motADeviner and essaiRestant > 0);

        if (choixUtilisateur == motADeviner){
            cout << "Bravo, vous avez gagne !\n";
        }else{
            cout << "Vous avez perdu, le mot etait : " << motADeviner << endl;
        }










    return 0;
}
