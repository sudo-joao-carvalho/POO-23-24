//
// Created by João Carvalho on 13/11/2023.
//

#ifndef POO_23_24_REGRAMAIOR_QUE_H
#define POO_23_24_REGRAMAIOR_QUE_H

#include "Regra.h"

using namespace std;

class RegraMAIOR_QUE: public Regra{

public:
    RegraMAIOR_QUE(Sensor& sensor, const int &num1, const int &num2 = 0);

    bool avaliaMedicoes() const override;

private:
    Sensor& sensor;
    int num1;
    int num2;
};


#endif //POO_23_24_REGRAMAIOR_QUE_H
