//
// Created by João Carvalho on 07/12/2023.
//

#ifndef POO_23_24_TEMPERATURA_H
#define POO_23_24_TEMPERATURA_H

#include "Propriedade.h"

using namespace std;

class Temperatura: public Propriedade {
public:
    Temperatura() = default;

    string getNome() const override;
    string getUnidade() const override;
    float getValorMinimo() const override;
    float getValorMaximo() const override;
private:
};


#endif //POO_23_24_TEMPERATURA_H
