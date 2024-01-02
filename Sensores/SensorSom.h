//
// Created by henri on 24/10/2023.
//

#ifndef POO_23_24_SENSORSOM_H
#define POO_23_24_SENSORSOM_H


#include "Sensor.h"

using namespace std;

class SensorSom: public Sensor {

private:

public:
    SensorSom(Zona* zona);
    ~SensorSom() = default;

    string getNome() const override;
    char getAbreviacao() const override;
    string getSensorAsString() const override;

    double fazLeitura() override;

};


#endif //POO_23_24_SENSORSOM_H
