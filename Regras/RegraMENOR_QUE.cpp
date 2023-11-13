//
// Created by João Carvalho on 13/11/2023.
//

#include "RegraMENOR_QUE.h"

RegraMENOR_QUE::RegraMENOR_QUE(Sensor &sensor, const int &num1, const int &num2):sensor(sensor), num1(num1), num2(num2) {}

bool RegraMENOR_QUE::avaliaMedicoes() const {
    int leitura = sensor.fazLeitura();

    if(leitura < num1)
        return true;
    else return false;
}