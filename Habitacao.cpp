//
// Created by João Carvalho on 21/10/2023.
//

#include "Habitacao.h"

Habitacao::Habitacao(const int& nLinhas, const int& nColunas):maxLinha(nLinhas), maxColuna(nColunas) {
}

Habitacao::~Habitacao(){

    ///TODO Zona::idZona = 0; // é necessario dar reset a variavel static da zona pois quando é feito hrem a zona que é criada tem que ser a primeira novamente e naozontinua co o id anterior;

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

    for (Zona *zona : zonas) {
        if (zona->getId() == idZona) {
            Aparelho *novoAparelho = zona->adicionaAparelho(tipoEquipamento);
            if (novoAparelho != nullptr) {
                return novoAparelho->getId();
            } else {
                // Tratar o caso em que adicionaAparelho retorna nullptr
                return -1;
            }
        }
    }
    // Tratar o caso em que a zona não é encontrada
    return -1;
}

int Habitacao::adicionaSensorAZona(const int &idZona, const char &tipoEquipamento) {

    for (Zona *zona : zonas) {
        if (zona->getId() == idZona) {
            Sensor *novoSensor = zona->adicionaSensor(tipoEquipamento);
            if (novoSensor != nullptr) {
                return novoSensor->getId();
            } else {
                // Tratar o caso em que adicionaSensor retorna nullptr
                return -1;
            }
        }
    }
    // Tratar o caso em que a zona não é encontrada
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

/*Aparelho* Habitacao::getAparelho(const int& posX, const int& posY, const int &indiceAparelho) const {
    for(Zona* zona: zonas){
        if(zona->getPosicao()[0] - 1 == posX && zona->getPosicao()[1] - 1 == posY)
            return zona->getAparelhoAtIndex(indiceAparelho);
    }
}*/

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

string Habitacao::listaPropriedadesZona(const int &id) const {

    ostringstream oss;

    for(Zona* zona: zonas){
        if(zona->getId() == id)
            oss << zona->listaPropriedades();
    }

    return oss.str();
}