#include "Baralla.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include "Carta.hpp"
#include <vector>

Baralla::Baralla()
{
    a_llavor = 25;
    
}

Baralla::Baralla(int seed)
{
    a_llavor = seed;
    
}


void Baralla::intercambiar(Carta& a, Carta& b)
{
    
    Carta aux = a;
    a = b;
    b = aux;
}

int Baralla::random(int seed)
{
   

    a_llavor = a * a_llavor + c;
    int nouLLavor = ((a_llavor / 32) % m) % seed;

    return nouLLavor;
}

void Baralla::barrejar()
{
    
    for (int i = cartes.size() - 1; i > 0; i--)
    {
        int pos = random(i + 1);
        intercambiar(cartes[pos], cartes[i]);
    }
}

void Baralla::generar() {

    omplir('P');
    omplir('c');
    omplir('d');
    omplir('T');
}

void Baralla::omplir(char c) {

    for (int i = 1; i <= 13; i++)
    {
        cartes.push_back(Carta(c, i, true));
    }
}

void Baralla::mostrar() const
{
    for (int i = 0; i < cartes.size(); i++)
    {
        if (cartes[i].aconseguir_valor() == 1)
            cout << "A";
        else if (cartes[i].aconseguir_valor() == 10)
            cout << "D";
        else if (cartes[i].aconseguir_valor() == 11)
            cout << "J";
        else if (cartes[i].aconseguir_valor() == 12)
            cout << "Q";
        else if (cartes[i].aconseguir_valor() == 13)
            cout << "K";
        else cout << cartes[i].aconseguir_valor();
        cout << cartes[i].aconseguir_pal() << " ";
    }
}

vector<Carta> Baralla::pilaCartes() const
{
    return cartes;
}

