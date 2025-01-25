#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;

// Função para ajustar o heap (Heapify)
void heapify(int arr[], int n, int i) {
    int largest = i;       // Assume que o nó atual é o maior
    int left = 2 * i + 1;  // Filho à esquerda
    int right = 2 * i + 2; // Filho à direita

    // Verifica se o filho à esquerda é maior que o pai
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Verifica se o filho à direita é maior que o maior atual
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não for o nó atual
    if (largest != i) {
        swap(arr[i], arr[largest]); // Troca o nó atual com o maior
        heapify(arr, n, largest);  // Ajusta o sub-heap afetado
    }
}

// Função principal do HeapSort
void heapSort(int arr[], int n) {
    // Passo 1: Constrói o heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Passo 2: Extrai elementos do heap um a um
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);      // Move a raiz para o final
        heapify(arr, i, 0);        // Restaura o heap máximo
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(int argc, char const *argv[])
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original:\n";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Array ordenado:\n";
    printArray(arr, n);

    return 0;
    return 0;
}
