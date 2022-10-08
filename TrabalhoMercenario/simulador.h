#ifndef simulador
#define simulador

#include <iostream>
#include "fila.h"

namespace Atendimento {
	
	struct Dias {
		int qtd_dias = 5;
		int minutos = 480; // 8 horas
		int pessoas_por_minuto = 5;
	};

	struct Secretaria {
		int num_atendentes = 1;
		int atendimentos_por_minuto = 1;
		int atendimentos_pendentes = 0;
		int atendimentos_efetuados = 0;
	};

	void atender_clientes(Secretaria& sec, Dias dia, Estrutura::Fila<int>& f) {
		if (sec.atendimentos_pendentes > 0) {
			for (int i = 0; i < sec.atendimentos_pendentes; i++) { // Pessoas voltando no dia segunte caso não tenham sido atentidas
				Estrutura::queue(f, 1);
			}
		}
		for (int i = 0; i < dia.qtd_dias; i++) {
			for (int j = 0; j < dia.minutos; j++) {
				for (int k = 0; k < dia.pessoas_por_minuto; k++) {
					Estrutura::queue(f, 1);
					sec.atendimentos_pendentes++;
				}
				for (int k = 0; k < sec.atendimentos_por_minuto; k++) {
					Estrutura::dequeue(f);
					sec.atendimentos_efetuados++;
					sec.atendimentos_pendentes--;
				}
			}
			//sec.atendimentos_pendentes += Estrutura::getSize(f);

			while (f.first != nullptr) { // Pessoas na fila indo embora após terminar o dia
				Estrutura::dequeue(f);
			}

			std::cout << " Fim do dia " << i + 1 << std::endl << " Atendentes: " << sec.num_atendentes << std::endl << " Atendimentos efetuados: " << sec.atendimentos_efetuados
				<< std::endl << " Atendimentos pendentes: " << sec.atendimentos_pendentes << "\n\n";

			system("pause");
			system("CLS");
		}
	}
}

#endif
