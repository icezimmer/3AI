#include <stdio.h>
#include <stdlib.h>

// Funzione per eseguire la ricerca lineare
int linearsearch(int *arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == target) {
            return i; // Restituisce l'indice dell'elemento trovato
        }
    }
    return -1; // Restituisce -1 se l'elemento non è stato trovato
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
    printf("Inserisci gli elementi dell'array:\n");
    for (int i = 0; i < size; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", arr + i);
    }

    // Inserimento del valore da cercare
    printf("Inserisci il valore da cercare: ");
    scanf("%d", &target);

    int result = linearsearch(arr, size, target);

    if (result != -1) {
        printf("Elemento trovato all'indice: %d\n", result);
    } else {
        printf("Elemento non trovato\n");
    }

    // Deallocazione della memoria
    free(arr);

    return 0;
}

