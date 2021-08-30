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

