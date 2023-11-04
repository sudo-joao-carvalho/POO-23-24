//
// Created by João Carvalho on 21/10/2023.
//

#include "Aparelho.h"

int Aparelho::idAparelho = 0;

Aparelho::Aparelho(){
    idAparelho++;
    id = idAparelho;
}

Aparelho::~Aparelho() {
    idAparelho = 0;
}

int Aparelho::getId() const {return id;}

string Aparelho::getEquipamentoAsString() const {

    ostringstream oss;

    oss << endl << "ID: " << id << endl
        << "Nome: " << this->getNome() << endl
        << "Estado: " << "COMPLETAR" << endl;

    return oss.str();
}
