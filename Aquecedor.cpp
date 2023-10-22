//
// Created by João Carvalho on 22/10/2023.
//

#include "Aquecedor.h"

Aquecedor::Aquecedor() {
    nome        = "Aquecedor";
    abreviacao  = 'a';
    isLigado    = false;
}

//getters
string Aquecedor::getNome() const {return nome;}

char Aquecedor::getAbreviacao() const {return abreviacao;}

bool Aquecedor::liga() {
    isLigado = true;

    return isLigado;
}

bool Aquecedor::desliga() {
    isLigado = false;

    return isLigado;
}

//setters
/*void Aquecedor::setIsLigado(bool isLigado) {
    this->isLigado = isLigado;
}*/