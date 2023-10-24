//
// Created by henri on 24/10/2023.
//

#include "SensorSom.h"

SensorSom::SensorSom()  {
    nome  = "Sensor Som";
    letra = 'o';

}

//getters
string SensorSom::getNome() const {return nome;}

char SensorSom::getAbreviacao() const {return letra;}