//
// Created by João Carvalho on 07/12/2023.
//

#include "Humidade.h"

string Humidade::getNome() const { return "Humidade"; }

string Humidade::getUnidade() const { return "%"; }

float Humidade::getValorMinimo() const { return 0.0; }

float Humidade::getValorMaximo() const { return 100; }