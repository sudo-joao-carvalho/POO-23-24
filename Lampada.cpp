//
// Created by João Carvalho on 22/10/2023.
//

#include "Lampada.h"

Lampada::Lampada() {
    nome        = "Lampada";
    abreviacao  = 'l';
    isLigado    = false;
}

//getters
string Lampada::getNome() const {return nome;}

char Lampada::getAbreviacao() const {return abreviacao;}

bool Lampada::liga() {
    isLigado = true;

    return isLigado;
}

bool Lampada::desliga() {
    isLigado = false;

    return isLigado;
}

//setters
/*void Lampada::setIsLigado(bool isLigado) {
    this->isLigado = isLigado;
}*/
