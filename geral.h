#ifndef GERAL_LIB_H
#define GERAL_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct
{
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
} data_std;

typedef struct
{
    unsigned int minuto;
    unsigned int hora;
} hora_std;

typedef struct
{
    // PACIENTE = código, nome, endereÃ§o, telefone e data de nascimento
    unsigned int codigo_paciente;
    char nome[100];
    char rua[100];
    int num_endereco;
    char bairro[100];
    char cidade[100];
    int ddd;
    char telefone[18];
    data_std data_nascimento;
} paciente_std;

typedef struct
{
    // MEDICO = código, nome, telefone, especialidade
    unsigned int codigo_medico;
    char nome[100];
    int ddd;
    char telefone[18];
    char especialidade[15];
} medico_std;

typedef struct
{
    // CONSULTA = código da consulta, data, hora, código do mÃ©dico, código do paciente
    unsigned int codigo;
    unsigned int codigo_medico;
    unsigned int codigo_paciente;
    data_std data;
    hora_std hora;
    char nome[100];
    char endereco[100];
    char telefone[18];
} consulta_std;

char *get_data_string(data_std d);
char *get_addres_paciente(char *rua, int numero_addr, char *bairro, char *cidade);
char *get_string_telefone(int ddd, char *num);

#endif // GERAL_LIB_H