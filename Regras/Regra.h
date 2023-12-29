//
// Created by João Carvalho on 12/11/2023.
//

#ifndef POO_23_24_REGRA_H
#define POO_23_24_REGRA_H

#include "../Sensores/Sensor.h"

using namespace std;

class Regra {

public:
    Regra(Sensor* sensor, const double& num1, const double& num2);
    virtual ~Regra() = default;

    virtual Regra* duplica() const = 0;

    virtual bool avaliaMedicoes() const = 0;

    Sensor* obtemSensor() const;
    virtual string getRegraAsString() const;
    int getId() const;
    double getNum1() const;
    void setNum1(const double& num1);
    double getNum2() const;
    void setNum2(const double& num2);

private:
    Sensor* sensor;
    double num1;
    double num2;

    int id;
    static int idS;
};


#endif //POO_23_24_REGRA_H
