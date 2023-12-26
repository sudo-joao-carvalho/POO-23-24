//
// Created by João Carvalho on 24/10/2023.
//

#include "Sensor.h"
#include <sstream>

int Sensor::idSensor = 0;

Sensor::Sensor() {
    idSensor++;
    id = idSensor;
}

Sensor::~Sensor() {
    idSensor = 0;
}

int Sensor::getId() const {return id;}

string Sensor::getSensorAsString() const {

    ostringstream oss;

    oss << endl << "ID: " << id << endl;
    //TODO meter aqui o valor atual da leitura

    return oss.str();
}
