#include "Joc.hpp"

Joc::Joc() {
    a_baralla = Baralla();
    a_baralla.barrejar();
    a_n_jugadors = 0;
    a_pilaCartes.resize(4);
}

Joc::Joc(unsigned llavor) {
    a_baralla = Baralla(llavor);
    a_baralla.barrejar();
    a_n_jugadors = 0;
    a_pilaCartes.resize(4);
}

void Joc::estat_joc(bool espiar) const
{
    cout << "ESTAT DEL JOC" << endl;
    

    if (!a_pilaCartes.empty())
    {
        for (int i = 0; i < a_pilaCartes.size(); i++)
        {
            if (!a_pilaCartes[i].empty()){
                a_pilaCartes[i].top().mostra_carta();
                cout<< " ";

            }
            
            else cout << "   ";
        }
    }
    cout << "   ";
    
    if(!a_ma.empty())
        cout << "** ";
    else cout << "   ";
    if (!a_descartades.empty())
    {
        /*if (a_descartades.top().aconseguir_valor() == 1)
            cout << "A";
        else if (a_descartades.top().aconseguir_valor() == 10)
            cout << "D";
        else if (a_descartades.top().aconseguir_valor() == 11)
            cout << "J";
        else if (a_descartades.top().aconseguir_valor() == 12)
            cout << "Q";
        else if (a_descartades.top().aconseguir_valor() == 13)
            cout << "K";
        else cout << a_descartades.top().aconseguir_valor();
        cout << a_descartades.top().aconseguir_pal();*/
        a_descartades.top().mostra_carta();
    }
    cout << endl;
   
    a_tauler.mostrar_condicional(espiar, partida_guanyada);
}

void Joc::obrir_carta()
{
    if (a_ma.empty())
    {
        while (!a_descartades.empty()){
            a_ma.push(a_descartades.top());
            a_descartades.pop();
        }
    }
   
    else{
        a_descartades.push(a_ma.top());
        a_ma.pop();        
    }
    estat_joc(false);}

void Joc::posar_carta()
{
    if (a_descartades.empty())
        cout << "NO HI HA CAP CARTA PER AGAFAR" << endl;
    else
    {
        int col;
        cout << "A QUINA COLUMNA LA VOLS POSAR:" << endl;
        cin >> col;
        bool posar = a_tauler.posar_carta(col-1, a_descartades.top());
        if (!posar){
            cout<<"LA CARTA NO ES POT POSAR A LA COLUMNA "<<col<<endl;
            
        }
        else{
            a_descartades.pop();
        }
    }
    estat_joc(false);


}

void Joc::posar_carta_tauler_tauler(){
    a_tauler.posar_carta_tauler_tauler();
    estat_joc(false);
}


bool Joc::insertar_a_pila(Carta c)
{
    bool inserit = false;
    int num_pila = c.aconseguir_pila_pal();
    int elements_a_pila = (int)a_pilaCartes[num_pila].size();
    int valor_carta = c.aconseguir_valor();
    if (valor_carta == elements_a_pila+1)
    {
        inserit = true;
        a_pilaCartes[num_pila].push(c);
    }
    else{
        cout << "LA CARTA NO ES POT APILAR" << endl;
        
    }
    return inserit;
}
void Joc::joc_guanyat(){
    bool guanyat = (a_pilaCartes[0].size()==13 and a_pilaCartes[1].size()==13 and a_pilaCartes[2].size()==13 and a_pilaCartes[3].size()==13);
    if (guanyat)
        partida_guanyada = true;
}

void Joc::posar_carta_ma_pila() {
    //P,c,d,T
    if (!a_descartades.empty())
    {
        Carta c = a_descartades.top();
        bool inserit = insertar_a_pila(c);
        if (inserit){
            a_descartades.pop();
        }        
    }
    else{
        cout << "NO HI HA CAP CARTA PER AGAFAR" << endl;
    }
    joc_guanyat();
    estat_joc(false);
}

void Joc::posar_carta_tauler_pila() {
    int col_origen;
    cout << "ENTRA LA COLUMNA ORIGEN:" << endl;
    cin >> col_origen;
    col_origen--;
    bool columna_erronia = false;
    //esperem columna entre 0 i 7
    if (col_origen >=0 and col_origen < 8){
        Carta carta;
        bool trobat = a_tauler.obtenir_ultima_carta_de_columna(carta, col_origen);
        if (trobat){
            bool inserit = insertar_a_pila(carta);
            if (inserit)
            {
                //cal eliminar la carta del tauler
                a_tauler.eliminar_ultima_carta_de_columna(col_origen);
            }
            
        }
        else{
            columna_erronia = true;
        }
    }
    else{
        columna_erronia = true;
    }
    if (columna_erronia)
        cout << "Columna incorrecte" << endl;
    estat_joc(false);
}

bool Joc:: partida_acabada(){
    return partida_guanyada;
}
void Joc::posar_carta_pila_tauler(){
    int col_origen;
    cout << "ENTRA LA PILA:" << endl;
    cin >> col_origen;
    col_origen--;
    
    bool podem_moure = false;
    //esperem columna entre 0 i 7
    if (col_origen >=0 and col_origen < 4){
        int elements_a_pila =(int)a_pilaCartes[col_origen].size();
        if (elements_a_pila > 0){
            Carta carta_origen = a_pilaCartes[col_origen].top();
            int col_desti;
            cout << "A QUINA COLUMNA LA VOLS POSAR:" << endl;
            cin >> col_desti;
            col_desti--;
            Carta carta_tauler;
            
            if (col_desti >=0 and col_desti < 7){
                
                bool trobada = a_tauler.obtenir_ultima_carta_de_columna(carta_tauler, col_desti);
                //si no hem trobat cap carta, és la que columna és buida, pel que hi podem posar
                //la carta de la pila
                if (not trobada){
                    podem_moure = true;
                }
                else if (carta_tauler.es_negre() !=carta_origen.es_negre() and carta_tauler.aconseguir_valor()==carta_origen.aconseguir_valor()+1){
                    podem_moure = true;
                }
            }
            if (podem_moure){
                //cal moure carta al tauler i treure-la de la pila
                a_pilaCartes[col_origen].pop();
                a_tauler.insertar_carta(carta_origen, col_desti);
            }
            else
                cout << "LA CARTA NO ES POT MOURE AL TAULER" << endl;
        }
        else {
           cout <<"A LA PILA NO HI HA CAP CARTA PER RECUPERAR" << endl;
            
        }
    }
    
    estat_joc(false);
}



void Joc::tauler(Baralla b)
{
    vector<Carta> aux = b.pilaCartes();
    int i = (int)aux.size() - 1;
    a_tauler.repartir(b, i);
    for (int j = i; j >= 0; j--)
    {
        a_ma.push(aux[j]);
    }
}
