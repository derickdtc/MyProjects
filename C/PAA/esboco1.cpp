#include <iostream>
using namespace std;

// Função para mesclar dois subarrays ordenados
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamanho do subarray esquerdo
    int n2 = right - mid;    // Tamanho do subarray direito

    // Criar arrays temporários dinamicamente
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Copiar os dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = arr[mid + 1 + i];

    // Índices iniciais dos subarrays e do array principal
    int i = 0, j = 0, k = left;

    // Mesclar os arrays temporários no array principal
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes do subarray esquerdo (se houver)
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes do subarray direito (se houver)
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    // Liberar memória alocada dinamicamente
    delete[] leftArray;
    delete[] rightArray;
}

// Função recursiva do MergeSort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Encontrar o meio

        // Dividir o array em duas partes
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mesclar as duas metades
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Chamar o MergeSort
    mergeSort(arr, 0, size - 1);

    cout << "Array ordenado: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
