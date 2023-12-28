//
// Created by João Carvalho on 21/10/2023.
//

#include "Habitacao.h"

Habitacao::Habitacao(const int& nLinhas, const int& nColunas):maxLinha(nLinhas), maxColuna(nColunas), tempo(1) {
}

Habitacao::~Habitacao(){

    //TODO Zona::idZona = 0; // é necessario dar reset a variavel static da zona pois quando é feito hrem a zona que é criada tem que ser a primeira novamente e nao ontinua com o id anterior;

    for(auto & zona : zonas)
        delete zona;

}

void Habitacao::avancaTempo() { tempo++; }

//void Habitacao::avancaTempoNVezes(const int &n) { tempo += n; }

void Habitacao::adicionaZona(const int& linha, const int& coluna) {
    Zona* aux = new Zona(coluna, linha);
    zonas.push_back(aux);
}

bool Habitacao::removeZonaById(const int &id) {

    for(vector<Zona*>::iterator it = zonas.begin(); it != zonas.end();){
        if ((*it)->getId() == id) {
            delete *it; // Liberta a memória alocada
            zonas.erase(it); // Remove o elemento do vetor //TODO perguntar ao stor pq q se isto estiver comentado da erro
            return true;
        } else {
            ++it; // Avanca para o próximo elemento
        }
    }

    return false;
}


int Habitacao::adicionaAparelhoAZona(const int &idZona, const char& tipoEquipamento) {

    for (Zona *zona : zonas) {
        if (zona->getId() == idZona) {
            Aparelho *novoAparelho = zona->adicionaAparelho(tipoEquipamento);
            if (novoAparelho != nullptr) {
                return novoAparelho->getId();
            } else {
                // Tratar o caso em que adicionaAparelho retorna nullptr
                return -1;
            }
        }
    }
    // Tratar o caso em que a zona não é encontrada
    return -1;
}

int Habitacao::adicionaSensorAZona(const int &idZona, const char &tipoEquipamento) {

    for (Zona *zona : zonas) {
        if (zona->getId() == idZona) {
            Sensor *novoSensor = zona->adicionaSensor(tipoEquipamento);
            if (novoSensor != nullptr) {
                return novoSensor->getId();
            } else {
                // Tratar o caso em que adicionaSensor retorna nullptr
                return -1;
            }
        }
    }
    // Tratar o caso em que a zona não é encontrada
    return -1;

}

int Habitacao::adicionaProcessadorAZona(const int &idZona, const string &comando) {

    for (Zona *zona : zonas) {
        if (zona->getId() == idZona) {
            Processador *novoProcessador = zona->adicionaProcessador(comando);
            if (novoProcessador != nullptr) {
                return novoProcessador->getId();
            }
        }
    }
    // Tratar o caso em que a zona não é encontrada
    return -1;

}

bool Habitacao::associaProcessadorDaZonaAparelho(const int& idZona, const int& idProcRegras, const int& idAparelho){
    for(Zona* zona: zonas){
        if(zona->getId() == idZona){
            if(zona->associaProcessadorAparelho(idProcRegras, idAparelho)){
                return true;
            }else return false;
        }
    }

    return false;
}

bool Habitacao::desassociaProcessadorDaZonaAparelho(const int& idZona, const int& idProcRegras, const int& idAparelho){
    for(Zona* zona: zonas){
        if(zona->getId() == idZona){
            if(zona->desassociaProcessadorAparelho(idProcRegras, idAparelho)){
                return true;
            }else return false;
        }
    }

    return false;
}

bool Habitacao::verificaSeGravacaoExiste(const string& nome){
    if(gravacoesProcessadores.count(nome) == 1){
        return true;
    }else return false;
}

bool Habitacao::salvaProcessadorDaZona(const int& idZona, const int& idProcRegra, const string& nome){
    for(Zona* zona: zonas){
        if(zona->getId() == idZona){
            Processador* aux = nullptr;

            for(Processador* p: zona->getProcessadores()){
                if(p->getId() == idProcRegra){
                    aux = p;
                }
            }

            if(aux == nullptr) return false;

            Processador* novoProcessador = new Processador(*aux);
            gravacoesProcessadores.insert(pair<string, Processador*>(nome, novoProcessador));
            return true;
        }
    }

    return false;
}

bool Habitacao::removeGravacaoProcessador(const string &nome) {
    gravacoesProcessadores.erase(nome); //remove o elemento dado a key
}

string Habitacao::listaGravacoes() const {

    ostringstream oss;

    for(auto it = gravacoesProcessadores.begin(); it != gravacoesProcessadores.end(); it++){
        oss << endl << "Nome: " << it->first << endl
            << "ID Processador: " << it->second->getId() << endl
            << "ID Zona: " << it->second->getIdZona() << endl;
            //<< "N aparelhos associados" << it->second->getAparelhosAssociados().size();
    }

    return oss.str();
}

