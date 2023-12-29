//
// Created by João Carvalho on 22/10/2023.
//

#include "Aquecedor.h"
#include "../Zona.h"
#include <sstream>

Aquecedor::Aquecedor(/*Zona* zona*/): /*Aparelho(zona),*/ isLigado(false), contador(0) {
}

//getters
string Aquecedor::getNome() const {
    if(isLigado)
        return "A" + to_string(getId());

    return "a" + to_string(getId());
}

char Aquecedor::getAbreviacao() const {return 'a';}

string Aquecedor::getAparelhoAsString() const {

    ostringstream oss;

    string estado = isLigado ? "ligado" : "desligado";

    oss << Aparelho::getAparelhoAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl
        << "Estado: " << estado << endl;

    return oss.str();

}

bool Aquecedor::liga(Zona* zona) {
    isLigado = true;
    /*
     * Adiciona um grau celsius à temperatura da zona por cada 3 instantes até ao máximo de 50 graus
     */
    ++contador;
    if(contador % 3 == 0){
        if(zona->obtemValorPropriedade("Temperatura") < 50)
            zona->alteraPropriedade("temperatura", 1, '+');
    }

    /*
     * Adiciona 5db de ruido uma unica vez -> altera a propriedade som
     */
    if(contador == 1)
        zona->alteraPropriedade("som", 5, '+');

    return isLigado;
}

bool Aquecedor::desliga(Zona* zona) {
    isLigado = false;

    /*
     * Remove 5 db de ruído no primeiro instante
     */

    if(zona->obtemValorPropriedade("Som") >= 5){ //so vai permitir remover o som se for >= 5 para nao passar do minimo de som
        if(contador != 0)
            zona->alteraPropriedade("som", 5, '-');

        contador = 0;
    }

    return isLigado;
}

//setters
/*void Aquecedor::setIsLigado(bool isLigado) {
    this->isLigado = isLigado;
}*/