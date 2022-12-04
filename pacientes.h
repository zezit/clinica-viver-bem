#ifndef PACIENTES_LIB_H
#define PACIENTES_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "geral.h"

bool cadastrar_paciente(char *nome, char *endereco, char *telefone, data_std nascimento);
void coleta_dados_paciente(paciente_std *paciente_dados, data_std *nas_aux);

#endif // PACIENTES_LIB_H
