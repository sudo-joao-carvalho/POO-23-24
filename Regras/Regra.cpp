//
// Created by João Carvalho on 12/11/2023.
//

#include "Regra.h"
Regra::Regra(Sensor &sensor, Operador operador, const int &num1, const int &num2):sensor(sensor), operador(operador), num1(num1), num2(num2) {}

bool Regra::avaliaMedicoes() const {

    int leitura = sensor.fazLeitura(); //TODO fazer funcao no sensor que faz leitura de propriedades

    switch (operador) {
        case IGUAL_A:
            return leitura == num1;
        case MENOR_QUE:
            return leitura < num1;
        case MAIOR_QUE:
            return leitura > num1;
        case ENTRE:
            return num1 < leitura < num2;
        case FORA:
            return leitura < num1 || leitura > num2;
        default:
            return false;
    }
}