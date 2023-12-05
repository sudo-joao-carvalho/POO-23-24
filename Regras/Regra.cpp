//
// Created by João Carvalho on 12/11/2023.
//

//sensor ativa processador e o sensor sabe qual e o processador de regras sabe qual e o sensor
//fazer classes para cada propriedade

#include "Regra.h"

Regra::Regra(Sensor& sensor):sensor(sensor) {}

Regra::~Regra() {}

Sensor& Regra::obtemSensor() const {return sensor;}