#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funzione per generare un array casuale
void generateRandomArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Numeri casuali tra 0 e 99
    }
}

/* Insertion Sort come visto a lezione.
 * Tempo: O(n^2)
 *        Si noti che se l'array è già ordinato (caso ottimo), il tempo scende a Θ(n).
 * Spazio: O(1)
 */
void insertion_sort(int* a, int dim) {
    int j, i;

    for(j=1;j<dim;j++) { // Si parte dal secondo elemento dell'array
        int key = a[j];
        i = j-1;
        /* Spostiamo "indietro" l'elemento a[j] in modo che alla sua destra
         * ci siano solo elementi maggiori di lui.
         */
        while(i >= 0 && a[i] > key) {
            a[i+1] = a[i];
            i--;
        }

        a[i+1] = key; // Nuova posizione di a[j] (cioè key)
    }
}

int main(void) {
    int *array;
    int n;
    int i;
    
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));

    // Genera array casuale
    srand(time(0));
    generateRandomArray(array, n);

    // Misura il tempo di ordinamento
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    insertion_sort(array, n);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tempo di ordinamento: %f secondi\n", cpu_time_used);

    /* Deallocazione della memoria occupata dall'array */
    free(array);

    return 0;
}
