//
// Created by João Carvalho on 22/10/2023.
//

#include "Refrigerador.h"

Refrigerador::Refrigerador() {
    nome        = "Refrigerador";
    abreviacao  = 'r';
    isLigado    = false;
}

//getters
string Refrigerador::getNome() const {return nome;}

char Refrigerador::getAbreviacao() const {return abreviacao;}

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
