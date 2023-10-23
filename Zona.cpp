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
    cout << "Zona " << id << " destruida" << endl;
}


//getters
int Zona::getId() const {return id;}

array<int, 2> Zona::getPosicao() const {return {this->posX, this->posY};}

string Zona::zonaAsString() const {

    ostringstream oss;

    oss << "Zona: " << id << endl;

    return oss.str();
}