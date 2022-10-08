#include <iostream>
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

    Atendimento::Dias dia;
    Atendimento::Secretaria secretaria;
    Estrutura::Fila<int> f;
    Estrutura::inicializar(f);
    Atendimento::atender_clientes(secretaria, dia, f);

    system("pause"); // Parte 1
    
    secretaria.num_atendentes = 12; // 7 caso só sejam atendidas as pendentes e não cheguem mais pessoas além dessas
    secretaria.atendimentos_por_minuto = secretaria.num_atendentes;

    dia.qtd_dias = 3;

    Atendimento::atender_clientes(secretaria, dia, f);

    system("pause"); // Parte 2 - Aleatoriedade

    secretaria.num_atendentes = 2;
    dia.pessoas_por_minuto = rand() % 20 + 20;
    secretaria.atendimentos_por_minuto = (rand() % 10) * secretaria.num_atendentes;

    Atendimento::atender_clientes(secretaria, dia, f);

    system("pause"); // Parte 3 -
}
