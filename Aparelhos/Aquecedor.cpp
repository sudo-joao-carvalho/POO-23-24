//
// Created by João Carvalho on 22/10/2023.
//

#include "Aquecedor.h"
#include "../Zona.h"
#include <sstream>

Aquecedor::Aquecedor(Zona* zona): Aparelho(zona), isLigado(false), contador(0) {
    isLigado    = false;
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

    oss << Aparelho::getAparelhoAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl
        << "Estado: " << isLigado << endl;

    return oss.str();

}

bool Aquecedor::liga() {
    isLigado = true;

    /*
     * Adiciona um grau celsius à temperatura da zona por cada 3 instantes até ao máximo de 50 graus
     */
    ++contador;
    if(contador % 3 == 0){
        if(getZona()->obtemValorPropriedade("Temperatura") < 50)
            getZona()->alteraPropriedade("temperatura", 1, '+');
    }

    /*
     * Adiciona 5db de ruido uma unica vez -> altera a propriedade som
     */
    if(contador == 1)
        getZona()->alteraPropriedade("som", 5, '+');

    return isLigado;
}

bool Aquecedor::desliga() {
    isLigado = false;

    /*
     * Remove 5 db de ruído no primeiro instante
     */

    if(contador != 0)
        getZona()->alteraPropriedade("som", 5, '-');

    contador = 0;

    return isLigado;
}

//setters
/*void Aquecedor::setIsLigado(bool isLigado) {
    this->isLigado = isLigado;
}*/