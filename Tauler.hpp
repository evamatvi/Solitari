#ifndef TAULER_HEADER
#define TAULER_HEADER
#include <stdio.h>
#include <vector>
#include "Carta.hpp"
#include "Baralla.hpp"
using namespace std;

class Tauler {
public:
    //CONSTRUCTORS
    Tauler();
    //Pre:--
    //Post: Constructor tauler per defecte
    Tauler(int mida);
    //Pre:--
    //Post:Constructor de tauler per paràmetre

    //CONSULTORS
    void mostrar() const;
    //Pre:--;
    //Post:Mostra la carta
    void mostrar_condicional(bool espiar, bool partida_guanyada) const;
    //Pre:--
    //Post:Mostra el tauler, amb la opció de veure cartes ocultes, i si hem guanyat per mostrar fi de partida
    int mida() const;
    //Pre:--
    //Post:Retorna la mida del tauler
       
    
    //MODIFICADORS
    bool posar_carta(int col,Carta c);
    //Pre:Columna no buida
    //Post:Afegeix una carta a la columna del tauler

    void repartir(Baralla b, int& i);
    //Pre:Baralla plena i índex incialitzat
    //Post:Cartes distribuïdes al tauler

    void insertar_carta(Carta c, int col);
    //Pre:Columna no buida
    //Post:Inserta la carta a la columna del tauler
   
    bool eliminar_ultima_carta_de_columna(int col);
    //Pre:Tauler omplert
    //Post:Eliminem la darrera carta de la columna, fals en cas que columna buida
    
    bool obtenir_ultima_carta_de_columna(Carta &carta, int col);
    //Pre:Tauler omplert
    //Post:Obtenir la info de la carta en questió, fals en cas que columna buida
    
    void posar_carta_tauler_tauler();
    //Pre:Tauler creat
    //Post:Si es possible, carta moguda d'una fila a una altre
private:
    //CONSTANTS
    static const int  MIDA_TAULER = 7;
   //ATRIBUTS
    int a_n_files, a_n_columnes;
    vector<vector<Carta>> a_tauler;
};
#endif
