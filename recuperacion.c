#include <stdio.h>
#include <string.h>

int main() {
    char nombres[6][30];  
    int puntos[6] = {0, 0, 0, 0, 0, 0};  
    char ganador_c[3][30]; 
    int puntos_f[3] = {0, 0, 0}; 
    char primero[30], segundo[30];  

    for (int i = 0; i < 6; i++) {
        printf("Ingrese el nombre del peleador %d: ", i + 1);
        fgets(nombres[i], 30, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0';  
    }

    printf("\n-----COMBATE-----\n");

    int cont = 0;
    while (cont < 6) {
        printf("Elija el ganador del combate entre:\n1. %s\n2. %s\nElija una opcion: ", nombres[cont], nombres[cont + 1]);
        int opc;
        scanf("%d", &opc);

        int puntos_ingresados;
        if (opc == 1) {
            do {
                printf("Ingrese los puntos por los cuales el peleador %s gano: ", nombres[cont]);
                if (scanf("%d", &puntos_ingresados) != 1 || puntos_ingresados < 0) {
                    printf("Entrada inválida. Por favor, ingrese un número positivo.\n");
                    while (getchar() != '\n');  
                }
            } while (puntos_ingresados < 0);
            puntos[cont] = puntos_ingresados;
        } else {
            do {
                printf("Ingrese los puntos por los cuales el peleador %s gano: ", nombres[cont + 1]);
                if (scanf("%d", &puntos_ingresados) != 1 || puntos_ingresados < 0) {
                    printf("Entrada inválida. Por favor, ingrese un número positivo.\n");
                    while (getchar() != '\n');  
                }
            } while (puntos_ingresados < 0);
            puntos[cont + 1] = puntos_ingresados;
        }

        cont += 2;
    }

    cont = 0;
    for (int i = 0; i < 3; i++) {
        if (puntos[cont] > puntos[cont + 1]) {
            strcpy(ganador_c[i], nombres[cont]);
            puntos_f[i] = puntos[cont];
        } else {
            strcpy(ganador_c[i], nombres[cont + 1]);
            puntos_f[i] = puntos[cont + 1];
        }
        cont += 2;
    }

    printf("-----GANADORES DE LA LLAVE-----\n");
    for (int i = 0; i < 3; i++) {
        printf("C%d: %s con %d puntos.\n", i + 1, ganador_c[i], puntos_f[i]);
    }

    if (puntos_f[0] > puntos_f[1] && puntos_f[0] > puntos_f[2]) {
        strcpy(primero, ganador_c[0]);
        if (puntos_f[1] > puntos_f[2]) {
            strcpy(segundo, ganador_c[1]);
        } else {
            strcpy(segundo, ganador_c[2]);
        }
    } else if (puntos_f[1] > puntos_f[0] && puntos_f[1] > puntos_f[2]) {
        strcpy(primero, ganador_c[1]);
        if (puntos_f[0] > puntos_f[2]) {
            strcpy(segundo, ganador_c[0]);
        } else {
            strcpy(segundo, ganador_c[2]);
        }
    } else {
        strcpy(primero, ganador_c[2]);
        if (puntos_f[0] > puntos_f[1]) {
            strcpy(segundo, ganador_c[0]);
        } else {
            strcpy(segundo, ganador_c[1]);
        }
    }

    printf("fINALISTA 1: %s\n", primero);
    printf("FINALISTA 2: %s\n", segundo);
    printf("Elija el ganador del combate entre:\n1. %s\n2. %s\nElija una opcion: ", primero, segundo);

    int opc_final;
    scanf("%d", &opc_final);

    int puntos_finalista;
    if (opc_final == 1) {
        do {
            printf("Ingrese los puntos por los cuales el peleador %s gano: ", primero);
            if (scanf("%d", &puntos_finalista) != 1 || puntos_finalista < 0) {
                printf("Entrada inválida, ingrese un numero positivo.\n");
                while (getchar() != '\n');  
            }
        } while (puntos_finalista < 0);
        printf("%s GANO\n", primero);
    } else {
        do {
            printf("Ingrese los puntos por los cuales el peleador %s gano: ", segundo);
            if (scanf("%d", &puntos_finalista) != 1 || puntos_finalista < 0) {
                printf("Entrada inválida, ingrese un numero positivo.\n");
                while (getchar() != '\n');  
            }
        } while (puntos_finalista < 0);
        printf("%s GANO\n", segundo);

    }

    return 0;
}
