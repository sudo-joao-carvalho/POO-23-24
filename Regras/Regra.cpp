//
// Created by João Carvalho on 12/11/2023.
//

//sensor ativa processador e o sensor sabe qual e o processador de regras sabe qual e o sensor
//fazer classes para cada propriedade

#include "Regra.h"
#include <sstream>

int Regra::idS = 0;

Regra::Regra(Sensor* sensor, const double& num1, const double& num2):sensor(sensor), id(++idS), num1(num1), num2(num2) {}

Sensor* Regra::obtemSensor() const {return sensor;}

string Regra::getRegraAsString() const {

    ostringstream oss;

    oss << "ID: " << id << endl;

    return oss.str();
}

int Regra::getId() const {
    return id;
}

double Regra::getNum1() const {
    return num1;
}

void Regra::setNum1(const double& num1) {
    this->num1 = num1;
}

double Regra::getNum2() const {
    return num2;
}

void Regra::setNum2(const double& num2) {
    this->num2 = num2;
}
