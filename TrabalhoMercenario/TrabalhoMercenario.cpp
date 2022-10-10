#include <iostream> // Feito por Gustavo Coelho
#include "fila.h"
#include "simulador.h"

int main()
{
    srand(time(NULL));
    
    /*using namespace Estrutura;
    Fila<int> f;
    inicializar(f);
    for (;;) {
    queue(f, 10);
    queue(f, 10);
    queue(f, 10);
    queue(f, 4);
    dequeue(f);
    dequeue(f);
    dequeue(f);
        dequeue(f);
    }
    print(f);

    for (int i = 0; i < 256; i++) {
        std::cout << char(i) << " " << int(char(i)) << std::endl;
    }

    //std::cout << Estrutura::getSize(f);*/

    Atendimento::Dias dia; // Parte 1
    Atendimento::Secretaria secretaria;
    Estrutura::Fila<int> f;
    Estrutura::inicializar(f);
    Atendimento::atender_clientes(secretaria, dia, f);

    system("pause");
    system("CLS");
    
    dia.qtd_dias = 3;
    secretaria.atendimentos_por_minuto = 1;
    secretaria.num_atendentes = Atendimento::descobrir_num_de_atendentes(dia, secretaria); //12; // 7 caso só sejam atendidas as pendentes e não cheguem mais pessoas além dessas
    secretaria.atendimentos_por_minuto = secretaria.num_atendentes * secretaria.atendimentos_por_minuto;

    Atendimento::atender_clientes(secretaria, dia, f);

    system("pause"); // Parte 2 - Aleatoriedade
    system("CLS");

    secretaria.num_atendentes = 2;
    dia.pessoas_por_minuto = rand() % 20 + 20;
    secretaria.atendimentos_por_minuto = (rand() % 10) * secretaria.num_atendentes;

    Atendimento::atender_clientes(secretaria, dia, f);

    system("pause"); // Parte 3 - Presumindo que sejam 5 pessoas por minuto
    system("CLS");

    Atendimento::Dias dia2;
    Atendimento::Secretaria secretaria2;
    Estrutura::Fila<int> f2;
    Estrutura::inicializar(f2);
    
    dia2.qtd_dias = 30;
    dia2.minutos = 24 * 60;
    dia2.pessoas_por_minuto = 5;
   

    secretaria2.atendimentos_por_minuto = 1;
    secretaria2.num_atendentes = Atendimento::descobrir_num_de_atendentes(dia2, secretaria2); //15;
    secretaria2.atendimentos_por_minuto = secretaria2.num_atendentes * secretaria2.atendimentos_por_minuto;
    Atendimento::atender_clientes(secretaria2, dia2, f2);

}
