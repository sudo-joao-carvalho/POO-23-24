//
// Created by João Carvalho on 12/11/2023.
//

//sensor ativa processador e o sensor sabe qual e o processador de regras sabe qual e o sensor
//fazer classes para cada propriedade

#include "Regra.h"
#include <sstream>

int Regra::idS = 0;

Regra::Regra(Sensor* sensor, const int& num1, const int& num2 = 0):sensor(sensor), id(idS++) {}

Sensor* Regra::obtemSensor() const {return sensor;}

string Regra::getRegraAsString() const {

    ostringstream oss;

    oss << "ID: " << id << endl;

    return oss.str();
}

int Regra::getId() const {
    return id;
}

int Regra::getNum1() const {
    return num1;
}

void Regra::setNum1(int num1) {
    Regra::num1 = num1;
}

int Regra::getNum2() const {
    return num2;
}

void Regra::setNum2(int num2) {
    Regra::num2 = num2;
}
