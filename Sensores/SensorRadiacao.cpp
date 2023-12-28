//
// Created by henri on 24/10/2023.
//

#include "SensorRadiacao.h"
#include "../Zona.h"
#include <sstream>

SensorRadiacao::SensorRadiacao(Zona* zona): Sensor(zona){}

//getters
string SensorRadiacao::getNome() const {return "d" + to_string(getId());}

char SensorRadiacao::getAbreviacao() const {return 'd';}

string SensorRadiacao::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

int SensorRadiacao::fazLeitura() {
    int valor = getZonaAssociada()->obtemValorPropriedade("Radiacao");

    setValorUltimaLeitura(valor);
    return 0; //retorna o valor da leitura
}