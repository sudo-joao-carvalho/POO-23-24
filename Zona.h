 //
// Created by João Carvalho on 21/10/2023.
//

#ifndef POO_23_24_ZONA_H
#define POO_23_24_ZONA_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

#include "Equipamento.h"

#include "Sensor.h"
#include "SensorTemperatura.h"
#include "SensorMovimento.h"
#include "SensorLuminosidade.h"
#include "SensorRadiacao.h"
#include "SensorHumidade.h"
#include "SensorSom.h"
#include "SensorFumo.h"

#include "Aparelho.h"
#include "Aquecedor.h"
#include "Aspersor.h"
#include "Refrigerador.h"
#include "Lampada.h"

 using namespace std;

class Zona {
private:
    static int idZona;
    int id;
    int posX;
    int posY;

    //vector<Equipamento*> equipamentos;

    //TODO Propriedades

    vector<Aparelho*> aparelhos;
    //vector<Processador*> processadore; //TODO
    vector<Sensor*> sensores;

public:

    Zona() = default;
    Zona(const int& posX, const int& posY);
    ~Zona();
    //Zona& operator=(const Zona* original);

    Aparelho* adicionaAparelho(const char& tipoDerivado);
    Sensor* adicionaSensor(const char& tipoDerivado);

    bool removeEquipamento(const char& tipoEquipamento, const int& idEquipamento);

    //getters
    int getId() const;
    array<int, 2> getPosicao() const;
    //vector<Equipamento*> getEquipamentos() const;

    string zonaAsString() const;
    string getEquipamentosAsString() const;
};


#endif //POO_23_24_ZONA_H
