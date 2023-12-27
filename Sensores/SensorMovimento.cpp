//
// Created by henri on 24/10/2023.
//

#include "SensorMovimento.h"
#include <sstream>

//getters
string SensorMovimento::getNome() const {return "v" + to_string(getId());}

char SensorMovimento::getAbreviacao() const {return 'v';}

string SensorMovimento::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

int SensorMovimento::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}