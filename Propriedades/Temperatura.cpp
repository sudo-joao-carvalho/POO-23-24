//
// Created by João Carvalho on 07/12/2023.
//

#include "Temperatura.h"

string Temperatura::getNome() const { return "Temperatura"; }

string Temperatura::getUnidade() const { return "graus celcius"; }

float Temperatura::getValorMinimo() const { return -273.0; }

float Temperatura::getValorMaximo() const {}