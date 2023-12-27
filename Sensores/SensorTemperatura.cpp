//
// Created by henri on 24/10/2023.
//

#include "SensorTemperatura.h"
#include <sstream>

//getters
string SensorTemperatura::getNome() const {return "t" + to_string(getId());}

char SensorTemperatura::getAbreviacao() const {return 't';}

string SensorTemperatura::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

int SensorTemperatura::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}