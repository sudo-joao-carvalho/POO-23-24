//
// Created by João Carvalho on 21/10/2023.
//

#ifndef POO_23_24_HABITACAO_H
#define POO_23_24_HABITACAO_H

#include "Zona.h"
#include "Aquecedor.h"
#include "Aspersor.h"
#include "Refrigerador.h"
#include "Lampada.h"

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

    void criaHabitacao();
    void adicionaZona(Zona* novaZona);
    bool removeZonaById(const int& id);

    void adicionaEquipamentoAZona(const int& idZona, const char& abreviaturaEquipamento, const char& tipoEquipamento);

    //overload para processador que recebe comando
    void adicionaEquipamentoAZona(const int& idZona, const char& abreviaturaEquipamento, const string& comandoProcessador);

    //getters
    int getMaxLinha() const;
    int getMaxColuna() const;
    vector <Zona*> getZonas();
    string listaZonas() const;
    string listaEquipamentoZona(const int& id) const;
};


#endif //POO_23_24_HABITACAO_H
