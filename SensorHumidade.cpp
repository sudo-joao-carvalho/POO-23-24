//
// Created by henri on 24/10/2023.
//

#include "SensorHumidade.h"


SensorHumidade::SensorHumidade()  {
    nome  = "Sensor Humidade";
    letra = 'h';

}

//getters
string SensorHumidade::getNome() const {return nome;}

char SensorHumidade::getAbreviacao() const {return letra;}