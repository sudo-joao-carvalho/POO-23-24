//
// Created by henri on 24/10/2023.
//

#include "SensorHumidade.h"


SensorHumidade::SensorHumidade()  {
    nome  = "Sensor Humidade";
    letra = 'h';

}

//getters
string SensorHumidade::getNome() const {return nome;}

char SensorHumidade::getAbreviacao() const {return letra;}

int SensorHumidade::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}