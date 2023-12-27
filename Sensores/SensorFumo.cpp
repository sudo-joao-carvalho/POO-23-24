//
// Created by henri on 24/10/2023.
//

#include "SensorFumo.h"
#include <sstream>

//getters
string SensorFumo::getNome() const {return "f" + to_string(getId());}

char SensorFumo::getAbreviacao() const {return 'f';}

string SensorFumo::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

int SensorFumo::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}