//
// Created by João Carvalho on 21/10/2023.
//

#include "Habitacao.h"
#include "Equipamento.h"

Habitacao::Habitacao(int nLinhas, int nColunas): maxLinha(nLinhas), maxColuna(nColunas) {
}

Habitacao::~Habitacao(){

    if(!zonas.empty())
        for(int i = 0; i < zonas.size(); i++)
            delete zonas[i];

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

    for (auto it = zonas.begin(); it != zonas.end(); ++it) {
        if ((*it)->getId() == id) {
            zonas.erase(it);
            return true;
        }
    }

    return false;
}


void Habitacao::adicionaEquipamentoAZona(const int &idZona, const char& abreviaturaEquipamento, const char& tipoEquipamento) {

    for(Zona* zona: zonas){
        if(zona->getId() == idZona){

            //sensor
            if(abreviaturaEquipamento == 's'){
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
            }

            //aparelho
            if(abreviaturaEquipamento == 'a'){

                if(tipoEquipamento == 'a') //aquecedor
                    zona->adicionaEquipamento(new Aquecedor());

                if(tipoEquipamento == 's') //aspersor
                    zona->adicionaEquipamento(new Aspersor());

                if(tipoEquipamento == 'r') //refrigerador
                    zona->adicionaEquipamento(new Refrigerador());

                if(tipoEquipamento == 'l') //lampada
                    zona->adicionaEquipamento(new Lampada());

            }
        }
    }
}

//TODO fazer quando a classe processador estiver construida
void Habitacao::adicionaEquipamentoAZona(const int &idZona, const char &abreviaturaEquipamento, const string& comandoProcessador) {

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
}

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

    //cout << "a";

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