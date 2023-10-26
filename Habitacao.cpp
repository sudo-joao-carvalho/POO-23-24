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

void Habitacao::criaHabitacao(){

    // TODO nesta funcao fazer apenas a printagem do board (se tiver couts deve ser feita na interface)

    /*Zona * obj;
    vector<string>aux;

    for (int i = 0; i < maxLinha; i++)
    {
        vector<Zona*> temp;

        for (int j = 0; j < maxColuna; j++)
        {
            obj = new Zona();
            temp.push_back(obj);
        }
        //zonaH.push_back(temp); //zonas obviamente
    }*/


}

void Habitacao::adicionaZona(Zona* novaZona) {
    zonas.push_back(novaZona);
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
            delete *it; // Libere a memória alocada
            it = zonas.erase(it); // Remova o elemento do vetor
            return true;
        } else {
            ++it; // Avance para o próximo elemento
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


/*
   string auxzo, auxed, auxtr, auxcont;
    Zona *obj;
    srand(time(NULL));
    vector<string>aux;

    for (int i = 0; i < MaxLinhaCriar; i++)
    {
        vector<Zona> temp;
        for (int j = 0; j < MaxColunaCriar; j++)
        {
            obj = new Zona();
            temp.push_back(obj);
        }
        zonailha.push_back(temp);
    }


*/