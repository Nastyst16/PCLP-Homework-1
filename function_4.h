// Nastase Cristian-Gabriel 315CA
#pragma once

#include <stdio.h>

//functii pentru problema "another_queries"

void posibilitati_linie(int v[], int a[][401], int N);
void posibilitati_coloana(int v[], int a[][401], int N);
void posibilitati_careu(int v[], int a[][401], int N);
int posibilitati_coordonate(int v[], int a[][401], int N);
void adaugare_numar(int a[][401]);
void stare_curenta(int v[], int a[][401], int N);
void citire_sudoku(int a[][401], int N);
