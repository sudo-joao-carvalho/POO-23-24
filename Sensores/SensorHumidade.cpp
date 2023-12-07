//
// Created by henri on 24/10/2023.
//

#include "SensorHumidade.h"

//getters
string SensorHumidade::getNome() const {return "Sensor Humidade";}

char SensorHumidade::getAbreviacao() const {return 'h';}

int SensorHumidade::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}