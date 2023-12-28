//
// Created by João Carvalho on 22/10/2023.
//

#include "Lampada.h"
#include "../Zona.h"
#include <sstream>

Lampada::Lampada(Zona* zona): Aparelho(zona), isLigado(false), contador(0) {
}

//getters
string Lampada::getNome() const {
    if(isLigado)
        return "L" + to_string(getId());
    return "l" + to_string(getId());
}

char Lampada::getAbreviacao() const {return 'l';}

string Lampada::getAparelhoAsString() const {

    ostringstream oss;

    oss << Aparelho::getAparelhoAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl
        << "Estado: " << isLigado << endl;

    return oss.str();
}

bool Lampada::liga() {
    isLigado = true;

    ++contador;

    /*
     * Adiciona 900 lumens no primeiro instante de ligado
     */
    if(contador == 1){
        getZona()->alteraPropriedade("Luz", 900, '+');
    }

    return isLigado;
}

bool Lampada::desliga() {
    isLigado = false;

/*
     * Remove 20 db de ruído no primeiro instante
     */
    if(contador != 0)
        getZona()->alteraPropriedade("luz", 900, '-');

    contador = 0;

    return isLigado;
}

//setters
/*void Lampada::setIsLigado(bool isLigado) {
    this->isLigado = isLigado;
}*/
