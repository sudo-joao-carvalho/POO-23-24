//
// Created by João Carvalho on 12/11/2023.
//

#include "Regra.h"

Regra::Regra(Sensor& sensor):sensor(sensor) {}

Regra::~Regra() {}

Sensor& Regra::obtemSensor() const {return sensor;}