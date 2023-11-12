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
#include <map>
#include <cctype>
#include <algorithm>

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

#include "Processador.h"

 using namespace std;

class Zona {
private:
    static int idZona;
    int id;
    int posX;
    int posY;

    //TODO Propriedades

    vector<Aparelho*> aparelhos;
    vector<Processador*> processadores; //TODO
    vector<Sensor*> sensores;

    map<string, int> propriedades;

public:

    Zona() = default;
    Zona(const int& posX, const int& posY);
    ~Zona();
    //Zona& operator=(const Zona* original);

    Aparelho* adicionaAparelho(const char& tipoDerivado);
    Sensor* adicionaSensor(const char& tipoDerivado);

    bool removeEquipamento(const char& tipoEquipamento, const int& idEquipamento);

    //tratamento de propriedades da zona
    void inserePropriedade(const string& key, const int& value);
    int obtemValorPropriedade(const string& key);
    bool alteraPropriedade(const string& key, const int& value);

    //getters
    int getId() const;
    array<int, 2> getPosicao() const;
    vector<Aparelho*> getAparelhos() const;
    vector<Sensor*> getSensores() const;

    //vector<Equipamento*> getEquipamentos() const;

    string zonaAsString() const;
    string getEquipamentosAsString() const;
    string listaPropriedades() const;
};


#endif //POO_23_24_ZONA_H
