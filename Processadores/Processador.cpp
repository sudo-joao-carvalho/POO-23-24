//
// Created by João Carvalho on 12/11/2023.
//

#include "Processador.h"
#include <sstream>
#include <algorithm>

int Processador::idProcessador = 0;

Processador::Processador(const string& comando):comandoOutput(comando),id(++idProcessador) {}

Processador::~Processador() {
    for(Regra* regra: regras){
        delete regra;
    }
}

void Processador::adicionaRegra(Regra* regra) {
    regras.push_back(regra);
}

bool Processador::eliminaRegra(const int &idRegra) {
    //regras.erase(remove_if(regras.begin(), regras.end(), ))

    for(vector<Regra*>::iterator it = regras.begin(); it != regras.end();){
        if((*it)->getId() == idRegra){
            delete *it;
            regras.erase(it);
            return true;
        }else{
            ++it;
        }
    }
}

int Processador::getId() const {
    return id;
}

string Processador::getComandoOutput() const { return comandoOutput; }

void Processador::setComandoOutput(const string& newComandoOutput) { comandoOutput = newComandoOutput; }

string Processador::getRegrasAsString() const {

    ostringstream oss;

    if(regras.empty())
        return "Nao existem regras no processador";

    for(Regra* regra: regras){
        oss << regra->getRegraAsString() << endl;
    }

    return oss.str();
}