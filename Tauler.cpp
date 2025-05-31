#include "Tauler.hpp"
#include <iostream>
#include <iomanip>
#include "Carta.hpp"

Tauler::Tauler() {
    a_n_columnes = a_n_files = MIDA_TAULER;
    vector<Carta> aux(a_n_columnes, Carta());
    a_tauler.resize(8);
}

Tauler::Tauler(int mida) {
    a_n_columnes = a_n_files = mida;
    vector<Carta> aux(a_n_columnes, Carta());
    a_tauler.resize(8);
}

int Tauler::mida() const {
    
    return a_n_columnes;
}

void Tauler::repartir(Baralla b, int &i)
{
    vector<Carta> aux = b.pilaCartes();
    for (int j = 0; j < 7; j++)
    {
        for (int k = 0; k < j+1; k++)
        {
            //A l'inicialitzar, només volem visibles els elements de la diagonal
            if (k==j){
                aux[i].ensenya();
            }
            else{
                aux[i].oculta();
            }
            a_tauler[j].push_back(aux[i]);
            i--;
        }
    }
}



void Tauler::mostrar_condicional(bool espiar, bool partida_guanyada)const{
    int max_files=0;
    for (int i = 1; i <= 7; i++)
    {
        cout << "c" << i << " ";
        int mida = (int)a_tauler[i-1].size();
        max_files = max(mida, max_files);
    }
    cout << endl;


    for (unsigned int k = 0; k < max_files; k++)
    {
        for (unsigned int j = 0; j < a_tauler.size()-1; j++)
        {
            unsigned int nactual_files = (int)a_tauler[j].size();
           
            if (k>= nactual_files)
                cout << "   ";
            else{
                if (not espiar and not a_tauler[j][k].es_visible()){
                    cout<<"** ";
                }
                else{
                    if (a_tauler[j][k].aconseguir_valor() == 1)
                        cout << "A";
                    else if (a_tauler[j][k].aconseguir_valor() == 10)
                        cout << "D";
                    else if (a_tauler[j][k].aconseguir_valor() == 11)
                        cout << "J";
                    else if (a_tauler[j][k].aconseguir_valor() == 12)
                        cout << "Q";
                    else if (a_tauler[j][k].aconseguir_valor() == 13)
                        cout << "K";
                    else cout << a_tauler[j][k].aconseguir_valor();
                    cout << a_tauler[j][k].aconseguir_pal() << " ";
                    
                }            }
            
           
        }
        cout <<"f" << k+1 << endl;
    }
    if (partida_guanyada){
        cout << "JOC ACABAT" << endl;
        cout << "HAS GUANYAT LA PARTIDA!" << endl;
    }
    else
        cout << "JOC EN CURS" << endl;

   
}



bool Tauler::posar_carta(int col, Carta c)
{
    bool afegir = false;
    unsigned int n_cartes = (int)a_tauler[col].size();
    Carta carta_desti = a_tauler[col][n_cartes-1];
    bool dif_color = c.diferent_color(carta_desti);
    int valor = c.aconseguir_valor();
    int valor_desti = carta_desti.aconseguir_valor();
    if (valor == valor_desti-1 and dif_color){
        insertar_carta(c,col);
        afegir = true;
    }
    
    return afegir;
}

void Tauler::posar_carta_tauler_tauler(){
    bool input_ok = true;
    bool input_desti = true;
    int col_origen,fila_origen;
    bool podem_moure=false;
    cout << "ENTRA LA COLUMNA ORIGEN I LA FILA ORIGEN:" << endl;
    cin >> col_origen;
    cin >> fila_origen;
    //Volem els números entre 0 i 7
    col_origen--; fila_origen--;
    if (col_origen<0 or col_origen>7){
        input_ok = false;
    }
    else{
        //Mirem si hi ha carta a la fila indicada
        int llargada_fila = (int)a_tauler[col_origen].size();
        if (fila_origen >=0 and fila_origen <= llargada_fila)
        {
            //Mirem si la carta és visible
            bool esVisible = a_tauler[col_origen][fila_origen].es_visible();
            if (not esVisible)
            {
                input_ok = false;
            }
            else{
                cout << "ENTRA LA COLUMNA DESTI:"<<endl;
                int col_desti;
                //Volem els números entre 0 i 7
                cin>>col_desti;
                col_desti--;
                if (col_desti<0 or col_desti>7){
                    input_desti = false;
                }
                else{
                    int elements_a_col = (int)a_tauler[col_desti].size();
                    if (elements_a_col==0){
                        podem_moure = true;
                    }
                    else{
                        Carta carta_desti=a_tauler[col_desti][elements_a_col-1];
                        Carta carta_origen=a_tauler[col_origen][fila_origen];
                        if (carta_desti.es_negre() !=carta_origen.es_negre() and carta_desti.aconseguir_valor()==carta_origen.aconseguir_valor()+1){
                            podem_moure = true;
                        }
                    }
                    if (podem_moure)
                    {
                        int llargada_origin = (int)a_tauler[col_origen].size();
                        int elements_moguts = 0;
                        for (int k=fila_origen; k< llargada_origin; k++){
                            a_tauler[col_desti].push_back(a_tauler[col_origen][k]);
                            ++elements_moguts;
                        }
                        for (int k=0;k<elements_moguts;++k)
                        {
                            a_tauler[col_origen].pop_back();
                        }
                        //Cal mostrar la darrera carta si no era visible
                        a_tauler[col_origen][a_tauler[col_origen].size()-1].ensenya();   
                    }
                    else{
                        cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << col_desti+1<< endl;
                    }
                }
            }
        }
        else
        {
            input_ok = false;
        }
        if (not input_ok)
        {
            cout << "LA CARTA NO ES POT MOURE" << endl;
        }
    }
}

bool Tauler::eliminar_ultima_carta_de_columna(int col){
    bool eliminat = false;
    int elements = (int)a_tauler[col].size();
    if (elements>0)
    {
        a_tauler[col].pop_back();
        eliminat = true;
        //hem de mostrar la darrera carta de la columna
        elements = (int)a_tauler[col].size();
        if (elements>0){
            a_tauler[col][elements-1].ensenya();
        }
    }
    return eliminat;
}
bool Tauler::obtenir_ultima_carta_de_columna(Carta &carta, int col){
    bool trobat = false;
    int elements = (int)a_tauler[col].size();
    if (elements>0)
    {
        carta = a_tauler[col][elements-1];
        trobat = true;
    }
    return trobat;
}
void Tauler::insertar_carta(Carta c, int col)
{
        a_tauler[col].push_back(c);
}
