//
// Created by henri on 24/10/2023.
//





#include "SensorLuminosidade.h"


SensorLuminosidade::SensorLuminosidade()  {
    nome  = "Sensor Luminosidade";
    letra = 'm';

}

//getters
string SensorLuminosidade::getNome() const {return nome;}

char SensorLuminosidade::getAbreviacao() const {return letra;}