#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "geral.h"

char *get_data_string(data_std d)
{
    char *data_str = (char *)malloc(20);
    char *aux = (char *)malloc(10);

    snprintf(aux, 10, "%d", d.dia);
    strcpy(data_str, aux);
    strcat(data_str, "/");
    snprintf(aux, 10, "%d", d.mes);
    strcat(data_str, aux);
    strcat(data_str, "/");
    snprintf(aux, 10, "%d", d.ano);
    strcat(data_str, aux);
    strcat(data_str, "\0");

    free(aux);

    printf("String da data inserida: %s\n\n", data_str);
    return data_str;
}

char *get_addres_paciente(char *rua, int numero_addr, char *bairro, char *cidade)
{
    char *endereco_completo = (char *)malloc(1024);
    char *aux = (char *)malloc(20);

    strcpy(endereco_completo, "Rua: ");
    strcat(endereco_completo, rua);
    strcat(endereco_completo, ", ");

    strcat(endereco_completo, "Nº: ");
    snprintf(aux, 20, "%d", numero_addr);
    strcat(endereco_completo, aux);
    strcat(endereco_completo, ", ");

    strcat(endereco_completo, "Bairro: ");
    strcat(endereco_completo, bairro);
    strcat(endereco_completo, ", ");

    strcat(endereco_completo, "Cidade: ");
    strcat(endereco_completo, cidade);

    strcat(endereco_completo, "\0");

    free(aux);

    printf("String do endereço inserida: %s\n\n", endereco_completo);

    return endereco_completo;
}

char *get_string_telefone(int ddd, char *num)
{
    char *telefone_completo = (char *)malloc(50);
    char *aux = (char *)malloc(10);

    strcpy(telefone_completo, "(");
    snprintf(aux, 10, "%d", ddd);
    strcat(telefone_completo, aux);
    strcat(telefone_completo, ") ");
    strcat(telefone_completo, num);
    strcat(telefone_completo, "\0");

    free(aux);

    printf("String do telefone inserido: %s\n\n", telefone_completo);

    return telefone_completo;
}