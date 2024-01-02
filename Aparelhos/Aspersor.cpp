//
// Created by João Carvalho on 22/10/2023.
//

#include "Aspersor.h"
#include "../Zona.h"
#include <sstream>

Aspersor::Aspersor(): isLigado(false), contador(0) {
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

    string estado = isLigado ? "ligado" : "desligado";

    oss << Aparelho::getAparelhoAsString() << endl
        << "Nome: " << getNome() << endl
        << "Abreviatura: " << getAbreviacao() << endl
        << "Estado: " << estado << endl;

    return oss.str();

}

bool Aspersor::liga(Zona* zona) {
    isLigado = true;

    ++contador;

    /*
     * No primeiro instante de ligado (ou seja, uma única vez por período em que está ligado):
     *
     * - Adiciona 50% de humidade relativa, até ao máximo de 75% de humidade.
     * - Adiciona vibração de 100 Hz.
     */
    if(contador == 1){
        zona->alteraPropriedade("vibracao", 100, '+');

        double valorAntigo = zona->obtemValorPropriedade("Humidade");

        if(valorAntigo < 75){
            zona->alteraPropriedade("humidade", 0.5 * zona->obtemValorPropriedade("Humidade"), '+');

            double novoValor = zona->obtemValorPropriedade("Humidade");
            if(novoValor >= 100){ //verifica se vai ser possivel adicionar de modo a nao passar do limite superior
                zona->alteraPropriedade("humidade", valorAntigo, 'n'); //volta a meter o valor anterior na propriedade
            }
        }

    }

    /*
     * Coloca o fumo a 0 uma única vez no segundo instante
     */
    if(contador == 2){
        zona->alteraPropriedade("fumo", 0, 'n');
    }

    return isLigado;
}

bool Aspersor::desliga(Zona* zona) {
    isLigado = false;

    /*
     * Remove 100 Hz de vibração no primeiro instante
     */
    if(contador != 0)
        zona->alteraPropriedade("vibracao", 100, '-');

    contador = 0;

    return isLigado;
}

//setters
/*void Aspersor::setIsLigado(bool isLigado) {
    this->isLigado = isLigado;
}*/
