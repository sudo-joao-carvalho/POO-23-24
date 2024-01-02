//
// Created by henri on 24/10/2023.
//

#include "SensorMovimento.h"
#include "../Zona.h"
#include <sstream>

SensorMovimento::SensorMovimento(Zona* zona): Sensor(zona){}

//getters
string SensorMovimento::getNome() const {return "v" + to_string(getId());}

char SensorMovimento::getAbreviacao() const {return 'v';}

string SensorMovimento::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

double SensorMovimento::fazLeitura() {
    double valor = getZonaAssociada()->obtemValorPropriedade("Vibracao");

    setValorUltimaLeitura(valor);
    return valor; //retorna o valor da leitura
}