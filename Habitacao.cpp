//
// Created by João Carvalho on 21/10/2023.
//

#include "Habitacao.h"

Habitacao::Habitacao(int nLinhas, int nColunas): maxLinha(nLinhas), maxColuna(nColunas) {
}

Habitacao::~Habitacao(){
    // TODO quando uma habitacao é criada e ja existe uma a habitacao que existia tem que ser destruida tao bem como tudo o que la existia

    cout << "Habitacao destruida" << endl;
}

void Habitacao::criaHabitacao(){

    /*Zonas * obj;
    vector<string>aux;

    for (int i = 0; i < maxLinha; i++)
    {
        vector<Zonas*> temp;

        for (int j = 0; j < maxColuna; j++)
        {
            obj = new Zonas();
            temp.push_back(obj);
        }
        //zonaH.push_back(temp); //zonas obviamente
    }*/


}






/*
   string auxzo, auxed, auxtr, auxcont;
    Zonas *obj;
    srand(time(NULL));
    vector<string>aux;

    for (int i = 0; i < MaxLinhaCriar; i++)
    {
        vector<Zonas> temp;
        for (int j = 0; j < MaxColunaCriar; j++)
        {
            obj = new Zonas();
            temp.push_back(obj);
        }
        zonailha.push_back(temp);
    }


*/