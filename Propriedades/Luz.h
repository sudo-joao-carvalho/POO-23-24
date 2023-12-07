//
// Created by João Carvalho on 07/12/2023.
//

#ifndef POO_23_24_LUZ_H
#define POO_23_24_LUZ_H

#include "Propriedade.h"
#include <string>

using namespace std;

class Luz: public Propriedade {
public:
    Luz() = default;

    string getNome() const override;
    string getUnidade() const override;
    float getValorMinimo() const override;
    float getValorMaximo() const override;
private:
};


#endif //POO_23_24_LUZ_H
