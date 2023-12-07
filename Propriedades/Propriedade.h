//
// Created by João Carvalho on 07/12/2023.
//

#ifndef POO_23_24_PROPRIEDADE_H
#define POO_23_24_PROPRIEDADE_H

#include <string>

using namespace std;

class Propriedade {
public:
    Propriedade() = default;
    virtual ~Propriedade() = default;

    virtual string getNome() const = 0;
    virtual string getUnidade() const = 0;
    virtual float getValorMinimo() const = 0;
    virtual float getValorMaximo() const = 0;
private:
};


#endif //POO_23_24_PROPRIEDADE_H
