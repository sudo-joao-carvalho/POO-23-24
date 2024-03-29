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

#include "../Aparelhos/Aparelho.h"

using namespace std;

class Zona;

class Processador {

public:
    Processador(const string& comando, Zona* zona);
    Processador(const Processador& orig);
    ~Processador();
    Processador& operator=(const Processador& orig);

    void adicionaRegra(Regra* regra);
    bool eliminaRegra(const int& idRegra);

    int criaNovaRegra(const string &tipoRegra, Sensor* sensor, vector<double> params);

    void adicionaAparelhoAssociado(Aparelho* novoAparelhoAssociado);
    void removeAparelhoAssociado(Aparelho* aparelhoParaRemover);

    //getters & setters
    int getId() const;
    string getComandoOutput() const;

    void setComandoOutput(const string& newComandoOutput);
    string getRegrasAsString() const;

    string getProcessadorAsString() const;

    Zona* getZona() const;

    string getNome() const;

    vector<Aparelho*> getAparelhosAssociados();
    vector<Regra*> getRegras();

    void avaliaRegras();

private:
    static int idProcessador;
    int id;
    string nome;

    Zona* zona;

    string comandoOutput;
    vector<Regra*> regras; //composicao
    vector<Aparelho*> aparelhosAssociados; //agregação
};


#endif //POO_23_24_PROCESSADOR_H
