#ifndef CARTA_hpp
#define CARTA_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class Carta {


public:
    //CONSTRUCTORS
    Carta();
    //Pre:--
    //Post:Construeix per defecte la carta
    
    Carta(char pal, int valor, bool visible);
    //Pre:--
    //Post:Constructor per paràmetre de la carta
    
    //MODIFICADODORS
    
    void ensenya();
    //Pre:--
    //Post:Assigna visible a la carta
    
    void oculta();
    //Pre:--
    //Post:La carta deixa d'estar visible
    
    //CONSULTORS
    char aconseguir_pal() const;
    //Pre:--
    //Post:Retorna el pal
    int aconseguir_valor() const;
    //Pre:--
    //Post:Retorna el valor
    bool es_visible() const;
    //Pre:--
    //Post:Retorna si un booleà de si està visible o no
    int aconseguir_pila_pal() const;
    //Pre:--
    //Post:Retorna la pila corresponent al pal
    // 0 per piques
    // 1 per cors
    // 2 per diamants
    // 3 per trèvol
    bool diferent_color(Carta carta)const;
    //Pre:--
    //Post:Retorna true si les cartes són de diferent color
    
    void mostra_carta()const;
    //Pre:--
    //Post:Mostra el valor i el pal de la carta
    
    bool es_negre()const;
    //Pre:--
    //Post:Retorna true si la carta és negre
    

private:
    //ATRIBUTS
    char a_pal;
    int a_valor;
    bool a_visible;


};

#endif /* CARTA_hpp */
