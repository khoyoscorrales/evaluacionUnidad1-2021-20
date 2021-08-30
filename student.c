#include <stdlib.h>
#include "student.h"
#include <string.h>

void invertir(char *str);

int sumarContenidoArreglo(char *cadenaArreglo);

int contarEspacios(char *cadenaArreglo);

double calcularPromedio(int *enteros, int length);

int encontrarMinimo(int *enteros, int length);

int encontrarMaximo(int *enteros, int length);

double calcularPromedioPonderado(struct _courseInfo_t *pobj, int length);

void feature1(FILE *fin, FILE *fout) {
    char line[256];

    if (fgets(line, sizeof(line), fin) != NULL) {
        fprintf(fout, "%s", strtok(line, "\n"));
    }
}
void feature2(FILE *fin, FILE *fout) {
    char line[256];

    if (fgets(line, sizeof(line), fin) != NULL) {
        invertir(line);
        fprintf(fout, "%s\n", line);
    }
}

void invertir(char *cadena) {
    size_t tamagno = strlen(cadena);
    size_t i = 0;
    while (tamagno + 1 > i) {
        char temporal = cadena[--tamagno];
        cadena[tamagno] = cadena[i];
        cadena[i++] = temporal;
    }
}

void feature3(FILE *fin, FILE *fout) {
    char line[256];
    int suma;

    if (fgets(line, sizeof(line), fin) != NULL) {
        suma = sumarContenidoArreglo(line);

        fprintf(fout, "%d\n", suma);
    }
}

int sumarContenidoArreglo(char *cadenaArreglo) {
    int suma = 0;
    size_t tamagno = strlen(cadenaArreglo);
    size_t i = 0;

    while (i < tamagno) {
        char temporal = cadenaArreglo[i];

        if (temporal != ' ' && temporal != '\n') {
            suma += (temporal - '0');
        }

        ++i;
    }

    return suma;
}

void feature4(FILE *fin, int **parr, int *length, char **op) {
    char line[256];

    if (fgets(line, sizeof(line), fin) != NULL) {
        char *partes;
        *length = contarEspacios(line);
        int n = *length;
        int arreglo[n];

        partes = strtok(line, " ");
        arreglo[0] = atoi(partes);

        for (int i = 1; i < n; ++i) {
            partes = strtok(NULL, " ");
            arreglo[i] = atoi(partes);
        }

        int *enteros[n];
        for (int i = 0; i < n; ++i) {
            enteros[i] = &arreglo[i];
        }

        *parr = &arreglo;

        partes = strtok(NULL, " ");

        if (strcmp(partes, "avg\n") == 0) {
            *op = "avg";
        } else if (strcmp(partes, "max\n") == 0) {
            *op = "max";
        } else if (strcmp(partes, "min\n") == 0) {
            *op = "min";
        } else {
            *op = "ninguna";
        }
    }
}


int contarEspacios(char *cadenaArreglo) {
    size_t tamagno = strlen(cadenaArreglo);
    size_t i = 0;
    int contadorEspacios = 0;

    while (i < tamagno) {
        char temporal = cadenaArreglo[i];

        if (temporal == ' ') {
            ++contadorEspacios;
        }

        ++i;
    }

    return contadorEspacios;
}