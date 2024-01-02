//
// Created by João Carvalho on 21/10/2023.
//

#include "Aparelho.h"
#include "../Zona.h"
#include <sstream>

int Aparelho::idAparelho = 0;

Aparelho::Aparelho():id(++idAparelho), ultimoComandoRecebido(""){
}

Aparelho::~Aparelho() {
}

int Aparelho::getId() const {return id;}

string Aparelho::getUltimoComandoRecebido() const { return ultimoComandoRecebido; }

string Aparelho::getAparelhoAsString() const {

    ostringstream oss;

    oss << endl << "ID: " << id << endl
        << "Ultimo Comando Recebido: " << ultimoComandoRecebido << endl;

    return oss.str();
}

void Aparelho::setUltimoComandoRecebido(const string& comando, Zona* zona){
    ultimoComandoRecebido = comando;
    if(ultimoComandoRecebido == "liga"){
        liga(zona);
    }else if(ultimoComandoRecebido == "desliga"){
        desliga(zona);
    }
}