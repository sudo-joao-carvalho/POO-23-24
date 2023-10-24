//
// Created by henri on 24/10/2023.
//

#ifndef POO_23_24_SENSORRADIACAO_H
#define POO_23_24_SENSORRADIACAO_H




#include "Sensor.h"

using namespace std;

class SensorRadiacao: public Sensor {

private:
    string nome;
    char letra;


public:
    SensorRadiacao();
    string getNome() const override;
    char getAbreviacao() const override;
    Tipo getTipo() const override;

};



#endif //POO_23_24_SENSORRADIACAO_H
