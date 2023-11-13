//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraMAIOR_QUE.h"

RegraMAIOR_QUE::RegraMAIOR_QUE(Sensor &sensor, const int &num1, const int &num2):sensor(sensor), num1(num1), num2(num2) {}

bool RegraMAIOR_QUE::avaliaMedicoes() const {
    int leitura = sensor.fazLeitura();

    if(leitura > num1)
        return true;
    else return false;
}