//
// Created by João Carvalho on 13/11/2023.
//

#ifndef POO_23_24_REGRAMENOR_QUE_H
#define POO_23_24_REGRAMENOR_QUE_H


#include "Regra.h"

using namespace std;

class RegraMENOR_QUE: public Regra{

public:
    RegraMENOR_QUE(Sensor* sensor, const double &num1, const double &num2);

    Regra* duplica() const override;

    bool avaliaMedicoes() const override;

    string getNome() const;
    string getRegraAsString() const override;
private:
};


#endif //POO_23_24_REGRAMENOR_QUE_H
