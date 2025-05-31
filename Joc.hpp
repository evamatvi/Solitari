#include <stdio.h>
#include <vector>
#include <stack>
#include "Tauler.hpp"
#include "Carta.hpp"
#include "Baralla.hpp"
using namespace std;

class Joc
{
public:
    //CONSTRUCTORS
    Joc();
    //Pre:--;
    //Post:Jugador per defecte
    Joc(unsigned llavor);
    //Pre:--;
    //Post:Jugador per constructor
    
    //CONSULTORS
    void estat_joc(bool espiar) const;
    //Pre:Joc inicialitzat;
    //Post:Mostra l'estat del joc, amb la opció d'espiar el tauler
    bool acabat() const;
    //Pre:--;
    //Post:Retorna cert si ha acabat
    int torn() const;
    //Pre:--;
    //Post:Retorna el torn en el qual estan
    bool ma_plena() const;
    //Pre:--;
    //Post:Retorna cert si la ma està plena
    
    //MODIFICADORS
    void obrir_carta();
    //Pre:--
    //Post:Si a_ma és buida, totes les cartes van a a_ma. Pel contrari a_ma és mogut al cim.
    void posar_carta();
    //Pre:--
    //Post:Si a_descartades està buida, es mostra una línia en blanc. Sinó,després de demanar a l'usuari una columna i intentar posar la carta de a_descartades al tauler.
    
    void posar_carta_ma_pila();
    //Pre:--
    //Post:Si a_descartades no està buida, la carta superior es mou a la pila corresponent del ma_pila basat en el pal de la carta
    
    void posar_carta_tauler_tauler();
    //Pre:Tauler creat
    //Post:Si es pot movem carta d'una columna a una altra
    
    void posar_carta_tauler_pila();
    //Pre:Tauler creat
    //Post:Si es pot movem carta d'una columna a la pila
    
    bool partida_acabada();
    //Pre:--
    //Post:Retorna cert si s'ha acabat la partida
    
    void posar_carta_pila_tauler();
    //Pre:Tauler creat
    //Post:Si es pot movem carta d'una pila al tauler
    
    int incrementar_turn();
    void tauler(Baralla b);
    //Pre:--;
    //Post:Crea tauler

private:
    //ATRIBUTS
    Tauler a_tauler;
    Baralla a_baralla;
    int a_n_jugadors;
    stack<Carta> a_descartades;
    stack<Carta> a_ma;
    vector<stack<Carta>> a_pilaCartes;
    
    bool firstMove = true;
    bool partida_guanyada = false;
    bool a_acabat;

    //MÈTODES PRIVATS
    void repartir_cartes();
    //Pre:--;
    //Post:Reparteix les cartas a cada jugador
    bool insertar_a_pila(Carta c);
    //Pre:--
    //Post:La carta de la cima, si es possible, o fals.
    void joc_guanyat();
    //Pre:Cartes repartides
    //Post:Modifica partida_guanyada si cal 

};
