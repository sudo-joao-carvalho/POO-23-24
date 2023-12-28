//
// Created by João Carvalho on 22/10/2023.
//

#include "Refrigerador.h"
#include "../Zona.h"
#include <sstream>

Refrigerador::Refrigerador(Zona* zona): Aparelho(zona), isLigado(false), contador(0) {
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

    oss << Aparelho::getAparelhoAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl
        << "Estado: " << isLigado << endl;

    return oss.str();
}

bool Refrigerador::liga() {
    isLigado = true;

    ++contador;

    /*
     * Remove um grau celsius à temperatura da zona a cada 3 instantes ligado
     */
    if(contador % 3 == 0){
        getZona()->alteraPropriedade("Temperatura", 1, '-');
    }

    /*
     * Adiciona 20 db de ruído no primeiro instante de ligado
     */
    if(contador == 1){
        getZona()->alteraPropriedade("Som", 20, '+');
    }

    return isLigado;
}

bool Refrigerador::desliga() {
    isLigado = false;

    /*
     * Remove 20 db de ruído no primeiro instante
     */
    if(contador != 0)
        getZona()->alteraPropriedade("som", 20, '-');

    contador = 0;

    return isLigado;
}

//setters
/*void Refrigerador::setIsLigado(bool isLigado) {
    this->isLigado = isLigado;
}*/
