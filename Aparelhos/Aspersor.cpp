//
// Created by João Carvalho on 22/10/2023.
//

#include "Aspersor.h"
#include <sstream>

Aspersor::Aspersor() {
    isLigado    = false;
}

//getters
string Aspersor::getNome() const {
    if(isLigado)
        return "S" + to_string(getId());

    return "s" + to_string(getId());
}

char Aspersor::getAbreviacao() const {return 's';}

string Aspersor::getAparelhoAsString() const {

    ostringstream oss;

    oss << Aparelho::getAparelhoAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl
        << "Estado: " << isLigado << endl;

    return oss.str();

}

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
