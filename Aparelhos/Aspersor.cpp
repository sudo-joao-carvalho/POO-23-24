//
// Created by João Carvalho on 22/10/2023.
//

#include "Aspersor.h"

Aspersor::Aspersor() {
    isLigado    = false;
}

//getters
string Aspersor::getNome() const {return "Aspersor";}

char Aspersor::getAbreviacao() const {return 's';}

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
