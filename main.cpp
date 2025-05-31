#include <iostream>
#include "Baralla.hpp"
#include "Tauler.hpp"
#include "Joc.hpp"
using namespace std;

void menu()
{
    cout << "MENU" << endl;
    cout << "1: OBRIR UNA CARTA (O TORNAR A COMENCAR)" << endl;
    cout << "2 : POSAR UNA CARTA (MA->TAULER)" << endl;
    cout << "3 : POSAR UNA CARTA (MA->PILA)" << endl;
    cout << "4 : MOURE UNA CARTA (TAULER->TAULER)" << endl;
    cout << "5 : MOURE UNA CARTA (TAULER->PILA)" << endl;
    cout << "6 : RECUPERAR UNA CARTA (PILA->TAULER)" << endl;
    cout << "E : ESPIAR EL TAULER" << endl;
    cout << "M : MOSTRAR EL MENU" << endl;
    cout << "A : ABANDONAR LA PARTIDA" << endl;
    
}

int main() {
    Joc j;

    cout << "ENTRA LA LLAVOR:" << endl;
    int llavor;
    cin >> llavor;
    Baralla baralla = Baralla(abs(llavor));
    baralla.generar();
    baralla.barrejar();
   
    j.tauler(baralla);
    j.estat_joc(false);
    menu();
    cout<<"OPCIO:"<<endl;
    char opcio;
    cin >> opcio;
    bool fi_joc = false;

    while (!fi_joc) {
        if (opcio == '1') {
            j.obrir_carta();
        } else if (opcio == '2') {
            j.posar_carta();
        } else if (opcio == '3') {
            j.posar_carta_ma_pila();
            fi_joc = j.partida_acabada();
        } else if (opcio == '4') {
            j.posar_carta_tauler_tauler();
        } else if (opcio == '5') {
            j.posar_carta_tauler_pila();
            fi_joc = j.partida_acabada();
        } else if (opcio == '6') {
            j.posar_carta_pila_tauler();
        } else if (opcio == 'E') {
            j.estat_joc(true);
        } else if (opcio == 'M') {
            menu();
        } else if (opcio == 'A') {
            fi_joc = true;
            cout << "HAS ABANDONAT LA PARTIDA!" << endl;
        }
        else{
            cout<<"OPCIO NO DEFINIDA "<<opcio<<endl;
            menu();
            j.estat_joc(false);
        }
        
        if (!fi_joc) {
            cout<<"OPCIO:"<<endl;
            cin >> opcio;
        }
    }

    return 0;
}
