//
// Created by henri on 24/10/2023.
//

#include "SensorFumo.h"
#include "../Zona.h"
#include <sstream>

SensorFumo::SensorFumo(Zona* zona): Sensor(zona){}

//getters
string SensorFumo::getNome() const {return "f" + to_string(getId());}

char SensorFumo::getAbreviacao() const {return 'f';}

string SensorFumo::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

double SensorFumo::fazLeitura() {
    double valor = getZonaAssociada()->obtemValorPropriedade("Fumo");
    setValorUltimaLeitura(valor);
    return valor; //retorna o valor da leitura
}