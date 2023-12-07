//
// Created by João Carvalho on 22/10/2023.
//

#include "Aquecedor.h"
#include <sstream>

Aquecedor::Aquecedor() {
    isLigado    = false;
}

//getters
string Aquecedor::getNome() const {return "Aquecedor";}

char Aquecedor::getAbreviacao() const {return 'a';}

string Aquecedor::getAparelhoAsString() const {

    ostringstream oss;

    oss << Aparelho::getAparelhoAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl
        << "Estado: " << isLigado << endl;

    return oss.str();

}

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