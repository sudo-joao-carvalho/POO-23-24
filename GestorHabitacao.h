//
// Created by João Carvalho on 07/12/2023.
//

#ifndef POO_23_24_GESTORHABITACAO_H
#define POO_23_24_GESTORHABITACAO_H

#include "Habitacao.h"

using namespace std;

class GestorHabitacao {
public:
    GestorHabitacao();
    ~GestorHabitacao();

    void criaHabitacao(const int& nLinhas, const int& nColunas);
    void destroiHabitacao();

    //getters & setters
    Habitacao* getHabitacao() const;
    int getTempoDaHabitacao() const;
private:
    Habitacao* habitacao;
};


#endif //POO_23_24_GESTORHABITACAO_H
