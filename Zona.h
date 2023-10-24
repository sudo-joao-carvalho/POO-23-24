 //
// Created by João Carvalho on 21/10/2023.
//

#ifndef POO_23_24_ZONA_H
#define POO_23_24_ZONA_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

#include "Equipamento.h"
 using namespace std;

class Zona {
private:
    static int idZona;
    int id;
    int posX;
    int posY;

    vector<Equipamento*> equipamentos;

public:

    Zona() = default;
    Zona(const int& posX, const int& posY);
    ~Zona();
    //Zona& operator=(const Zona* original);

    void adicionaEquipamento(Equipamento* novoEquipamento);

    //getters
    int getId() const;
    array<int, 2> getPosicao() const;
    vector<Equipamento*> getEquipamentos() const;

    string zonaAsString() const;
    string getEquipamentosAsString() const;
};


#endif //POO_23_24_ZONA_H
