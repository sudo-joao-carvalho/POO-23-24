//
// Created by henri on 24/10/2023.
//

#include "SensorMovimento.h"


SensorMovimento::SensorMovimento()  {
    nome  = "Sensor Movimento";
    letra = 'v';

}

//getters
string SensorMovimento::getNome() const {return nome;}

char SensorMovimento::getAbreviacao() const {return letra;}