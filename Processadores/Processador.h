//
// Created by João Carvalho on 12/11/2023.
//

#ifndef POO_23_24_PROCESSADOR_H
#define POO_23_24_PROCESSADOR_H

#include <string>
#include <vector>

#include "../Regras/Regra.h"
#include "../Regras/RegraIGUAL_A.h"
#include "../Regras/RegraENTRE.h"
#include "../Regras/RegraFORA.h"
#include "../Regras/RegraMAIOR_QUE.h"
#include "../Regras/RegraMENOR_QUE.h"

using namespace std;

class Processador {

public:
    Processador(const string& comando);
    ~Processador();

    void adicionaRegra(Regra* regra);
    bool eliminaRegra(const int& idRegra);

    //getters & setters
    int getId() const;
    string getComandoOutput() const;

    void setComandoOutput(const string& newComandoOutput);
    string getRegrasAsString() const;

    int criaNovaRegra(const string &tipoRegra, Sensor* sensor, vector<int> params);

private:
    static int idProcessador;
    int id;
    string comandoOutput;
    vector<Regra*> regras; //composicao

};


#endif //POO_23_24_PROCESSADOR_H
