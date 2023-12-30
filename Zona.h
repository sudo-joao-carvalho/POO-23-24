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

#include "Sensores/Sensor.h"
#include "Sensores/SensorTemperatura.h"
#include "Sensores/SensorMovimento.h"
#include "Sensores/SensorLuminosidade.h"
#include "Sensores/SensorRadiacao.h"
#include "Sensores/SensorHumidade.h"
#include "Sensores/SensorSom.h"
#include "Sensores/SensorFumo.h"

#include "Aparelhos/Aparelho.h"
#include "Aparelhos/Aquecedor.h"
#include "Aparelhos/Aspersor.h"
#include "Aparelhos/Refrigerador.h"
#include "Aparelhos/Lampada.h"

#include "Processadores/Processador.h"

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

    map<string, double> propriedades;

public:

    Zona() = default;
    Zona(const int& posX, const int& posY);
    ~Zona();
    //Zona& operator=(const Zona* original);

    Aparelho* adicionaAparelho(const char& tipoDerivado);
    Sensor* adicionaSensor(const char& tipoDerivado);
    Processador* adicionaProcessador(const string& comando);
    Processador* adicionaProcessador(Processador* novo);

    bool removeEquipamento(const char& tipoEquipamento, const int& idEquipamento);
    bool associaProcessadorAparelho(const int& idProcRegras, const int& idAparelho);
    bool desassociaProcessadorAparelho(const int& idProcRegras, const int& idAparelho);

    bool mudaComandoAparelho(const int& idAparelho, const string& comando);

    //tratamento de propriedades da zona
    void inserePropriedade(const string& key, const int& value);
    double obtemValorPropriedade(const string& key);
    bool alteraPropriedade(const string& key, const double& value, const char& operacao);

    //getters
    int getId() const;
    array<int, 2> getPosicao() const;
    vector<Aparelho*> getAparelhos() const;
    vector<Sensor*> getSensores() const;
    vector<Processador*> getProcessadores() const;

    Processador* getProcessadorById(const int& idProcRegra) const;
    bool eliminaRegraDoProcessador(const int& idProcessador, const int& idRegra);

    string zonaAsString() const;
    string getEquipamentosAsString() const;
    string listaPropriedades() const;

    int
    criaNovaRegraNoProcessador(const int &idProcRegra, const string &tipoRegra, const int &idSensor,
                               vector<double> params);
};


#endif //POO_23_24_ZONA_H
