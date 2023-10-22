//
// Created by João Carvalho on 22/10/2023.
//

#ifndef POO_23_24_ASPERSOR_H
#define POO_23_24_ASPERSOR_H

#include "Aparelho.h"
#include <string>

using namespace std;

class Aspersor: public Aparelho {

private:
    string nome;
    char abreviacao;
    bool isLigado;

public:
    Aspersor();

    //getters
    string getNome() const override;
    char getAbreviacao() const override;

    //açoes
    bool liga() override;
    bool desliga() override;

    //setters
    //void setIsLigado(bool isLigado);
};


#endif //POO_23_24_ASPERSOR_H
