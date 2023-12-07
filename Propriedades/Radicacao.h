//
// Created by João Carvalho on 07/12/2023.
//

#ifndef POO_23_24_RADICACAO_H
#define POO_23_24_RADICACAO_H

#include "Propriedade.h"
#include <string>

using namespace std;

class Radiacao: public Propriedade {
public:
    Radiacao() = default;

    string getNome() const override;
    string getUnidade() const override;
    float getValorMinimo() const override;
    float getValorMaximo() const override;
private:
};


#endif //POO_23_24_RADICACAO_H
