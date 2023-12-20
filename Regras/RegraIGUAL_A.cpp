//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraIGUAL_A.h"
#include <sstream>

RegraIGUAL_A::RegraIGUAL_A(Sensor* sensor, const int &num1):Regra(sensor, num1, 0) {}

bool RegraIGUAL_A::avaliaMedicoes() const {

    int leitura =  Regra::obtemSensor()->fazLeitura();

    if(leitura == Regra::getNum1())
        return true;
    else return false;
}

string RegraIGUAL_A::getNome() const { return "Regra Igual A"; }

string RegraIGUAL_A::getRegraAsString() const {
    ostringstream oss;

    oss << Regra::getRegraAsString()
        << "Nome: " << getNome() << endl
        << "Id Sensor associado: " << obtemSensor()->getId() << endl;

    return oss.str();
}