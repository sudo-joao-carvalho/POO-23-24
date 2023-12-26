//
// Created by João Carvalho on 21/10/2023.
//

#include "Zona.h"

int Zona::idZona = 0;

Zona::Zona(const int& posX, const int& posY):id(++idZona), posX(posX), posY(posY) {
    propriedades["Temperatura"] = 0;
    propriedades["Luz"] = 0;
    propriedades["Radiacao"] = 0;
    propriedades["Vibracao"] = 0;
    propriedades["Humidade"] = 0;
    propriedades["Fumo"] = 0;
    propriedades["Som"] = 0;
}

Zona::~Zona(){

    for(auto & aparelho : aparelhos){
        delete aparelho;
    }

    for(auto & sensor : sensores){
        delete sensor;
    }

    for(auto & processador : processadores){
        delete processador;
    }
    //idZona = 0;
}

/*Zona& Zona::operator=(const Zona* original) {

    //Prevenir auto-atribuicao
    if(this == original)
        return *this;

    // TODO quando existirem mais atributos na classe zona, deletar o que estiver em memoria dinamica e atribuir corretamente a nova zona

    return *this;
}*/

Aparelho* Zona::adicionaAparelho(const char& tipoDerivado) {

    Aparelho *novoAparelho = nullptr;

    if (tipoDerivado == 'a') {
        novoAparelho = new Aquecedor();
    } else if (tipoDerivado == 's') {
        novoAparelho = new Aspersor();
    } else if (tipoDerivado == 'r') {
        novoAparelho = new Refrigerador();
    } else if (tipoDerivado == 'l') {
        novoAparelho = new Lampada();
    }
    // Se tipoDerivado não for 'a', 's', 'r' ou 'l', novoAparelho permanecerá como nullptr

    if (novoAparelho != nullptr) {
        aparelhos.push_back(novoAparelho);
    }

    return novoAparelho;
}

Sensor* Zona::adicionaSensor(const char& tipoDerivado) {

    Sensor *novoSensor = nullptr;

    switch (tipoDerivado) {
        case 't': // temperatura
            novoSensor = new SensorTemperatura();
            break;
        case 'v': // movimento
            novoSensor = new SensorMovimento();
            break;
        case 'm': // luminosidade
            novoSensor = new SensorLuminosidade();
            break;
        case 'd': // radiacao
            novoSensor = new SensorRadiacao();
            break;
        case 'h': // humidade
            novoSensor = new SensorHumidade();
            break;
        case 'o': // som
            novoSensor = new SensorSom();
            break;
        case 'f': // fumo
            novoSensor = new SensorFumo();
            break;
        default:
            // Tratar o caso em que tipoEquipamento não é reconhecido
            return nullptr;
    }

    if (novoSensor != nullptr) {
        sensores.push_back(novoSensor);
    }

    return novoSensor;
}

Processador* Zona::adicionaProcessador(const string& comando) {
    Processador* novo = new Processador(comando);
    processadores.push_back(novo);
    return novo;
}

bool Zona::removeEquipamento(const char &tipoEquipamento, const int &idEquipamento) {

    if(tipoEquipamento == 'a'){
        for(auto it = aparelhos.begin(); it != aparelhos.end();){
            if ((*it)->getId() == idEquipamento) {
                //da-se delete primeiro do que o erase pq se eu fizesse erase primeiro o erase devolve a posicao do proximo elemento entao se fizessemos delete depois iamos apagar o seguinte e o delete remove o elemento da memoria dinamica entao tem que se dar erase depois para remover a posicao dele no vetor

                delete *it; // Liberta a memória alocada
                aparelhos.erase(it); // Remove o elemento do vetor
                return true;
            } else {
                ++it; // Avanca para o próximo elemento
            }
        }

        return false;
    }

    if(tipoEquipamento == 's'){
        for(auto it = sensores.begin(); it != sensores.end();){
            if ((*it)->getId() == idEquipamento) {
                delete *it; // Liberta a memória alocada
                sensores.erase(it); // Remove o elemento do vetor
                return true;
            } else {
                ++it; // Avanca para o próximo elemento
            }
        }

        return false;
    }

    if(tipoEquipamento == 'p'){
        for(auto it = processadores.begin(); it != processadores.end();){
            if ((*it)->getId() == idEquipamento) {
                delete *it; // Liberta a memória alocada
                processadores.erase(it); // Remove o elemento do vetor
                return true;
            } else {
                ++it; // Avanca para o próximo elemento
            }
        }

        return false;
    }

    return false;
}

