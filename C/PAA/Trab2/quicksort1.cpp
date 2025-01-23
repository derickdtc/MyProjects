#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;
int partirComLomutoPadrao(int arr[] , int first , int last){
    int pivot = arr[last];
    int i = first-1;
    for (int j = first; j < last ; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);           

        }        
    }
    swap(arr[i + 1], arr[last]);
    return i + 1;
    
}

int partirComHoarePadrao(int arr[], int first, int last) {
    int pivot = arr[first];
    int i = first - 1 , j = last + 1 ;

    while (true) {
      while(arr[--j] > pivot);
        while(arr[++i] < pivot);
        if(i < j ) swap(arr[i], arr[j]);
        else return j;
    }
}  
/*
int partitionHoare(int arr[], int low, int high) {
    int pivot = arr[low]; // Escolhe o primeiro elemento como pivô
    int i = low - 1;
    int j = high + 1;

    while (true) {
        // Encontra o primeiro elemento maior que o pivô da esquerda para a direita
        do {
            i++;
        } while (arr[i] < pivot);

        // Encontra o primeiro elemento menor que o pivô da direita para a esquerda
        do {
            j--;
        } while (arr[j] > pivot);

        // Se os índices se cruzarem, retorne o índice de separação
        if (i >= j)
            return j;

        // Caso contrário, troque os elementos
        swap(arr[i], arr[j]);
    }
}

int partir(int arr[] , int first , int last){
    int pivot = arr[last];
    int i = first - 1;
    for (int j = first; j < last; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i] , arr[j]);
        }
        
    }
    swap(arr[i+1], arr[last]);
    return i + 1;// retorna a posição do pivô
    
}*/

void quickSort(int arr[] , int first , int last){
    if (first < last)
    {
        int pivotIndexAfterPartir = partirComHoarePadrao(arr , first , last);
        quickSort(arr , first , pivotIndexAfterPartir - 1);
        quickSort(arr , pivotIndexAfterPartir + 1 , last);
    }
    
}
void quickSortHoare(int arr[], int low, int high) {
    if (low < high) {
        int pi = partirComHoarePadrao(arr, low, high);
        quickSortHoare(arr, low, pi);    // Note que a recursão vai até 'pi', não 'pi - 1'
        quickSortHoare(arr, pi + 1, high);
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = { 23, 32, 54, 92, 74, 23, 1, 43, 63 , 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;


    quickSortHoare(arr, 0, n - 1);

    cout << "Array ordenado : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
