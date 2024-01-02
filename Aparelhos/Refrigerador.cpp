//
// Created by João Carvalho on 22/10/2023.
//

#include "Refrigerador.h"
#include "../Zona.h"
#include <sstream>

Refrigerador::Refrigerador():isLigado(false), contador(0) {
}

//getters
string Refrigerador::getNome() const {
    if(isLigado)
        return "R" + to_string(getId());

    return "r" + to_string(getId());
}

char Refrigerador::getAbreviacao() const {return 'r';}

string Refrigerador::getAparelhoAsString() const {

    ostringstream oss;

    string estado = isLigado ? "ligado" : "desligado";

    oss << Aparelho::getAparelhoAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl
        << "Estado: " << estado << endl;

    return oss.str();
}

bool Refrigerador::liga(Zona* zona) {
    isLigado = true;

    ++contador;

    /*
     * Remove um grau celsius à temperatura da zona a cada 3 instantes ligado
     */
    if(contador % 3 == 0){
        double valorAntigo = zona->obtemValorPropriedade("Temperatura");
        zona->alteraPropriedade("temperatura", 1, '-');

        double novoValor = zona->obtemValorPropriedade("Temperatura");
        if(novoValor < -273.0){
            zona->alteraPropriedade("temperatura", valorAntigo, 'n');
        }
    }

    /*
     * Adiciona 20 db de ruído no primeiro instante de ligado
     */
    if(contador == 1){
        zona->alteraPropriedade("som", 20, '+');
    }

    return isLigado;
}

bool Refrigerador::desliga(Zona* zona) {
    isLigado = false;

    /*
     * Remove 20 db de ruído no primeiro instante
     */
    if(contador != 0){
        double valorAntigo = zona->obtemValorPropriedade("Som");
        zona->alteraPropriedade("som", 20, '-');

        double novoValor = zona->obtemValorPropriedade("Som");
        if(novoValor < 0){
            zona->alteraPropriedade("som", valorAntigo, 'n');
        }
    }


    contador = 0;

    return isLigado;
}

//setters
/*void Refrigerador::setIsLigado(bool isLigado) {
    this->isLigado = isLigado;
}*/
