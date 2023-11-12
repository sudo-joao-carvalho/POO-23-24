//
// Created by João Carvalho on 12/11/2023.
//

#ifndef POO_23_24_PROCESSADOR_H
#define POO_23_24_PROCESSADOR_H

#include <string>
#include <vector>

#include "Regra.h"

using namespace std;

class Processador {

public:
    Processador() = default;

    bool adicionaRegra(const Regra& regra);

private:
    string comandoOutput;
    vector<Regra> regras;

};


#endif //POO_23_24_PROCESSADOR_H
