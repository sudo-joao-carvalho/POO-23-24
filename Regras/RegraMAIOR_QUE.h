//
// Created by João Carvalho on 13/11/2023.
//

#ifndef POO_23_24_REGRAMAIOR_QUE_H
#define POO_23_24_REGRAMAIOR_QUE_H

#include "Regra.h"

using namespace std;

class RegraMAIOR_QUE: public Regra{

public:
    RegraMAIOR_QUE(Sensor* sensor, const double &num1, const double &num2);

    Regra* duplica() const override;

    bool avaliaMedicoes() const override;

    string getNome() const;
    string getRegraAsString() const override;
private:
};


#endif //POO_23_24_REGRAMAIOR_QUE_H
