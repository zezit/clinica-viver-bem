#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "medicos.h"

char esp_std[3][20] = {"Cardiologia", "Dermatologia", "Clínica Médica"};

bool cadastrar_medicos(char *nome, char *especialidade, char *telefone)
{
    FILE *medicos;
    bool existe = false;
    int num_linhas = 0;
    int newCode = 10000 + rand() % (99999 - 10000);
    int code_aux;

    medicos = fopen("./armazenamento/medicos.txt", "r");

    while (!feof(medicos))
    {
        char line[1024] = "";

        if (fgets(line, 1023, medicos))
        {
            printf("%s\n", line);

            char *aux;
            char *code = (char *)malloc(500);
            char *name = (char *)malloc(500);
            char *tel = (char *)malloc(500);
            char *espc = (char *)malloc(500);

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

            aux = strtok(NULL, "#"); // pega o telefone
            strcpy(tel, aux);
            strcat(tel, "\0");
            printf("%s\n", tel);

            aux = strtok(NULL, "#"); // pega a especialidade
            strcpy(espc, aux);
            strcat(espc, "\0");
            printf("%s\n", espc);

            if ((strncmp(nome, name, strlen(name)) == 0) &&
                (strncmp(telefone, tel, strlen(tel)) == 0) &&
                (strncmp(espc, especialidade, strlen(espc)) == 0))
            {
                existe = true;
                printf("ERRO: paciente já existe no sistema.\n");
            }

            num_linhas++;

            free(code);
            free(name);
            free(tel);
            free(espc);
        }
    }

    if (!existe)
    {
        medicos = fopen("./armazenamento/medicos.txt", "a");
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

        // coloca telefone
        strcat(buffer, telefone);
        strcat(buffer, "#"); // limitador

        // coloca especialidade
        strcat(buffer, especialidade);
        strcat(buffer, "\n"); // limitador

        printf("Salvando: %s\n", buffer);

        fputs(buffer, medicos);

        fclose(medicos);

        free(buffer);
        free(num_aux);

        return true;
    }

    else
    {
        return false;
    }
}

void coleta_dados_medicos(medico_std *medicos_dados)
{
    int aux_num;

    // coletando informações
    printf("Nome completo -> ");
    fflush(stdin);
    gets(medicos_dados->nome);

    printf("\nTelefone\n");
    printf("DDD -> ");
    fflush(stdin);
    scanf("%d", &medicos_dados->ddd);
    printf("Número -> ");
    fflush(stdin);
    gets(medicos_dados->telefone);

    printf("1 - Cardiologia\n");
    printf("2 - Dermatologia\n");
    printf("3 - Clínica Médica\n\n");
    printf("Especialidade -> ");
    fflush(stdin);
    scanf("%d", &aux_num);
    aux_num--;
    if (aux_num >= 0 && aux_num <= 2)
    {
        strcpy(medicos_dados->especialidade, esp_std[aux_num]);
    }
    else
    {
        strcpy(medicos_dados->especialidade, "");
    }
}