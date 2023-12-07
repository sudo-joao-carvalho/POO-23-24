//
// Created by henri on 24/10/2023.
//

#include "SensorRadiacao.h"
#include <sstream>

//getters
string SensorRadiacao::getNome() const {return "Sensor Radiacao";}

char SensorRadiacao::getAbreviacao() const {return 'd';}

string SensorRadiacao::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

int SensorRadiacao::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}