//
// Created by henri on 24/10/2023.
//





#include "SensorLuminosidade.h"
#include <sstream>

//getters
string SensorLuminosidade::getNome() const {return "Sensor Luminosidade";}

char SensorLuminosidade::getAbreviacao() const {return 'm';}

string SensorLuminosidade::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

int SensorLuminosidade::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}