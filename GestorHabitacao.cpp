//
// Created by João Carvalho on 07/12/2023.
//

#include "GestorHabitacao.h"

GestorHabitacao::GestorHabitacao():habitacao(nullptr) {}
GestorHabitacao::~GestorHabitacao() {
    delete habitacao;
}

//getters & setters
Habitacao* GestorHabitacao::getHabitacao() const {return this->habitacao;}

void GestorHabitacao::criaHabitacao(const int& nLinhas, const int& nColunas) {
    this->habitacao = new Habitacao(nLinhas, nColunas);
}

void GestorHabitacao::destroiHabitacao(){
    if (habitacao != nullptr) {
        delete habitacao;
        habitacao = nullptr;
    }
}

int GestorHabitacao::getTempoDaHabitacao() const { return habitacao->getTempo(); }