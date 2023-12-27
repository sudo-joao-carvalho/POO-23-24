//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraMAIOR_QUE.h"
#include <sstream>

RegraMAIOR_QUE::RegraMAIOR_QUE(Sensor* sensor, const int &num1):Regra(sensor, num1, 0) {}

Regra* RegraMAIOR_QUE::duplica() const {
    return new RegraMAIOR_QUE(*this);
}

bool RegraMAIOR_QUE::avaliaMedicoes() const {
    int leitura =  obtemSensor()->fazLeitura();

    if(leitura > getNum1())
        return true;
    else return false;
}

string RegraMAIOR_QUE::getNome() const { return "Regra Maior Que"; }

string RegraMAIOR_QUE::getRegraAsString() const {
    ostringstream oss;

    oss << Regra::getRegraAsString()
        << "Nome: " << getNome() << endl
        << "Id Sensor associado: " << obtemSensor()->getId() << endl;

    return oss.str();
}