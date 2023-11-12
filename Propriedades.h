//
// Created by João Carvalho on 21/10/2023.
//

#ifndef POO_23_24_PROPRIEDADES_H
#define POO_23_24_PROPRIEDADES_H

#include <string>
#include <map>

using namespace std;

class Propriedades {

public:
    Propriedades();

    void setupPropriedades();
    /*void verificaMedicoes();

    int getMedicao(const string& key) const;
    void setMedicao(const string& key, const int& value);*/

private:

    map<string, int> map_propriedades;

};


#endif //POO_23_24_PROPRIEDADES_H
