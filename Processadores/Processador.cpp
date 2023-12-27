//
// Created by João Carvalho on 12/11/2023.
//

#include "Processador.h"
#include <sstream>
#include <algorithm>

int Processador::idProcessador = 0;

Processador::Processador(const string& comando, const int& idZona):comandoOutput(comando), idZona(idZona), id(++idProcessador), nome("p" + to_string(id)) {}

Processador::Processador(const Processador &orig):comandoOutput(orig.comandoOutput), idZona(orig.idZona), id(orig.id), nome("p" + to_string(id))  {
    *this = orig;
}

Processador::~Processador() {
    for(Regra* regra: regras){
        delete regra;
    }
}

/*
 * Nesta funcao nao se adiciona os aparelhos e sensores associados porque estes estao por composicao e quando as copias sao feitas apenas o que pertence
 * ao processador de regras é associado ao novo Processador
 */
Processador& Processador::operator=(const Processador &orig) {

    //Prevencao de auto-atribuicao
    if(this == &orig){
        return *this;
    }

    //Faz uma copia de todas as regras que o processador tem e adiciona-as ao vetor de regras do novo processador
    for(Regra* r: orig.regras){
        Regra* regraDuplicada = r->duplica();
        this->regras.emplace_back(regraDuplicada);
    }

    return *this;
}

void Processador::adicionaRegra(Regra* regra) {
    regras.push_back(regra);
}

bool Processador::eliminaRegra(const int &idRegra) {

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

int Processador::criaNovaRegra(const string &tipoRegra, Sensor* sensor, vector<int> params) {

    Regra* novaRegra = nullptr;

    if(tipoRegra == "igual_a"){
         novaRegra = new RegraIGUAL_A(sensor, params[0]);
        regras.push_back(novaRegra);
        return novaRegra->getId();
    }
    if(tipoRegra == "maior_que"){
        novaRegra = new RegraMAIOR_QUE(sensor, params[0]);
        regras.push_back(novaRegra);
        return novaRegra->getId();
    }
    if(tipoRegra == "menor_que"){
        novaRegra = new RegraMENOR_QUE(sensor, params[0]);
        regras.push_back(novaRegra);
        return novaRegra->getId();
    }
    if(tipoRegra == "entre"){
        novaRegra = new RegraENTRE(sensor, params[0], params[1]);
        regras.push_back(novaRegra);
        return novaRegra->getId();
    }
    if(tipoRegra == "fora"){
        novaRegra = new RegraFORA(sensor, params[0], params[1]);
        regras.push_back(novaRegra);
        return novaRegra->getId();
    }

    return -1;
}

void Processador::adicionaAparelhoAssociado(Aparelho* novoAparelhoAssociado){
    aparelhosAssociados.push_back(novoAparelhoAssociado);
}

void Processador::removeAparelhoAssociado(Aparelho* aparelhoParaRemover){

    for(int i = 0; i < aparelhosAssociados.size(); i++){
        if(aparelhosAssociados[i] == aparelhoParaRemover){ //isto aqui retorna true se os aparelhos estao na mesma zona de memoria, logo nao é necessario redefinir o operador == para comparar se tem o mesmo id, ate pq podem ter o mesmo id mas serem de zonas diferentes
            aparelhosAssociados.erase(aparelhosAssociados.begin() + i);
            break;
        }
    }

}

string Processador::getProcessadorAsString() const {

    ostringstream oss;

    oss << "ID: " << id << endl
        << "ComandoOutput: " << comandoOutput << endl
        << "Numero Regras: " << regras.size() << endl;

    return oss.str();
}

int Processador::getIdZona() const {
    return idZona;
}

void Processador::setIdZona(const int& idZona) {
    this->idZona = idZona;
}

string Processador::getNome() const { return nome; }

vector<Aparelho*> Processador::getAparelhosAssociados(){return aparelhosAssociados;}
