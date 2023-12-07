//
// Created by João Carvalho on 07/12/2023.
//

#include "Fumo.h"

string Fumo::getNome() const { return "Fumo"; }

string Fumo::getUnidade() const { return "Obscuracao (%)"; }

float Fumo::getValorMinimo() const { return 0.0; }

float Fumo::getValorMaximo() const { return 100; }