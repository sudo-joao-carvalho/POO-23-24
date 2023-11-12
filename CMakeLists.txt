cmake_minimum_required(VERSION 3.23)
project(POO_23_24)

set(CMAKE_CXX_STANDARD 14)

add_executable(POO_23_24 main.cpp Interface.cpp Interface.h Terminal.cpp Terminal.h Habitacao.cpp Habitacao.h Zona.cpp Zona.h Aparelhos/Aparelho.cpp Aparelhos/Aparelho.h Aparelhos/Aquecedor.cpp Aparelhos/Aquecedor.h Aparelhos/Aspersor.cpp Aparelhos/Aspersor.h Aparelhos/Refrigerador.cpp Aparelhos/Refrigerador.h Aparelhos/Lampada.cpp Aparelhos/Lampada.h Equipamento.cpp Equipamento.h Sensores/Sensor.cpp Sensores/Sensor.h
        Sensores/SensorTemperatura.h
        Sensores/SensorTemperatura.h
        Sensores/SensorTemperatura.cpp
        Sensores/SensorLuminosidade.h
        Sensores/SensorLuminosidade.cpp
        Sensores/SensorMovimento.h
        Sensores/SensorMovimento.cpp
        Sensores/SensorRadiacao.cpp
        Sensores/SensorRadiacao.h
        Sensores/SensorHumidade.h
        Sensores/SensorHumidade.cpp
        Sensores/SensorFumo.h
        Sensores/SensorFumo.cpp
        Sensores/SensorSom.h
        Sensores/SensorSom.cpp Processadores/Processador.cpp Processadores/Processador.h Regras/Regra.cpp Regras/Regra.h EOperador.h)

target_link_libraries(${PROJECT_NAME} -lncurses)