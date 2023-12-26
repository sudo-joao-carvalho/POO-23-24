//
// Created by João Carvalho on 12/11/2023.
//

#ifndef POO_23_24_REGRA_H
#define POO_23_24_REGRA_H

#include "../Sensores/Sensor.h"

using namespace std;

class Regra {

public:
    Regra(Sensor* sensor, const int& num1, const int& num2);
    virtual ~Regra() = default;

    virtual Regra* duplica() const = 0;

    virtual bool avaliaMedicoes() const = 0;

    Sensor* obtemSensor() const;
    virtual string getRegraAsString() const;
    int getId() const;
    int getNum1() const;
    void setNum1(int num1);
    int getNum2() const;
    void setNum2(int num2);

private:
    Sensor* sensor;
    int num1;
    int num2;

    int id;
    static int idS;
};


#endif //POO_23_24_REGRA_H
