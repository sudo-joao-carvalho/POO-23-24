//
// Created by João Carvalho on 21/10/2023.
//

#include "Aparelho.h"
#include <sstream>

int Aparelho::idAparelho = 0;

Aparelho::Aparelho(){
    idAparelho++;
    id = idAparelho;
}

Aparelho::~Aparelho() {
    idAparelho = 0;
}

int Aparelho::getId() const {return id;}

string Aparelho::getAparelhoAsString() const {

    ostringstream oss;

    oss << endl << "ID: " << id << endl;
    //TODO meter aqui o ultimo comando recebido

    return oss.str();
}
