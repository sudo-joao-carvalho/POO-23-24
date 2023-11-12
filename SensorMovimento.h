//
// Created by henri on 24/10/2023.
//

#ifndef POO_23_24_SENSORMOVIMENTO_H
#define POO_23_24_SENSORMOVIMENTO_H


#include "Sensor.h"

using namespace std;

class SensorMovimento: public Sensor {

private:
    string nome;
    char letra;


public:
    SensorMovimento();
    string getNome() const override;
    char getAbreviacao() const override;
    //Tipo getTipo() const override;
    int fazLeitura() const override;

};


#endif //POO_23_24_SENSORMOVIMENTO_H
