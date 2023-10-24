//
// Created by João Carvalho on 24/10/2023.
//

#include "Sensor.h"

int Sensor::idSensor = 0;

Sensor::Sensor() {
    idSensor++;
    id = idSensor;
}

int Sensor::getId() const {return id;}

// TODO Barracas fazer as classes derivadas do sensor -> tipo as classes derivadas do aparelho