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

void lireFichier(std::string nomFichier, std::vector<std::string> &vecteur);

std::vector<int> comparerMots(std::string mot1, std::string mot2);
std::string essaiRestant(int nombreRestant);

#endif //WORDLE_FONCTIONS_H
