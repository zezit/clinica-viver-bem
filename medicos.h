#ifndef MEDICOS_LIB_H
#define MEDICOS_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "geral.h"

bool cadastrar_medicos(char *nome, char *especialidade, char *telefone);
void coleta_dados_medicos(medico_std *medicos_dados);

#endif // MEDICOS_LIB_H
