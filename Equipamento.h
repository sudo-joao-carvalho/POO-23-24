//
// Created by João Carvalho on 24/10/2023.
//

#ifndef POO_23_24_EQUIPAMENTO_H
#define POO_23_24_EQUIPAMENTO_H

#include <string>
#include <sstream>

using namespace std;

class Equipamento {

public:
    enum Tipo {
        TIPO_BASE,
        TIPO_SENSOR,
        TIPO_PROCESSADOR,
        TIPO_APARELHO
    };

    virtual Tipo getTipo() const {
        return TIPO_BASE;
    }

    virtual string getEquipamentoAsString() const = 0;

};


#endif //POO_23_24_EQUIPAMENTO_H
