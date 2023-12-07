//
// Created by João Carvalho on 07/12/2023.
//

#include "GestorHabitacao.h"

GestorHabitacao::GestorHabitacao():habitacao(nullptr) {}

//getters & setters
Habitacao* GestorHabitacao::getHabitacao() const {return this->habitacao;}

void GestorHabitacao::criaHabitacao(const int& nLinhas, const int& nColunas) {
    this->habitacao = new Habitacao(nLinhas, nColunas);
}

void GestorHabitacao::destroiHabitacao(){
    delete habitacao;
    this->habitacao = nullptr;
}