//
// Created by henri on 24/10/2023.
//

#include "SensorSom.h"

SensorSom::SensorSom()  {
    nome  = "Sensor Som";
    letra = 'o';

}

//getters
string SensorSom::getNome() const {return nome;}

char SensorSom::getAbreviacao() const {return letra;}

int SensorSom::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}