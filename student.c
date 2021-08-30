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

void feature5(FILE *fout, int *parr, int length, char *op) {
    if (strcmp(op, "avg") == 0) {
        fprintf(fout, "%.0f\n", calcularPromedio(parr, length));
    } else if (strcmp(op, "max") == 0) {
        fprintf(fout, "%d\n", encontrarMinimo(parr, length));
    } else if (strcmp(op, "min") == 0) {
        fprintf(fout, "%d\n", encontrarMaximo(parr, length));
    }
}

double calcularPromedio(int *enteros, int length) {
    double suma = 0;

    for (int i = 0; i < length; ++i) {
        suma += enteros[i];
    }

    return suma != 0 ? suma / length : 0;
}

int encontrarMinimo(int *enteros, int length) {
    int minimo = enteros[0];

    for (int i = 1; i < length; ++i) {
        if (minimo > enteros[i]) {
            minimo = enteros[i];
        }
    }

    return minimo;
}

int encontrarMaximo(int *enteros, int length) {
    int maximo = enteros[0];

    for (int i = 1; i < length; ++i) {
        if (maximo < enteros[i]) {
            maximo = enteros[i];
        }
    }

    return maximo;
}

void feature6(FILE *fin, struct Obj_t *pobj) {
    char line[256];

    if (fgets(line, sizeof(line), fin) != NULL) {
        char *partes;
        partes = strtok(line, " ");

        char resultado[256];
        strcpy(resultado, partes);

        pobj->nombre = resultado;

        partes = strtok(NULL, " ");
        pobj->cedula = atoi(partes);
    }
}

void feature7(FILE *fout, struct Obj_t *pobj) {
    fprintf(fout, "%s,", pobj->nombre);
    fprintf(fout, "%d\n", pobj->cedula);
}

void feature8(FILE *fin, struct _courseInfo_t **pobj, int *length) {
    char line[256];

    if (fgets(line, sizeof(line), fin) != NULL) {
        *length = atoi(line);
        int n = *length;
        char entrada[256];

        for (int i = 0; i < n; ++i) {
            struct _courseInfo_t curso;
            struct _courseInfo_t *cursoPointer;
            cursoPointer = &curso;

            printf("ingresa el curso %d: ", (i + 1));
            scanf("%s", entrada);

            char *partes;
            partes = strtok(entrada, ",");

            strcpy(cursoPointer->name, partes);
            printf("F9in %s\n", cursoPointer->name);
            partes = strtok(NULL, ",");
            cursoPointer->credits = atoi(partes);
            printf("F9in %d\n", cursoPointer->credits);
            partes = strtok(NULL, ",");
            cursoPointer->grade = atoi(partes);
            printf("F9in %.2f\n", cursoPointer->grade);
            printf("\n");

            pobj[i] = cursoPointer;
        }
        printf("OK.....");
    }
}
