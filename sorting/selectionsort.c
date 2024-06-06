#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funzione per generare un array casuale
void generateRandomArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Numeri casuali tra 0 e 99
    }
}



/* Selection Sort come visto a lezione.
 * Tempo: O(n^2)
 * Spazio: O(1)
 */
void selection_sort(int* a, int dim) {
    int i, j;

    for(i=0;i<dim-1;i++) { // L'ultimo elemento sarà già al posto giusto
        int pos_minimo = i;
        
        /* Cerchiamo il minimo dell'array e lo portiamo
         * alla fine della porzione di array già ordinata
         * (inizialmente vuota)
         */
        for(j=i+1;j<dim;j++) {
            if(a[j] < a[pos_minimo]) {
                pos_minimo = j;
            }
        }
        
        /* Scambiamo a[i] con a[pos_minimo] */
        int temp = a[i];
        a[i] = a[pos_minimo];
        a[pos_minimo] = temp;
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
    selection_sort(array, n);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tempo di ordinamento: %f secondi\n", cpu_time_used);

    /* Deallocazione della memoria occupata dall'array */
    free(array);

    return 0;
}
