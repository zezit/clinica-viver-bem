#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "pacientes.h"
// #include "geral.h"

bool cadastrar_paciente(char *nome, char *endereco, char *telefone, data_std nascimento)
{
    FILE *pacientes;
    bool existe = false;
    int num_linhas = 0;
    int newCode = 10000 + rand() % (99999 - 10000);
    int code_aux;

    pacientes = fopen("./armazenamento/pacientes.txt", "r");

    while (!feof(pacientes))
    {
        char line[1024] = "";

        if (fgets(line, 1023, pacientes))
        {
            printf("%s\n", line);

            char *aux;
            char *code = (char *)malloc(500);
            char *name = (char *)malloc(500);
            char *addr = (char *)malloc(500);
            char *tel = (char *)malloc(500);
            char *nas = (char *)malloc(500);

            aux = strtok(line, "#");

            aux = strtok(NULL, "#"); // pega o codigo
            strcpy(code, aux);
            code_aux = atoi(code);
            if (code_aux == newCode)
            {
                newCode = 10000 + rand() % (99999 - 10000);
            }
            printf("%s\n", code);

            aux = strtok(NULL, "#"); // pega o nome
            strcpy(name, aux);
            strcat(name, "\0");
            printf("%s\n", name);

            aux = strtok(NULL, "#"); // pega o endereÃ§o
            strcpy(addr, aux);
            strcat(addr, "\0");
            printf("%s\n", addr);

            aux = strtok(NULL, "#"); // pega o telefone
            strcpy(tel, aux);
            strcat(tel, "\0");
            printf("%s\n", tel);

            aux = strtok(NULL, "#"); // pega a data de nascimento
            strcpy(nas, aux);
            strcat(nas, "\0");
            printf("%s\n", nas);

            if ((strncmp(nome, name, strlen(name)) == 0) &&
                (strncmp(endereco, addr, strlen(addr)) == 0) &&
                (strncmp(telefone, tel, strlen(tel)) == 0) &&
                (strncmp(nas, get_data_string(nascimento), strlen(get_data_string(nascimento))) == 0))
            {
                existe = true;
                printf("ERRO: paciente já existe no sistema.\n");
            }

            num_linhas++;

            free(code);
            free(name);
            free(addr);
            free(tel);
            free(nas);
        }
    }

    if (!existe)
    {
        pacientes = fopen("./armazenamento/pacientes.txt", "a");
        char *buffer = (char *)malloc(1024);
        char *num_aux = (char *)malloc(20);

        // coloca indice
        snprintf(num_aux, 20, "%d", num_linhas);
        strcpy(buffer, num_aux);
        strcat(buffer, "#"); // limitador

        // coloca codigo
        snprintf(num_aux, 20, "%5d", newCode);
        strcat(buffer, num_aux);
        strcat(buffer, "#"); // limitador

        // coloca nome
        strcat(buffer, nome);
        strcat(buffer, "#"); // limitador

        // coloca endereÃ§o
        strcat(buffer, endereco);
        strcat(buffer, "#"); // limitador

        // coloca telefone
        strcat(buffer, telefone);
        strcat(buffer, "#"); // limitador

        // coloca data de nascimento
        snprintf(num_aux, 20, "%d", nascimento.dia); // dia
        strcat(buffer, num_aux);
        strcat(buffer, "/");
        snprintf(num_aux, 20, "%d", nascimento.mes); // mÃªs
        strcat(buffer, num_aux);
        strcat(buffer, "/");
        snprintf(num_aux, 20, "%d", nascimento.ano); // ano
        strcat(buffer, num_aux);
        strcat(buffer, "\n"); // limitador

        printf("Salvando: %s\n", buffer);

        fputs(buffer, pacientes);

        fclose(pacientes);

        free(buffer);
        free(num_aux);

        return true;
    }

    else
    {
        return false;
    }
}

void coleta_dados_paciente(paciente_std *paciente_dados, data_std *nas_aux)
{
    unsigned int aux_num;

    // coletando informações
    printf("Nome completo -> ");
    fflush(stdin);
    gets(paciente_dados->nome);

    printf("\nNascimento\n");
    do
    {
        printf("Dia -> ");
        fflush(stdin);
        scanf("%u", &aux_num);
        nas_aux->dia = aux_num;
    } while (aux_num <= 0 || aux_num > 31);
    do
    {
        printf("Mês -> ");
        fflush(stdin);
        scanf("%u", &aux_num);
        nas_aux->mes = aux_num;
    } while (aux_num <= 0 || aux_num > 12);
    do
    {
        printf("Ano -> ");
        fflush(stdin);
        scanf("%u", &aux_num);
        nas_aux->ano = aux_num;
    } while (aux_num <= 0);

    printf("\nEndereço\n");
    printf("Rua -> ");
    fflush(stdin);
    gets(paciente_dados->rua);
    printf("Número -> ");
    fflush(stdin);
    scanf("%d", &paciente_dados->num_endereco);
    printf("Bairro -> ");
    fflush(stdin);
    gets(paciente_dados->bairro);
    printf("Cidade -> ");
    fflush(stdin);
    gets(paciente_dados->cidade);

    printf("\nTelefone\n");
    printf("DDD -> ");
    fflush(stdin);
    scanf("%d", &paciente_dados->ddd);
    printf("Número -> ");
    fflush(stdin);
    gets(paciente_dados->telefone);
}