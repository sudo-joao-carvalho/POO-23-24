//
// Created by henri on 24/10/2023.
//

#ifndef POO_23_24_SENSORTEMPERATURA_H
#define POO_23_24_SENSORTEMPERATURA_H

#include "Sensor.h"

using namespace std;

class SensorTemperatura: public Sensor {

private:

public:
    SensorTemperatura(Zona* zona);
    ~SensorTemperatura() = default;

    string getNome() const override;
    char getAbreviacao() const override;
    string getSensorAsString() const override;

    double fazLeitura() override;

};


#endif //POO_23_24_SENSORTEMPERATURA_H