bool Zona::associaProcessadorAparelho(const int& idProcRegras, const int& idAparelho){
    Aparelho* aparelhoAssociado = nullptr;
    for(Aparelho* a: aparelhos){
        if(a->getId() == idAparelho){
            aparelhoAssociado = a;
        }
    }

    if(aparelhoAssociado != nullptr){
        for(Processador* p: processadores){
            if(p->getId() == idProcRegras){
                p->adicionaAparelhoAssociado(aparelhoAssociado);
                return true;
            }
        }
    }

    return false;
}

bool Zona::desassociaProcessadorAparelho(const int& idProcRegras, const int& idAparelho){
    Aparelho* aparelhoAssociado = nullptr;
    for(Aparelho* a: aparelhos){
        if(a->getId() == idAparelho){
            aparelhoAssociado = a;
        }
    }

    if(aparelhoAssociado != nullptr){
        for(Processador* p: processadores){
            if(p->getId() == idProcRegras){
                p->removeAparelhoAssociado(aparelhoAssociado);
                return true;
            }
        }
    }

    return false;
}

//tratamento de propriedades da zona
void Zona::inserePropriedade(const string &key, const int &value) { propriedades[key] = value; }

int Zona::obtemValorPropriedade(const string &key) {
    for(map<string, int>::iterator it = propriedades.begin(); it != propriedades.end();){
        if(it->first == key)
            return it->second;
        else
            ++it;
    }

    return -274; //valor para quando da erro
}

bool Zona::alteraPropriedade(const string& key, const int& value){

    string keyLower = key;
    transform(keyLower.begin(), keyLower.end(), keyLower.begin(), ::tolower);

    for(map<string, int>::iterator it = propriedades.begin(); it != propriedades.end();){

        string currentKeyLower = it->first;
        transform(currentKeyLower.begin(), currentKeyLower.end(), currentKeyLower.begin(), ::tolower);

        if(currentKeyLower == key){
            it->second = value;
            return true;
        }else
            ++it;
    }

    return false;
}

//getters
int Zona::getId() const {return id;}

array<int, 2> Zona::getPosicao() const {return {this->posX, this->posY};}

vector<Aparelho*> Zona::getAparelhos() const {
    return aparelhos;
}

vector<Sensor*> Zona::getSensores() const {
    return sensores;
}

vector<Processador*> Zona::getProcessadores() const {
    return processadores;
}

Processador* Zona::getProcessadorById(const int& idProcRegra) const {
    for(Processador* proc: processadores){
        if(proc->getId() == idProcRegra)
            return proc;
    }

    return nullptr;
}

bool Zona::eliminaRegraDoProcessador(const int &idProcessador, const int &idRegra) {
    for(Processador* p: processadores){
        if(p->getId() == idProcessador){
            return p->eliminaRegra(idRegra);
        }
    }

    return false;
}

string Zona::zonaAsString() const {

    ostringstream oss;

    oss << endl << "Zona: " << id << endl
        << "Numero de Aparelhos: " << aparelhos.size() << endl
        << "Numero de Sensores: " << sensores.size() << endl
        << "Numero de Processador: " << processadores.size() << endl << endl;


    return oss.str();
}

string Zona::getEquipamentosAsString() const {

    ostringstream oss;

    oss << "Zona: " << id << endl;

    for(Aparelho* a: aparelhos){
        oss << "Tipo: a" << a->getAparelhoAsString() << endl;
    }

    /*for(Processador* s: processadores){
        oss << "Zona: " << id << endl
            << "Tipo: p" << p->getEquipamentoAsString() << endl;
        break;
    }*/

    for(Sensor* s: sensores){
        oss << "Tipo: s" << s->getSensorAsString() << endl;
    }

    return oss.str();

}

string Zona::listaPropriedades() const {
    ostringstream oss;

    oss << "Zona: " << id << endl;

    for(map<string, int>::const_iterator it = propriedades.cbegin(); it != propriedades.cend(); ++it){
        oss << "\tPropriedade: " << it->first << "   Valor: " << it->second << endl;
    }

    return oss.str();
}

int Zona::criaNovaRegraNoProcessador(const int &idProcRegra, const string &tipoRegra, const int &idSensor,
                                     vector<int> params) {

    Sensor* aux = nullptr;

    for(Sensor* s: sensores){
        if(s->getId() == idSensor){
             aux = s;
        }
    }

    if(aux != nullptr){
        for(Processador* p: processadores){
            if(p->getId() == idProcRegra){
                return p->criaNovaRegra(tipoRegra, aux, params);
            }
        }
    }else return -2; // o id do Sensor introduzido é invalido

    return -1; // nao foi possivel criar a regra
}
