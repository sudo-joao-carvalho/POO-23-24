//
// Created by João Carvalho on 22/10/2023.
//

#include "Aspersor.h"

Aspersor::Aspersor() {
    nome        = "Aspersor";
    abreviacao  = 's';
    isLigado    = false;
}

//getters
string Aspersor::getNome() const {return nome;}

char Aspersor::getAbreviacao() const {return abreviacao;}

bool Aspersor::liga() {
    isLigado = true;

    return isLigado;
}

bool Aspersor::desliga() {
    isLigado = false;

    return isLigado;
}

//setters
/*void Aspersor::setIsLigado(bool isLigado) {
    this->isLigado = isLigado;
}*/
