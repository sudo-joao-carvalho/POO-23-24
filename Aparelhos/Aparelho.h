//
// Created by João Carvalho on 21/10/2023.
//

#ifndef POO_23_24_APARELHO_H
#define POO_23_24_APARELHO_H

#include <string>

using namespace std;

class Aparelho {

public:

    Aparelho();
    virtual ~Aparelho();

    virtual string getNome() const = 0;
    virtual char getAbreviacao() const = 0;
    virtual bool liga() = 0; // TODO implementar em cada classe derivada
    virtual bool desliga() = 0; // TODO implementar em cada classe derivada

    int getId() const;
    virtual string getAparelhoAsString() const;

private:
    static int idAparelho;
    int id;

};


#endif //POO_23_24_APARELHO_H
