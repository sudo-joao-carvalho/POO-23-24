//
// Created by João Carvalho on 12/11/2023.
//

//sensor ativa processador e o sensor sabe qual e o processador de regras sabe qual e o sensor
//fazer classes para cada propriedade

#include "Regra.h"
#include <sstream>

int Regra::idS = 0;

Regra::Regra(Sensor& sensor):sensor(sensor), id(idS++) {}

Sensor& Regra::obtemSensor() const {return sensor;}

string Regra::getRegraAsString() const {

    ostringstream oss;

    oss << "ID: " << id << endl;

    return oss.str();
}

int Regra::getId() const {
    return id;
}
