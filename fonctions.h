//
// Created by ivbab on 17.11.2022.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cctype> // tous les types de caractères

#ifndef WORDLE_FONCTIONS_H
#define WORDLE_FONCTIONS_H

void regles();

void lireFichier(const std::string& nomFichier, std::vector<std::string>& vecteur);

std::vector<int> comparerMots(std::string mot1, std::string mot2);
std::string essaiRestant(int nombreRestant);

bool estDansDico(const std::string& mot,std::vector<std::string> dico);

void afficheMotRestant(std::vector<std::string>dicoCourant);
#endif //WORDLE_FONCTIONS_H
