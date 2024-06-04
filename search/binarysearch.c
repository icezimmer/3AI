#include <stdio.h>
#include <stdlib.h>

// Funzione ricorsiva per eseguire la ricerca binaria
int binarysearch(int *arr, int sx, int dx, int target) {
    if (sx <= dx) {
        int cx = sx + (dx - sx) / 2; // Calcola l'indice centrale

        if (*(arr + cx) == target) {
            return cx; // Elemento trovato, restituisce l'indice
        }

        if (*(arr + cx) > target) {
            return binarysearch(arr, sx, cx - 1, target); // Cerca nella metà sinistra
        }

        return binarysearch(arr, cx + 1, dx, target); // Cerca nella metà destra
    }

    return -1; // Elemento non trovato
}

int main() {
    int size;
    int target;

    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &size);

    // Allocazione dinamica dell'array
    int *arr = (int*) malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }

    // Inserimento degli elementi nell'array
    printf("Inserisci gli elementi dell'array in ordine crescente:\n");
    for (int i = 0; i < size; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", arr + i);
    }

    // Inserimento del valore da cercare
    printf("Inserisci il valore da cercare: ");
    scanf("%d", &target);

    int result = binarysearch(arr, 0, size - 1, target);

    if (result != -1) {
        printf("Elemento trovato all'indice: %d\n", result);
    } else {
        printf("Elemento non trovato\n");
    }

    // Deallocazione della memoria
    free(arr);

    return 0;
}
