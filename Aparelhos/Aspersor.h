//
// Created by João Carvalho on 22/10/2023.
//

#ifndef POO_23_24_ASPERSOR_H
#define POO_23_24_ASPERSOR_H

#include "Aparelho.h"
#include <string>

using namespace std;

class Zona;

class Aspersor: public Aparelho {

private:
    bool isLigado;
    int contador;

public:
    Aspersor(/*Zona* zona*/);
    ~Aspersor() = default;

    //getters
    string getNome() const override;
    char getAbreviacao() const override;
    string getAparelhoAsString() const override;

    //açoes
    bool liga(Zona* zona) override;
    bool desliga(Zona* zona) override;

    //setters
    //void setIsLigado(bool isLigado);
};


#endif //POO_23_24_ASPERSOR_H
