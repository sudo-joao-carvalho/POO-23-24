//
// Created by João Carvalho on 21/10/2023.
//

#include "Zona.h"

int Zona::idZona = 0;

Zona::Zona(const int& posX, const int& posY) {
    idZona++;
    id = idZona;
    this->posX = posX;
    this->posY = posY;
}

Zona::~Zona(){

    for(auto & aparelho : aparelhos){
        delete aparelho;
    }

    for(auto & sensore : sensores){
        delete sensore;
    }

    cout << "Zona destruida" << endl;
}

/*Zona& Zona::operator=(const Zona* original) {

    //Prevenir auto-atribuicao
    if(this == original)
        return *this;

    // TODO quando existirem mais atributos na classe zona, deletar o que estiver em memoria dinamica e atribuir corretamente a nova zona

    return *this;
}*/

Aparelho* Zona::adicionaAparelho(const char& tipoDerivado) {

    if(tipoDerivado == 'a'){ //aquecedor
        aparelhos.push_back(new Aquecedor());
        return aparelhos.back();
    }

    if(tipoDerivado == 's'){ //aspersor
        aparelhos.push_back(new Aspersor());
        return aparelhos.back();
    }

    if(tipoDerivado == 'r'){ //refrigerador
        aparelhos.push_back(new Refrigerador());\
        return aparelhos.back();
    }


    if(tipoDerivado == 'l'){ //lampada
        aparelhos.push_back(new Lampada());
        return aparelhos.back();
    }

    return nullptr;
}

Sensor* Zona::adicionaSensor(const char& tipoDerivado) {

    if(tipoDerivado == 't'){ //temperatura
        sensores.push_back(new SensorTemperatura());
        return sensores.back();
    }

    if(tipoDerivado == 'v'){ //movimento
        sensores.push_back(new SensorMovimento());
        return sensores.back();
    }

    if(tipoDerivado == 'm'){ //luminosidade
        sensores.push_back(new SensorLuminosidade());
        return sensores.back();
    }

    if(tipoDerivado == 'd'){ //radiacao
        sensores.push_back(new SensorRadiacao());
        return sensores.back();
    }

    if(tipoDerivado == 'h'){ //humidade
        sensores.push_back(new SensorHumidade());
        return sensores.back();
    }

    if(tipoDerivado == 'o'){ //som
        sensores.push_back(new SensorSom());
        return sensores.back();
    }

    if(tipoDerivado == 'f'){ //fumo
        sensores.push_back(new SensorFumo());
        return sensores.back();
    }

    return nullptr;
}


//getters
int Zona::getId() const {return id;}

array<int, 2> Zona::getPosicao() const {return {this->posX, this->posY};}

/*vector<Equipamento*> Zona::getEquipamentos() const {return equipamentos;}*/

string Zona::zonaAsString() const {

    ostringstream oss;

    oss << endl << "Zona: " << id << endl
        << "Numero de Sensores: " << sensores.size() << endl
        << "Numero de Processadores: " << "0"/*processadores.size()*/ << endl
        << "Numero de Aparelhos: " << aparelhos.size() << endl << endl;

    return oss.str();
}

string Zona::getEquipamentosAsString() const {

    ostringstream oss;

    for(Aparelho* a: aparelhos){
        oss << "Zona: " << id << endl
            << "Tipo: a" << a->getEquipamentoAsString() << endl;
        break;
    }

    /*for(Processador* s: processadores){
        oss << "Zona: " << id << endl
            << "Tipo: p" << p->getEquipamentoAsString() << endl;
        break;
    }*/

    for(Sensor* s: sensores){
        oss << "Zona: " << id << endl
            << "Tipo: s" << s->getEquipamentoAsString() << endl;
        break;
    }

    return oss.str();

}