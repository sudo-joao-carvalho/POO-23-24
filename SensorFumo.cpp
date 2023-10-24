//
// Created by henri on 24/10/2023.
//

#include "SensorFumo.h"


SensorFumo::SensorFumo() {
    nome  = "Sensor Fumo";
    letra = 'f';

}

//getters
string SensorFumo::getNome() const {return nome;}

char SensorFumo::getAbreviacao() const {return letra;}
