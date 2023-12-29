//
// Created by henri on 24/10/2023.
//

#ifndef POO_23_24_SENSORRADIACAO_H
#define POO_23_24_SENSORRADIACAO_H




#include "Sensor.h"

using namespace std;

class SensorRadiacao: public Sensor {

private:

public:
    SensorRadiacao(Zona* zona);
    ~SensorRadiacao() = default;

    string getNome() const override;
    char getAbreviacao() const override;
    string getSensorAsString() const override;

    //Tipo getTipo() const override;
    double fazLeitura() override;

};



#endif //POO_23_24_SENSORRADIACAO_H
