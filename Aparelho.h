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

    virtual string getNome() const = 0;
    virtual char getAbreviacao() const = 0;
    virtual bool liga() = 0;
    virtual bool desliga() = 0;
    int getIdAparelho() const;

private:
    static int idAparelho;


};


#endif //POO_23_24_APARELHO_H
