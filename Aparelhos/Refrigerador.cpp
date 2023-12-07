//
// Created by João Carvalho on 22/10/2023.
//

#include "Refrigerador.h"
#include <sstream>

Refrigerador::Refrigerador() {
    isLigado    = false;
}

//getters
string Refrigerador::getNome() const {return "Refrigerador";}

char Refrigerador::getAbreviacao() const {return 'r';}

string Refrigerador::getAparelhoAsString() const {

    ostringstream oss;

    oss << Aparelho::getAparelhoAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl
        << "Estado: " << isLigado << endl;

    return oss.str();
}

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
