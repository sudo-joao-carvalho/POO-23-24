//
// Created by João Carvalho on 22/10/2023.
//

#ifndef POO_23_24_LAMPADA_H
#define POO_23_24_LAMPADA_H

#include "Aparelho.h"
#include <string>

using namespace std;

class Zona;

class Lampada: public Aparelho {

private:
    bool isLigado;
    int contador;

public:
    Lampada();
    ~Lampada() = default;

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


#endif //POO_23_24_LAMPADA_H
