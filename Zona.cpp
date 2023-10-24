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

    for(int i = 0; i < equipamentos.size(); i++){
        delete equipamentos[i];
    }

}

/*Zona& Zona::operator=(const Zona* original) {

    //Prevenir auto-atribuicao
    if(this == original)
        return *this;

    // TODO quando existirem mais atributos na classe zona, deletar o que estiver em memoria dinamica e atribuir corretamente a nova zona

    return *this;
}*/

void Zona::adicionaEquipamento(Equipamento* novoEquipamento) {
    equipamentos.push_back(novoEquipamento);
}


//getters
int Zona::getId() const {return id;}

array<int, 2> Zona::getPosicao() const {return {this->posX, this->posY};}

vector<Equipamento*> Zona::getEquipamentos() const {return equipamentos;}

string Zona::zonaAsString() const {

    int numSensores = 0;
    int numProcessadores = 0;
    int numAparelhos = 0;

    for(Equipamento* equip: equipamentos){
        switch (equip->getTipo()) {
            case Equipamento::TIPO_SENSOR:
                numSensores++;
                break;
            case Equipamento::TIPO_PROCESSADOR:
                numProcessadores++;
                break;
            case Equipamento::TIPO_APARELHO:
                numAparelhos++;
                break;
            default:
                break;
        }
    }

    ostringstream oss;

    oss << endl << "Zona: " << id << endl
        << "Numero de Sensores: " << numSensores << endl
        << "Numero de Processadores: " << numProcessadores << endl
        << "Numero de Aparelhos: " << numAparelhos << endl << endl;

    return oss.str();
}