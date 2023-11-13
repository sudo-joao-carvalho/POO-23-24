//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraIGUAL_A.h"

RegraIGUAL_A::RegraIGUAL_A(Sensor &sensor, const int &num1, const int &num2):sensor(sensor), num1(num1), num2(num2) {}

bool RegraIGUAL_A::avaliaMedicoes() const {

    int leitura = sensor.fazLeitura();

    if(leitura == num1)
        return true;
    else return false;
}