//
// Created by henri on 24/10/2023.
//

#include "SensorSom.h"
#include <sstream>

//getters
string SensorSom::getNome() const {return "Sensor Som";}

char SensorSom::getAbreviacao() const {return 'o';}

string SensorSom::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

int SensorSom::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}