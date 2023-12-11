//
// Created by João Carvalho on 13/11/2023.
//

#ifndef POO_23_24_REGRAIGUAL_A_H
#define POO_23_24_REGRAIGUAL_A_H

#include "Regra.h"

using namespace std;

class RegraIGUAL_A: public Regra{

public:
    RegraIGUAL_A(Sensor& sensor, const int &num1, const int &num2 = 0);

    bool avaliaMedicoes() const override;

    string getNome() const;
private:
    //Sensor& sensor;
    int num1;
    int num2;
};


#endif //POO_23_24_REGRAIGUAL_A_H
