//
// Created by henri on 24/10/2023.
//

#ifndef POO_23_24_SENSORHUMIDADE_H
#define POO_23_24_SENSORHUMIDADE_H


#include "Sensor.h"

using namespace std;

class SensorHumidade: public Sensor {

private:

public:
    SensorHumidade() = default;

    string getNome() const override;
    char getAbreviacao() const override;
    string getSensorAsString() const override;

    //Tipo getTipo() const override;
    int fazLeitura() const override;

};


#endif //POO_23_24_SENSORHUMIDADE_H
