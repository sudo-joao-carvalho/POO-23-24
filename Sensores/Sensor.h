//
// Created by João Carvalho on 24/10/2023.
//

#ifndef POO_23_24_SENSOR_H
#define POO_23_24_SENSOR_H

#include <string>
class Zona;

using namespace std;

class Sensor {

public:

    explicit Sensor(Zona* zona);
    virtual ~Sensor();

    virtual string getNome() const = 0;
    virtual char getAbreviacao() const = 0;
    int getId() const;

    virtual int fazLeitura() = 0;

    virtual string getSensorAsString() const;

    int getValorUltimaLeitura() const;
    void setValorUltimaLeitura(const int& leitura);

    Zona* getZonaAssociada();

private:
    static int idSensor;
    int id;

    Zona* zona;

    int valorUltimaLeitura;
};


#endif //POO_23_24_SENSOR_H
