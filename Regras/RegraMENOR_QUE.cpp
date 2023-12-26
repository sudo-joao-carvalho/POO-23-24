//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraMENOR_QUE.h"
#include <sstream>

RegraMENOR_QUE::RegraMENOR_QUE(Sensor* sensor, const int &num1):Regra(sensor, num1, 0) {}

Regra* RegraMENOR_QUE::duplica() const {
    return new RegraMENOR_QUE(*this);
}

bool RegraMENOR_QUE::avaliaMedicoes() const {
    int leitura =  Regra::obtemSensor()->fazLeitura();

    if(leitura < Regra::getNum1())
        return true;
    else return false;
}

string RegraMENOR_QUE::getNome() const { return "Regra Menor Que"; }

string RegraMENOR_QUE::getRegraAsString() const {
    ostringstream oss;

    oss << Regra::getRegraAsString()
        << "Nome: " << getNome() << endl
        << "Id Sensor associado: " << obtemSensor()->getId() << endl;

    return oss.str();
}