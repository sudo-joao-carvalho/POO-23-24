//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraMENOR_QUE.h"
#include <sstream>

RegraMENOR_QUE::RegraMENOR_QUE(Sensor &sensor, const int &num1, const int &num2):Regra(sensor), num1(num1), num2(num2) {}

bool RegraMENOR_QUE::avaliaMedicoes() const {
    int leitura =  Regra::obtemSensor().fazLeitura();

    if(leitura < num1)
        return true;
    else return false;
}

string RegraMENOR_QUE::getNome() const { return "Regra Menor Que"; }

string RegraMENOR_QUE::getRegraAsString() const {
    ostringstream oss;

    oss << Regra::getRegraAsString()
        << "Nome: " << getNome() << endl
        << "Id Sensor associado: " << obtemSensor().getId() << endl;

    return oss.str();
}