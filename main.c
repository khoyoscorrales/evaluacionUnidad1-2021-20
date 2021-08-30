#include <stdio.h>
#include <stdlib.h>
#include "student.h"


int main(int argc, char *argv[]){
    if (argc == 3) {
        FILE *archivoFuente;
        FILE *archivoDestino;
        archivoFuente = fopen(argv[1], "r");
        archivoDestino = fopen(argv[2], "w");

        if (archivoFuente == NULL) {
            printf("MENSAJE: El archivo de fuente de datos no existe. Intente nuevamente.");
            exit(1);
        }
        if (archivoDestino == NULL) {
            printf("MENSAJE: El archivo de destino de datos no existe. Intente nuevamente.");
            exit(1);
        }

        const int FEATURE_1 = 1;
        const int FEATURE_2 = 2;
        const int FEATURE_3 = 3;
        const int FEATURE_4 = 4;    
        const int FEATURE_5 = 5;
        const int FEATURE_6 = 6;
        const int FEATURE_7 = 7;
        const int FEATURE_8 = 8;
         const int FEATURE_9 = 9;


        int arregloEnteros[100];
        int *enteros;
        enteros = arregloEnteros;
        int **arregloEnterosPtr = &enteros;

        int n;
        int *tamagnioArregloPtr = &n;
        *tamagnioArregloPtr = 0;

        char * operacion = "OPERACION";
        char** operacionPtr = &operacion;

        struct Obj_t objeto, *objetoPointer;
        objetoPointer = &objeto;

        struct _courseInfo_t *notas, **notasPointer;
        notasPointer = &notas;

        for (int i = 1; i <= 9; i++) {
            switch (i) {
                case FEATURE_1:
                    feature1(archivoFuente, archivoDestino);
                    break;
                 case FEATURE_2:
                    feature2(archivoFuente, archivoDestino);
                    break;
                case FEATURE_3:
                    feature3(archivoFuente, archivoDestino);
                    break;
                case FEATURE_4:
                    feature4(archivoFuente, arregloEnterosPtr, tamagnioArregloPtr, operacionPtr);
                    break;
                 case FEATURE_5:
                    feature5(archivoDestino, enteros, n, operacion);
                    break;
                case FEATURE_6:
                    feature6(archivoFuente, objetoPointer);
                    break;        
                case FEATURE_7:
                    feature7(archivoDestino, objetoPointer);
                     break;
                case FEATURE_8:
                    feature8(archivoFuente, notasPointer, tamagnioArregloPtr);
                    break;
                    case FEATURE_9:
                    feature9(archivoDestino, notas, n);
                    break;
            }
        }

        fclose(archivoFuente);
        fclose(archivoDestino);
        objetoPointer = NULL;
    }

    return EXIT_SUCCESS;
}
