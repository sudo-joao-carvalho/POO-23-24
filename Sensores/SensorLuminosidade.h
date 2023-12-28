//
// Created by henri on 24/10/2023.
//

#ifndef POO_23_24_SENSORLUMINOSIDADE_H
#define POO_23_24_SENSORLUMINOSIDADE_H



#include "Sensor.h"

using namespace std;

class SensorLuminosidade: public Sensor {

private:

public:
    SensorLuminosidade(Zona* zona);
    ~SensorLuminosidade() = default;

    string getNome() const override;
    char getAbreviacao() const override;
    string getSensorAsString() const override;

    //Tipo getTipo() const override;
    int fazLeitura() override;

};



#endif //POO_23_24_SENSORLUMINOSIDADE_H
