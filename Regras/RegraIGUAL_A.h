//
// Created by João Carvalho on 13/11/2023.
//

#ifndef POO_23_24_REGRAIGUAL_A_H
#define POO_23_24_REGRAIGUAL_A_H

#include "Regra.h"

using namespace std;

class RegraIGUAL_A: public Regra{

public:
    RegraIGUAL_A(Sensor* sensor, const int &num1);

    Regra* duplica() const override;

    bool avaliaMedicoes() const override;

    string getNome() const;
    string getRegraAsString() const override;
private:
};


#endif //POO_23_24_REGRAIGUAL_A_H
