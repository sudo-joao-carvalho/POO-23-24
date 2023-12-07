//
// Created by João Carvalho on 22/10/2023.
//

#include "Refrigerador.h"

Refrigerador::Refrigerador() {
    isLigado    = false;
}

//getters
string Refrigerador::getNome() const {return "Refrigerador";}

char Refrigerador::getAbreviacao() const {return 'r';}

bool Refrigerador::liga() {
    isLigado = true;

    return isLigado;
}

bool Refrigerador::desliga() {
    isLigado = false;

    return isLigado;
}

//setters
/*void Refrigerador::setIsLigado(bool isLigado) {
    this->isLigado = isLigado;
}*/
