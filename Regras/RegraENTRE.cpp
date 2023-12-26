//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraENTRE.h"
#include <sstream>

RegraENTRE::RegraENTRE(Sensor* sensor, const int &num1, const int &num2): Regra(sensor, num1, num2) {}

Regra* RegraENTRE::duplica() const {
    return new RegraENTRE(*this);
}

bool RegraENTRE::avaliaMedicoes() const {
    int leitura = Regra::obtemSensor()->fazLeitura();

    if(Regra::getNum1() < leitura < Regra::getNum2())
        return true;
    else return false;
}

string RegraENTRE::getNome() const { return "Regra Entre"; }

string RegraENTRE::getRegraAsString() const {
    ostringstream oss;

    oss << Regra::getRegraAsString()
        << "Nome: " << getNome() << endl
        << "Id Sensor associado: " << obtemSensor()->getId() << endl;

    return oss.str();
}
