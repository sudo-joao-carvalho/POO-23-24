//
// Created by henri on 24/10/2023.
//

#include "SensorSom.h"
#include "../Zona.h"
#include <sstream>

SensorSom::SensorSom(Zona* zona): Sensor(zona){}

//getters
string SensorSom::getNome() const {return "o" + to_string(getId());}

char SensorSom::getAbreviacao() const {return 'o';}

string SensorSom::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

double SensorSom::fazLeitura() {
    double valor = getZonaAssociada()->obtemValorPropriedade("Som");

    setValorUltimaLeitura(valor);
    return valor; //retorna o valor da leitura
}