//
// Created by João Carvalho on 24/10/2023.
//

#include "Sensor.h"

int Sensor::idSensor = 0;

Sensor::Sensor() {
    idSensor++;
    id = idSensor;
}

Sensor::~Sensor() {
    idSensor = 0;
}

int Sensor::getId() const {return id;}

string Sensor::getEquipamentoAsString() const {

    ostringstream oss;

    oss << endl << "ID: " << id << endl
        << "Nome: " << this->getNome() << endl
        << "Estado: " << "COMPLETAR" <<endl;

    return oss.str();
}
