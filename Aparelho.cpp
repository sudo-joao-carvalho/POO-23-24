//
// Created by João Carvalho on 21/10/2023.
//

#include "Aparelho.h"

int Aparelho::idAparelho = 0;

Aparelho::Aparelho() {
    idAparelho++;
}

int Aparelho::getIdAparelho() const {return idAparelho;}
