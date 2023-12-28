//
// Created by João Carvalho on 22/10/2023.
//

#include "Aspersor.h"
#include "../Zona.h"
#include <sstream>

Aspersor::Aspersor(Zona* zona): Aparelho(zona), isLigado(false), contador(0) {
}

//getters
string Aspersor::getNome() const {
    if(isLigado)
        return "S" + to_string(getId());

    return "s" + to_string(getId());
}

char Aspersor::getAbreviacao() const {return 's';}

string Aspersor::getAparelhoAsString() const {

    ostringstream oss;

    oss << Aparelho::getAparelhoAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl
        << "Estado: " << isLigado << endl;

    return oss.str();

}

bool Aspersor::liga() {
    isLigado = true;

    ++contador;

    /*
     * No primeiro instante de ligado (ou seja, uma única vez por período em que está ligado):
     *
     * - Adiciona 50% de humidade relativa, até ao máximo de 75% de humidade.
     * - Adiciona vibração de 100 Hz.
     */
    if(contador == 1){
        getZona()->alteraPropriedade("vibracao", 100, '+');

        if(getZona()->obtemValorPropriedade("Humidade") < 75){
            getZona()->alteraPropriedade("humidade", 0.5 * getZona()->obtemValorPropriedade("Humidade"), '+');
        }

    }

    /*
     * Coloca o fumo a 0 uma única vez no segundo instante
     */
    if(contador == 2){
        getZona()->alteraPropriedade("fumo", 0, 'n');
    }

    return isLigado;
}

bool Aspersor::desliga() {
    isLigado = false;

    /*
     * Remove 100 Hz de vibração no primeiro instante
     */
    if(contador != 0)
        getZona()->alteraPropriedade("vibracao", 100, '-');

    contador = 0;

    return isLigado;
}

//setters
/*void Aspersor::setIsLigado(bool isLigado) {
    this->isLigado = isLigado;
}*/
