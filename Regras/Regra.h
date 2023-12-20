//
// Created by João Carvalho on 12/11/2023.
//

#ifndef POO_23_24_REGRA_H
#define POO_23_24_REGRA_H

#include "../Sensores/Sensor.h"

using namespace std;

class Regra {

public:
    Regra(Sensor& sensor);

    virtual ~Regra() = default;
    virtual bool avaliaMedicoes() const = 0;

    Sensor& obtemSensor() const;

    virtual string getRegraAsString() const;

    int getId() const;

private:
    Sensor& sensor;
    int id;
    static int idS;
};


#endif //POO_23_24_REGRA_H
