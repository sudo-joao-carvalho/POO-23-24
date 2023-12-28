//
// Created by João Carvalho on 24/10/2023.
//

#include "Sensor.h"
#include "../Zona.h"
#include <sstream>

int Sensor::idSensor = 0;

Sensor::Sensor(Zona* zona):id(++idSensor), valorUltimaLeitura(-999), zona(zona) {
    /*idSensor++;
    id = idSensor;*/
}

Sensor::~Sensor() {
    //idSensor = 0;
}

int Sensor::getId() const {return id;}

string Sensor::getSensorAsString() const {

    ostringstream oss;

    oss << endl << "ID: " << id << endl
        << "Valor ultima leitura: " << valorUltimaLeitura << endl;

    return oss.str();
}

int Sensor::getValorUltimaLeitura() const{ return valorUltimaLeitura; }
void Sensor::setValorUltimaLeitura(const int &leitura) { this->valorUltimaLeitura = leitura; }

Zona* Sensor::getZonaAssociada() { return zona; }
