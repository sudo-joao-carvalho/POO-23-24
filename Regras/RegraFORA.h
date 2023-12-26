//
// Created by João Carvalho on 13/11/2023.
//

#ifndef POO_23_24_REGRAFORA_H
#define POO_23_24_REGRAFORA_H


#include "Regra.h"

using namespace std;

class RegraFORA: public Regra{

public:
    RegraFORA(Sensor* sensor, const int &num1, const int &num2);

    Regra* duplica() const override;

    bool avaliaMedicoes() const override;

    string getNome() const;
    string getRegraAsString() const override;
private:
};


#endif //POO_23_24_REGRAFORA_H
