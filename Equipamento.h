//
// Created by João Carvalho on 24/10/2023.
//

#ifndef POO_23_24_EQUIPAMENTO_H
#define POO_23_24_EQUIPAMENTO_H


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

};


#endif //POO_23_24_EQUIPAMENTO_H
