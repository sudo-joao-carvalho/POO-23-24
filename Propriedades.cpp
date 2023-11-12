//
// Created by João Carvalho on 21/10/2023.
//

#include "Propriedades.h"

Propriedades::Propriedades() {
    setupPropriedades();
}

void Propriedades::setupPropriedades() { //valores iniciais
    this->map_propriedades["Temperatura"] = 0;
    this->map_propriedades["Luz"] = 0;
    this->map_propriedades["Radicacao"] = 0;
    this->map_propriedades["Vibracao"] = 0;
    this->map_propriedades["Humidade"] = 0;
    this->map_propriedades["Fumo"] = 0;
    this->map_propriedades["Som"] = 0;
}

//void Propriedades::verificaMedicoes(){
//    //TODO funcao que verifica se os valores estao compreendidos entre o maximo e o minimo
//}
//
//int Propriedades::getMedicao(const string& key) const { //rever pois pode n ser preciso fazer assim a receber uma key pois os getters normalmente nao recebem parametros
//
//    for(/*map<string, int>::iterator*/auto it = map_propriedades.begin(); it != map_propriedades.end();){
//        if(it->first == key){
//            return it->second;
//        }else{
//            ++it;
//        }
//    }
//
//    return -274; //nao podia ser nenhum dos valores que compreendidos entre o maximo e o minimo das propriedades todas
//}
//
//void Propriedades::setMedicao(const string& key, const int& value) {
//    for(/*map<string, int>::iterator*/auto it = map_propriedades.begin(); it != map_propriedades.end();){
//        if(it->first == key){
//            it->second = value;
//        }else{
//            ++it;
//        }
//    }
//}