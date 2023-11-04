//
// Created by João Carvalho on 21/10/2023.
//

#ifndef POO_23_24_HABITACAO_H
#define POO_23_24_HABITACAO_H

#include "Zona.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Habitacao {
private:
    int maxLinha, maxColuna;// é preciso receber estes valores pelo comando
    vector<Zona*> zonas;

public:
    Habitacao(int nLinhas, int nColunas);
    ~Habitacao();

    void adicionaZona(const int& linha, const int& coluna);
    bool removeZonaById(const int& id);

    int adicionaAparelhoAZona(const int& idZona, const char& tipoEquipamento);
    int adicionaSensorAZona(const int& idZona, const char& tipoEquipamento);
    //overload para processador que recebe comando
    //Processador* adicionaProcessadorAZona(const int& idZona, const char& abreviaturaEquipamento, const string& comandoProcessador);

    bool removeEquipamentoByID(const int& idZona, const char& tipoEquipamento, const int& idEquipamento);

    //getters
    int getMaxLinha() const;
    int getMaxColuna() const;
    vector <Zona*> getZonas();
    Zona* getZonaByPosicao(const int& posX, const int& posY) const;
    string listaZonas() const;
    string listaEquipamentoZona(const int& id) const;
};


#endif //POO_23_24_HABITACAO_H
