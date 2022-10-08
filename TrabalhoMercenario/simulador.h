#ifndef simulador
#define simulador

#include <iostream>
#include "fila.h"

namespace Atendimento {
	
	struct Dia {
		int minutos = 480;
		int pessoas_por_minuto = 5;
	};

	struct Secretaria {
		int num_atendentes = 1;
		int atendimentos_por_minuto = num_atendentes * 1;
		int atendimentos_pendentes = 0;
		int atendimentos_efetuados = 0;
	};


}

#endif
