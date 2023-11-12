//
// Created by João Carvalho on 12/11/2023.
//

#ifndef POO_23_24_REGRA_H
#define POO_23_24_REGRA_H

#include "../Sensores/Sensor.h"
#include "../EOperador.h"

using namespace std;

class Regra {

public:
    Regra(Sensor& sensor, Operador operador, const int& num1, const int& num2 = 0);

    bool avaliaMedicoes() const;

private:
    Sensor& sensor;
    Operador operador;
    int num1;
    int num2;
};


#endif //POO_23_24_REGRA_H
