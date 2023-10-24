//
// Created by João Carvalho on 21/10/2023.
//

#ifndef POO_23_24_APARELHO_H
#define POO_23_24_APARELHO_H

#include "Equipamento.h"
#include <string>

using namespace std;

class Aparelho: public Equipamento {

public:

    Aparelho();

    virtual string getNome() const = 0;
    virtual char getAbreviacao() const = 0;
    virtual bool liga() = 0; // TODO implementar em cada classe derivada
    virtual bool desliga() = 0; // TODO implementar em cada classe derivada
    int getId() const;

    Tipo getTipo() const override {
        return TIPO_APARELHO;
    }

private:
    static int idAparelho;
    int id;

};


#endif //POO_23_24_APARELHO_H
