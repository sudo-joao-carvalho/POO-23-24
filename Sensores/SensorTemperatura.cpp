//
// Created by henri on 24/10/2023.
//

#include "SensorTemperatura.h"

SensorTemperatura::SensorTemperatura()  {
    nome  = "Sensor Temperatura";
    letra = 't';

}

//getters
string SensorTemperatura::getNome() const {return nome;}

char SensorTemperatura::getAbreviacao() const {return letra;}

int SensorTemperatura::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}