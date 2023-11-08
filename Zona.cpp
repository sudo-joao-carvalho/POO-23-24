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

    for(auto & sensor : sensores){
        delete sensor;
    }

    //idZona = 0;
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
        aparelhos.push_back(new Refrigerador());
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

bool Zona::removeEquipamento(const char &tipoEquipamento, const int &idEquipamento) {



    if(tipoEquipamento == 'a'){
        for(auto it = aparelhos.begin(); it != aparelhos.end();){
            if ((*it)->getId() == idEquipamento) {
                //da-se delete primeiro do que o erase pq se eu fizesse erase primeiro o erase devolve a posicao do proximo elemento entao se fizessemos delete depois iamos apagar o seguinte

                delete *it; // Liberta a memória alocada
                //it = aparelhos.erase(it); // Remove o elemento do vetor
                return true;
            } else {
                ++it; // Avanca para o próximo elemento
            }
        }
    }

    if(tipoEquipamento == 's'){
        for(auto it = sensores.begin(); it != sensores.end();){
            if ((*it)->getId() == idEquipamento) {
                delete *it; // Liberta a memória alocada
                //it = sensores.erase(it); // Remove o elemento do vetor
                return true;
            } else {
                ++it; // Avanca para o próximo elemento
            }
        }
    }

    if(tipoEquipamento == 'p'){

    }

    return false;
}


//getters
int Zona::getId() const {return id;}

array<int, 2> Zona::getPosicao() const {return {this->posX, this->posY};}

vector<Aparelho*> Zona::getAparelhos() const {
    return aparelhos;
}

vector<Sensor*> Zona::getSensores() const {
    return sensores;
}

/*vector<Equipamento*> Zona::getEquipamentos() const {return equipamentos;}*/

string Zona::zonaAsString() const {

    ostringstream oss;

    oss << endl << "Zona: " << id << endl
        << "Numero de Aparelhos: " << aparelhos.size() << endl
        << "Numero de Sensores: " << sensores.size() << endl
        << "Numero de Processadores: " << "0" << endl << endl;


    return oss.str();
}

string Zona::getEquipamentosAsString() const {

    ostringstream oss;

    oss << "Zona: " << id << endl;

    for(Aparelho* a: aparelhos){
        oss << "Tipo: a" << a->getEquipamentoAsString() << endl;
        break;
    }

    /*for(Processador* s: processadores){
        oss << "Zona: " << id << endl
            << "Tipo: p" << p->getEquipamentoAsString() << endl;
        break;
    }*/

    for(Sensor* s: sensores){
        oss << "Tipo: s" << s->getEquipamentoAsString() << endl;
        break;
    }

    return oss.str();

}