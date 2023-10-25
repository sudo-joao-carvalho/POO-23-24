//
// Created by henri on 24/10/2023.
//

#ifndef POO_23_24_SENSORFUMO_H
#define POO_23_24_SENSORFUMO_H


#include "Sensor.h"

using namespace std;

class SensorFumo: public Sensor {

private:
    string nome;
    char letra;


public:
    SensorFumo();
    string getNome() const override;
    char getAbreviacao() const override;
    //Tipo getTipo() const override;

};


#endif //POO_23_24_SENSORFUMO_H
