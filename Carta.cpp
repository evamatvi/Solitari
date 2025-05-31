#include "Carta.hpp"
#include<string>
using namespace std;
Carta::Carta() {
    a_pal = ' ';
    a_valor = 0;
    a_visible = false;
}

Carta::Carta(char pal, int valor, bool visible)
{
    a_pal = pal;
    a_valor = valor;
    a_visible = visible;
}

char Carta::aconseguir_pal() const{
    return a_pal;
}

int Carta::aconseguir_pila_pal() const{
    int pila_pal = 0;
    switch(a_pal) {
        case 'c':
            pila_pal = 1;
            break;
        case 'd':
            pila_pal = 2;
            break;
        case 'T':
            pila_pal = 3;
            break;
        default:
            pila_pal = 0;
    }
    return pila_pal;
}
int Carta::aconseguir_valor() const {
    return a_valor;
}

bool Carta::es_visible() const {
    return a_visible;
}

void Carta::ensenya(){
    a_visible=true;
}

void Carta::oculta(){
    a_visible=false;
}

bool Carta::diferent_color(Carta carta)const{
    bool igual=false;
    if (es_negre() != carta.es_negre())
        igual = true;
    return igual;
}


bool Carta:: es_negre()const{
    bool negre=false;
    if (a_pal=='P' or a_pal== 'T'){
        negre=true;
    }
    return negre;
}

void Carta::mostra_carta()const{
    if (a_valor == 1)
        cout << "A";
    else if (a_valor == 10)
        cout << "D";
    else if (a_valor == 11)
        cout << "J";
    else if (a_valor == 12)
        cout << "Q";
    else if (a_valor == 13)
        cout << "K";
    else cout << a_valor;
    cout << a_pal;

}
