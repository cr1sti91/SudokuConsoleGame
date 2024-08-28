#ifndef SUDOKU_FUNCTIONS_H
#define SUDOKU_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <random>

//Culori pentru text (codul ANSI)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

const size_t nr = 9;

void clearScreen(); //Face iluzia curatirii consolei
void efectuarea_copiei(char(&matrice_originala)[nr][nr], char(&matrice_copie)[nr][nr]);
void inserare_spatii(char(&matrice)[nr][nr]);
void afisare_tabla(char(&matrice)[nr][nr], int optiune);
bool este_valid(char(&matrice)[nr][nr], int rand, int coloana, int numar);
bool rezolvare_Sudoku(char(&matrice)[nr][nr]);
void generare_Sudoku_prim_3x3(char(&matrice)[nr][nr], int dificultate, char(&matrice_rez)[nr][nr], char(&matrice_copie)[nr][nr]);
void generare_Sudoku_full_random(char(&matrice)[nr][nr], int dificultate, char(&matrice_rez)[nr][nr], char(&matrice_copie)[nr][nr]);
bool compararea_perechi_indici(int(&array_elemente)[nr * nr][2], int a, int b);
void colectarea_indicilor(char(&matrice)[nr][nr], int(&container)[nr * nr][2]);
int sfarsit_rezolvare(bool starea_curenta, char(&matrice)[nr][nr]); //Verifica daca a mai ramas de introdus un singur numar
bool aranjament_valid(char(&matrice)[nr][nr]); //Verifica daca aranjamentul este valid
void indiciu(char(&matrice)[nr][nr], std::vector<std::vector<int>>& pasii, int rand, int coloana, int mod_afisare);
void analiza_grilei(char(&matrice)[nr][nr]);

#endif //SUDOKU_FUNCTIONS_H