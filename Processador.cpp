//
// Created by João Carvalho on 12/11/2023.
//

#include "Processador.h"

bool Processador::adicionaRegra(const Regra& regra) {
    regras.push_back(regra);
    return true;
}