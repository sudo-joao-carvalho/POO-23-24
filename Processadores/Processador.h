//
// Created by João Carvalho on 12/11/2023.
//

#ifndef POO_23_24_PROCESSADOR_H
#define POO_23_24_PROCESSADOR_H

#include <string>
#include <vector>

#include "../Regras/Regra.h"

using namespace std;

class Processador {

public:
    Processador();
    ~Processador();

    bool adicionaRegra(const Regra& regra);

    //getters & setters
    int getId() const;

private:
    static int idProcessador;
    int id;
    string comandoOutput;
    vector<Regra*> regras; //composicao

};


#endif //POO_23_24_PROCESSADOR_H
