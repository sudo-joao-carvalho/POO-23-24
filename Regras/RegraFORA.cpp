//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraFORA.h"
#include <sstream>

RegraFORA::RegraFORA(Sensor* sensor, const double &num1, const double &num2):Regra(sensor, num1, num2) {}

Regra* RegraFORA::duplica() const {
    return new RegraFORA(*this);
}

bool RegraFORA::avaliaMedicoes() const {
    double leitura = obtemSensor()->fazLeitura();

    if(leitura < getNum1() && leitura > getNum2())
        return true;
    else return false;
}

string RegraFORA::getNome() const { return "Regra Fora"; }

string RegraFORA::getRegraAsString() const {
    ostringstream oss;

    oss << Regra::getRegraAsString()
        << "Nome: " << getNome() << endl
        << "Id Sensor associado: " << obtemSensor()->getId() << endl;

    return oss.str();
}