bool Habitacao::mudaComandoAparelhoNaZona(const int& idZona, const int& idAparelho, const string& comando){
    for(Zona* zona: zonas){
        if(zona->getId() == idZona){
            if(zona->mudaComandoAparelho(idAparelho, comando)){
                return true;
            }else return false;
        }
    }

    return false;
}


bool Habitacao::removeEquipamentoByID(const int& idZona, const char& tipoEquipamento, const int& idEquipamento){ //Modificar aqui para dar return do objeto eliminado

    for(Zona* zona: zonas){
        if(zona->getId() == idZona){
            if(zona->removeEquipamento(tipoEquipamento, idEquipamento))
                return true;
            else return false;
        }
    }

    return false;
}

//TODO verificar com o professor se esta bem
int Habitacao::mudaComandoProcessadorNaZona(const int& idZona, const int& idProcRegra, const string& novoComando){

    //TODO fazer com smart pointer weak

    Zona* auxZona = getZonaById(idZona);
    if(auxZona == nullptr) return -1;
    Processador* auxProc = auxZona->getProcessadorById(idProcRegra);
    if(auxProc == nullptr) return -2;

    auxProc->setComandoOutput(novoComando);
    return 0;
}

bool Habitacao::removeRegraDoProcessadorDaZona(const int &idZona, const int &idProcRegra, const int &idRegra) {
    for(Zona* z: zonas){
        if(z->getId() == idZona){
            return z->eliminaRegraDoProcessador(idProcRegra, idRegra);
        }
    }

    return false;
}

//Propriedades
bool Habitacao::alteraPropriedade(const int& idZona, const string& key, const int& value, const char& operacao){

    for(Zona* zona: zonas){
        if(zona->getId() == idZona){
            if(zona->alteraPropriedade(key, value, operacao))
                return true;
            else return false;
        }
    }

    return false;
}

//getters
int Habitacao::getTempo() const { return tempo; }

int Habitacao::getMaxLinha() const { return maxLinha; }

int Habitacao::getMaxColuna() const { return maxColuna; }

vector<Zona*> Habitacao::getZonas(){
    return zonas;
}

Zona* Habitacao::getZonaByPosicao(const int& posX, const int& posY) const{

    for(Zona* zona: zonas){
        if(zona->getPosicao()[0] - 1 == posX && zona->getPosicao()[1] - 1 == posY)
            return zona;
    }

    return nullptr;
}

Zona* Habitacao::getZonaById(const int& idZona) const{
    for(Zona* zona: zonas){
        if(zona->getId() == idZona){
            return zona;
        }
    }

    return nullptr;
}

/*Aparelho* Habitacao::getAparelho(const int& posX, const int& posY, const int &indiceAparelho) const {
    for(Zona* zona: zonas){
        if(zona->getPosicao()[0] - 1 == posX && zona->getPosicao()[1] - 1 == posY)
            return zona->getAparelhoAtIndex(indiceAparelho);
    }
}*/

string Habitacao::listaZonas() const {

    ostringstream oss;

    for(Zona* zona: zonas){
        oss << zona->zonaAsString();
    }

    return oss.str();
}

string Habitacao::listaEquipamentoZona(const int& id) const {

    ostringstream oss;

    for(Zona* zona: zonas){
        if(zona->getId() == id)
            oss << zona->getEquipamentosAsString();
    }

    return oss.str();
}

string Habitacao::listaPropriedadesZona(const int &id) const {

    ostringstream oss;

    for(Zona* zona: zonas){
        if(zona->getId() == id){
            oss << zona->listaPropriedades();
            return oss.str();
        }

    }

    return "Zona nao existe";
}

string Habitacao::listaRegrasNoProcessador(const int& idZona, const int& idProcRegra) const {

    Zona* zonaAux = getZonaById(idZona);
    if(zonaAux == nullptr) return "Zona nao existe";

    Processador* processadorAux = zonaAux->getProcessadorById(idProcRegra);
    if(processadorAux == nullptr) return "Processador nao existe";

    return processadorAux->getRegrasAsString();
}

int Habitacao::criaNovaRegraNoProcessadorDaZona(const int& idZona , const int& idProcRegra, const string& tipoRegra, const int& idSensor, vector<int> params) {
    for(Zona* z: zonas){
        if(z->getId() == idZona)
            return z->criaNovaRegraNoProcessador(idProcRegra, tipoRegra, idSensor, params);
    }

    return -1;
}
