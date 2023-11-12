//
// Created by henri on 24/10/2023.
//

#include "SensorRadiacao.h"


SensorRadiacao::SensorRadiacao()  {
    nome  = "Sensor Radiacao";
    letra = 'd';

}

//getters
string SensorRadiacao::getNome() const {return nome;}

char SensorRadiacao::getAbreviacao() const {return letra;}

int SensorRadiacao::fazLeitura() const {
    //TODO funcao para fazer a leitura de uma propriedade
    return 0; //retorna o valor da leitura
}