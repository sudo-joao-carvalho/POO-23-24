//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraFORA.h"

RegraFORA::RegraFORA(Sensor &sensor, const int &num1, const int &num2):sensor(sensor), num1(num1), num2(num2) {}

bool RegraFORA::avaliaMedicoes() const {
    int leitura = sensor.fazLeitura();

    if(leitura < num1 && leitura > num2)
        return true;
    else return false;
}