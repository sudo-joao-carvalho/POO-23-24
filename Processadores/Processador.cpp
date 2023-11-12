//
// Created by João Carvalho on 12/11/2023.
//

#include "Processador.h"

int Processador::idProcessador = 0;

Processador::Processador():id(++idProcessador) {}

bool Processador::adicionaRegra(const Regra& regra) {
    regras.push_back(regra);
    return true;
}

int Processador::getId() const {
    return id;
}
