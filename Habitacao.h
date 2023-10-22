//
// Created by João Carvalho on 21/10/2023.
//

#ifndef POO_23_24_HABITACAO_H
#define POO_23_24_HABITACAO_H

#include "Zonas.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Habitacao {
private:
    int maxLinha, maxColuna;// é preciso receber estes valores pelo comando

public:
    Habitacao(int nLinhas, int nColunas);
    ~Habitacao();

    void criaHabitacao();


};


#endif //POO_23_24_HABITACAO_H
