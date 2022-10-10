#ifndef simulador
#define simulador

#include <iostream>
#include "fila.h"

namespace Atendimento {
	
	struct Dias {
		float qtd_dias = 5;
		float minutos = 480; // 8 horas
		float pessoas_por_minuto = 5;
	};

	struct Secretaria {
		float num_atendentes = 1;
		float minutos_de_trabalho = 480;
		float atendimentos_por_minuto = 1;
		float atendimentos_pendentes = 0;
		float atendimentos_efetuados = 0;
		float aten_por_atendente = 0;
		float pendentes_por_atendente = 0;
		float media_atendente = 0;
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
			}
			for (int j = 0; j < sec.minutos_de_trabalho; j++) {
				for (int k = 0; k < sec.atendimentos_por_minuto; k++) {
					Estrutura::dequeue(f);
					sec.atendimentos_efetuados++;
					sec.atendimentos_pendentes--;
				}
			}
			sec.aten_por_atendente = sec.atendimentos_efetuados / sec.num_atendentes;
			sec.pendentes_por_atendente = sec.atendimentos_pendentes / sec.num_atendentes;
			sec.media_atendente = sec.atendimentos_efetuados / sec.aten_por_atendente / sec.num_atendentes * 100 / sec.num_atendentes;

			//sec.atendimentos_pendentes += Estrutura::getSize(f);

			while (f.first != nullptr) { // Pessoas na fila indo embora após terminar o dia
				Estrutura::dequeue(f);
			}

			std::cout << " Fim do dia " << i + 1 << std::endl << " Atendentes: " << sec.num_atendentes << std::endl << " Atendimentos efetuados: " << sec.atendimentos_efetuados
				<< std::endl << " Atendimentos pendentes: " << sec.atendimentos_pendentes << "\n\n" << " Atendimentos por atendente: " << sec.aten_por_atendente <<
				 std::endl << " Pendentes por atendente: " << sec.pendentes_por_atendente << std::endl << " Media de ocupacao diaria por atendente: " << sec.media_atendente <<
				 "%" << "\n\n";

			system("pause");
			system("CLS");
		}
	}

	float descobrir_num_de_atendentes(Dias dia, Secretaria sec) {
		if (dia.minutos > sec.minutos_de_trabalho) {
			sec.atendimentos_pendentes += (dia.minutos - sec.minutos_de_trabalho) * dia.qtd_dias * dia.pessoas_por_minuto;
		}
		return (sec.atendimentos_pendentes + dia.pessoas_por_minuto * sec.minutos_de_trabalho * dia.qtd_dias) / ((sec.minutos_de_trabalho) * dia.qtd_dias);
	}
}

#endif
