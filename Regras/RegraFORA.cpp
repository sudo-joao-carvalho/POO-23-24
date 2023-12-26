//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraFORA.h"
#include <sstream>

RegraFORA::RegraFORA(Sensor* sensor, const int &num1, const int &num2):Regra(sensor, num1, num2) {}

Regra* RegraFORA::duplica() const {
    return new RegraFORA(*this);
}

bool RegraFORA::avaliaMedicoes() const {
    int leitura =  Regra::obtemSensor()->fazLeitura();

    if(leitura < Regra::getNum1() && leitura > Regra::getNum2())
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