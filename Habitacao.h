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
    int tempo;
    int maxLinha, maxColuna;
    vector<Zona*> zonas;

    map<string, Processador*> gravacoesProcessadores;
public:
    Habitacao(const int& nLinhas, const int& nColunas);
    ~Habitacao();

    void avancaTempo();

    void adicionaZona(const int& linha, const int& coluna);
    bool removeZonaById(const int& id);

    int adicionaAparelhoAZona(const int& idZona, const char& tipoEquipamento);
    int adicionaSensorAZona(const int& idZona, const char& tipoEquipamento);
    int adicionaProcessadorAZona(const int& idZona, const string& comando);
    bool associaProcessadorDaZonaAparelho(const int& idZona, const int& idProcRegras, const int& idAparelho);
    bool desassociaProcessadorDaZonaAparelho(const int& idZona, const int& idProcRegras, const int& idAparelho);
    bool verificaSeGravacaoExiste(const string& nome);
    bool salvaProcessadorDaZona(const int& idZona, const int& idProcRegra, const string& nome);
    bool repoeProcessadorNaZona(const string& nome);
    bool removeGravacaoProcessador(const string& nome);

    string listaGravacoes() const;

    bool mudaComandoAparelhoNaZona(const int& idZona, const int& idAparelho, const string& comando);

    bool removeEquipamentoByID(const int& idZona, const char& tipoEquipamento, const int& idEquipamento);

    int mudaComandoProcessadorNaZona(const int& idZona, const int& idProcRegra, const string& novoComando);
    bool removeRegraDoProcessadorDaZona(const int& idZona, const int& idProcRegra, const int& idRegra);
    int criaNovaRegraNoProcessadorDaZona(const int& idZona , const int& idProcRegra, const string& tipoRegra, const int& idSensor, vector<double> params);

    //propriedades
    bool alteraPropriedade(const int& idZona, const string& key, const double& value, const char& operacao);

    //getters
    int getTempo() const;
    int getMaxLinha() const;
    int getMaxColuna() const;
    vector <Zona*> getZonas();
    Zona* getZonaByPosicao(const int& posX, const int& posY) const;
    Zona* getZonaById(const int& idZona) const;
    string listaZonas() const;
    string listaEquipamentoZona(const int& id) const;
    string listaPropriedadesZona(const int& id) const;
    string listaRegrasNoProcessador(const int& idZona, const int& idProcRegras) const;
};


#endif //POO_23_24_HABITACAO_H
