//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraFORA.h"
#include <sstream>

RegraFORA::RegraFORA(Sensor &sensor, const int &num1, const int &num2):Regra(sensor), num1(num1), num2(num2) {}

bool RegraFORA::avaliaMedicoes() const {
    int leitura =  Regra::obtemSensor().fazLeitura();

    if(leitura < num1 && leitura > num2)
        return true;
    else return false;
}

string RegraFORA::getNome() const { return "Regra Fora"; }

string RegraFORA::getRegraAsString() const {
    ostringstream oss;

    oss << Regra::getRegraAsString()
        << "Nome: " << getNome() << endl
        << "Id Sensor associado: " << obtemSensor().getId() << endl;

    return oss.str();
}