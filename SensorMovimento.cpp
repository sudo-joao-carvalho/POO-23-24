//
// Created by henri on 24/10/2023.
//

#include "SensorMovimento.h"


SensorMovimento::SensorMovimento()  {
    nome  = "Sensor Movimento";
    letra = 'v';

}

//getters
string SensorMovimento::getNome() const {return nome;}

char SensorMovimento::getAbreviacao() const {return letra;}

int SensorMovimento::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}