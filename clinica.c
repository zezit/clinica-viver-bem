#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
// local
#include "clinica.h"
#include "pacientes.h"
#include "medicos.h"

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil"); // also try "pt_BR"
    srand((unsigned int)time(NULL));

    printf("=============================\n");
    printf("Bem vindo a Clínica Viva Bem!\n");
    printf("=============================\n\n");

    printf("Entradas do menu:\n");
    printf("1: Cadastrar paciente\n");
    printf("2: Cadastrar médico\n");
    printf("=============================\n\n");

    int menu_entry;
    printf("Insira uma opção -> ");
    fflush(stdin);
    scanf("%d", &menu_entry);
    printf("=============================\n\n");

    enter_menu(menu_entry);

    return 0;
}

void enter_menu(int menu_entry)
{
    switch (menu_entry)
    {
    case 1: // cadastro de pacientes

        printf("CADASTRO DE PACIENTES\n");
        printf("=====================\n\n");

        data_std nas_aux;

        paciente_std cria_paciente;

        coleta_dados_paciente(&cria_paciente, &nas_aux);

        cadastrar_paciente(cria_paciente.nome, get_addres_paciente(cria_paciente.rua, cria_paciente.num_endereco, cria_paciente.bairro, cria_paciente.cidade), get_string_telefone(cria_paciente.ddd, cria_paciente.telefone), nas_aux);

        break;

    case 2: // cadastro de médicos

        printf("CADASTRO DE MÉDICOS\n");
        printf("=====================\n\n");

        medico_std cria_medico;

        coleta_dados_medicos(&cria_medico);

        cadastrar_medicos(cria_medico.nome, cria_medico.especialidade, get_string_telefone(cria_medico.ddd, cria_medico.telefone));

        break;

    default:
        break;
    }
}