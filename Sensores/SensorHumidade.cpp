//
// Created by henri on 24/10/2023.
//

#include "SensorHumidade.h"
#include <sstream>

//getters
string SensorHumidade::getNome() const {return "Sensor Humidade";}

char SensorHumidade::getAbreviacao() const {return 'h';}

string SensorHumidade::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

int SensorHumidade::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}