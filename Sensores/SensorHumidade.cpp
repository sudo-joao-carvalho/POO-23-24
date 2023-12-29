//
// Created by henri on 24/10/2023.
//

#include "SensorHumidade.h"
#include "../Zona.h"
#include <sstream>

SensorHumidade::SensorHumidade(Zona* zona): Sensor(zona){}

//getters
string SensorHumidade::getNome() const {return "h" + to_string(getId());}

char SensorHumidade::getAbreviacao() const {return 'h';}

string SensorHumidade::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

double SensorHumidade::fazLeitura() {
    double valor = getZonaAssociada()->obtemValorPropriedade("Humidade");

    setValorUltimaLeitura(valor);
    return valor; //retorna o valor da leitura
}