//
// Created by henri on 24/10/2023.
//

#include "SensorLuminosidade.h"
#include "../Zona.h"
#include <sstream>

SensorLuminosidade::SensorLuminosidade(Zona* zona): Sensor(zona){}

//getters
string SensorLuminosidade::getNome() const {return "m" + to_string(getId());}

char SensorLuminosidade::getAbreviacao() const {return 'm';}

string SensorLuminosidade::getSensorAsString() const {

    ostringstream oss;

    oss << Sensor::getSensorAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl;

    return oss.str();
}

int SensorLuminosidade::fazLeitura() {
    int valor = getZonaAssociada()->obtemValorPropriedade("Luminosidade");

    setValorUltimaLeitura(valor);
    return 0; //retorna o valor da leitura
}