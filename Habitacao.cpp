//
// Created by João Carvalho on 21/10/2023.
//

#include "Habitacao.h"

Habitacao::Habitacao(int nLinhas, int nColunas): maxLinha(nLinhas), maxColuna(nColunas) {
}

Habitacao::~Habitacao(){
    // TODO quando uma habitacao é criada e ja existe uma a habitacao que existia tem que ser destruida tao bem como tudo o que la existia

    for(Zona* aux: zonas){
        delete aux;
    }

    cout << "Habitacao destruida" << endl;
}

void Habitacao::criaHabitacao(){

    // TODO nesta funcao fazer apenas a printagem do board

    /*Zona * obj;
    vector<string>aux;

    for (int i = 0; i < maxLinha; i++)
    {
        vector<Zona*> temp;

        for (int j = 0; j < maxColuna; j++)
        {
            obj = new Zona();
            temp.push_back(obj);
        }
        //zonaH.push_back(temp); //zonas obviamente
    }*/


}

void Habitacao::adicionaZona(Zona* novaZona) {
    zonas.push_back(novaZona);
}

//getters
int Habitacao::getMaxLinha() const {return maxLinha;}

int Habitacao::getMaxColuna() const {return maxColuna;}

vector<Zona*> Habitacao::getZonas(){
    return zonas;
}

string Habitacao::listaZonas() const {

    ostringstream oss;

    for(Zona* zona: zonas){
        oss << zona->zonaAsString();
    }

    return oss.str();
}




/*
   string auxzo, auxed, auxtr, auxcont;
    Zona *obj;
    srand(time(NULL));
    vector<string>aux;

    for (int i = 0; i < MaxLinhaCriar; i++)
    {
        vector<Zona> temp;
        for (int j = 0; j < MaxColunaCriar; j++)
        {
            obj = new Zona();
            temp.push_back(obj);
        }
        zonailha.push_back(temp);
    }


*/