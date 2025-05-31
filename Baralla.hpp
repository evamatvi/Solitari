#ifndef BARALLA_HEADER
#define BARALLA_HEADER
#include<vector>
#include<stdio.h>
#include<iostream>
#include "Carta.hpp"
using namespace std;

class Baralla {
public:
    //CONSTRUCTORS
    Baralla();
    //Pre:--
    //Post:Constructor per defecte de baralla
    Baralla(int seed);
    //Pre:--
    //Post:Constructor per paràmetre de baralla
   
    //MODIFICADORS
    
    void intercambiar(Carta& a, Carta& b);
    //Pre:--
    //Post:a=B, b=A
    int random(int s);
    //Pre:--
    //Post:Mostra les cartes segons l'algorisme Fisher
    void barrejar();
    //Pre:--
    //Post:Barreja les cartes
    void omplir(char c);
    //Pre:Char és una lletra
    //Post:Empila cada carta
    void generar();
    //Pre:--
    //Post:Omple la baralla P c d T
    
    //CONSULTORS
    void mostrar() const;
    //Pre:--
    //Post:Mostra la baralla
    vector<Carta> pilaCartes() const;

private:
    //ATRIBUTS
    vector<Carta> cartes;
    unsigned int a_llavor;

    //CONSTANTS
    static const int a = 1103515245;
    static const int c = 12345;
    static const int m = 32768;
};
#endif
