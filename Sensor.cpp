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

string Sensor::getEquipamentoAsString() const {

    ostringstream oss;

    oss << endl << "ID: " << id << endl
        << "Nome: " << this->getNome() << endl
        << "Estado: " << "COMPLETAR" <<endl;

    return oss.str();
}

// TODO Barracas fazer as classes derivadas do sensor -> tipo as classes derivadas do aparelho