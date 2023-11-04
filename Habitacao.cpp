//
// Created by João Carvalho on 21/10/2023.
//

#include "Habitacao.h"

Habitacao::Habitacao(int nLinhas, int nColunas): maxLinha(nLinhas), maxColuna(nColunas) {
}

Habitacao::~Habitacao(){

    for(auto & zona : zonas)
        delete zona;

    cout << "Habitacao destruida" << endl;
}

void Habitacao::adicionaZona(const int& linha, const int& coluna) {
    Zona* aux = new Zona(coluna, linha);
    zonas.push_back(aux);
}

bool Habitacao::removeZonaById(const int &id) {

    /*for (auto it = zonas.begin(); it != zonas.end(); ++it) {
        if ((*it)->getId() == id) {
            //delete *it;
            zonas.erase(it);
            return true;
        }
    }*/

    for(auto it = zonas.begin(); it != zonas.end();){
        if ((*it)->getId() == id) {
            delete *it; // Liberta a memória alocada
            it = zonas.erase(it); // Remove o elemento do vetor
            return true;
        } else {
            ++it; // Avanca para o próximo elemento
        }
    }

    return false;
}


int Habitacao::adicionaAparelhoAZona(const int &idZona, const char& tipoEquipamento) {

    for(Zona* zona: zonas){
        if(zona->getId() == idZona){

            //aparelho
            if(tipoEquipamento == 'a'){ //aquecedor
                return zona->adicionaAparelho(tipoEquipamento)->getId();
            }

            if(tipoEquipamento == 's'){ //aspersor
                return zona->adicionaAparelho(tipoEquipamento)->getId();
            }

            if(tipoEquipamento == 'r'){ //refrigerador
                return zona->adicionaAparelho(tipoEquipamento)->getId();
            }

            if(tipoEquipamento == 'l'){ //lampada
                return zona->adicionaAparelho(tipoEquipamento)->getId();
            }

        }
    }

    return -1;
}

int Habitacao::adicionaSensorAZona(const int &idZona, const char &tipoEquipamento) {

    for(Zona* zona: zonas) {
        if (zona->getId() == idZona) {
            //sensor
            if (tipoEquipamento == 't') { //temperatura
                return zona->adicionaSensor(tipoEquipamento)->getId();
            }

            if (tipoEquipamento == 'v') { //movimento
                return zona->adicionaSensor(tipoEquipamento)->getId();
            }

            if (tipoEquipamento == 'm') { //luminosidade
                return zona->adicionaSensor(tipoEquipamento)->getId();
            }

            if (tipoEquipamento == 'd') { //radiacao
                return zona->adicionaSensor(tipoEquipamento)->getId();
            }

            if (tipoEquipamento == 'h') { //humidade
                return zona->adicionaSensor(tipoEquipamento)->getId();
            }

            if (tipoEquipamento == 'o') { //som
                return zona->adicionaSensor(tipoEquipamento)->getId();
            }

            if (tipoEquipamento == 'f') { //fumo
                return zona->adicionaSensor(tipoEquipamento)->getId();
            }
        }
    }

    return -1;

}

bool Habitacao::removeEquipamentoByID(const int& idZona, const char& tipoEquipamento, const int& idEquipamento){ //Modificar aqui para dar return do objeto eliminado

    for(Zona* zona: zonas){
        if(zona->getId() == idZona){
            if(zona->removeEquipamento(tipoEquipamento, idEquipamento))
                return true;
            else return false;
        }
    }

    return false;
}

//TODO fazer quando a classe processador estiver construida
//Processador* Habitacao::adicionaProcessadorAZona(const int &idZona, const char &abreviaturaEquipamento, const string& comandoProcessador) {

    //processador
    /*if(abreviaturaEquipamento == 'p'){
        if(tipoEquipamento == 't') //temperatura
            return;
        //zona->adicionaEquipamento(new SensorTemperatura());

        if(tipoEquipamento == 'v') //movimento
            return;
        //zona->adicionaEquipamento(new SensorMovimento());

        if(tipoEquipamento == 'm') //luminosidade
            return;
        //zona->adicionaEquipamento(new SensorLuminosidade());

        if(tipoEquipamento == 'd') //radiacao
            return;
        //zona->adicionaEquipamento(new SensorRadiacao());

        if(tipoEquipamento == 'h') //humidade
            return;
        //zona->adicionaEquipamento(new SensorHumidade());

        if(tipoEquipamento == 'o') //som
            return;
        //zona->adicionaEquipamento(new SensorSom());

        if(tipoEquipamento == 'f') //fumo
            return;
        //zona->adicionaEquipamento(new SensorFumo());

    }*/

    //return nullptr;
//}

//getters
int Habitacao::getMaxLinha() const {return maxLinha;}

int Habitacao::getMaxColuna() const {return maxColuna;}

vector<Zona*> Habitacao::getZonas(){
    return zonas;
}

Zona* Habitacao::getZonaByPosicao(const int& posX, const int& posY) const{

    for(Zona* zona: zonas){
        if(zona->getPosicao()[0] - 1 == posX && zona->getPosicao()[1] - 1 == posY)
            return zona;
    }

    return nullptr;
}

string Habitacao::listaZonas() const {

    ostringstream oss;

    for(Zona* zona: zonas){
        oss << zona->zonaAsString();
    }

    return oss.str();
}

string Habitacao::listaEquipamentoZona(const int& id) const {

    ostringstream oss;

    for(Zona* zona: zonas){
        if(zona->getId() == id)
            oss << zona->getEquipamentosAsString();
    }

    return oss.str();
}