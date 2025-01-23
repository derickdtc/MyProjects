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
int partirComLomutoAleatorio(int arr[], int first , int last){
    int n = last - first + 1;
    int random = arr[first + abs(arr[first] % n)];
    // Swap A[random] with A[high]
    swap(arr[random], arr[last]);
 
    return partirComLomutoPadrao(arr, first, last);
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
int partirComHoareAleatorio(int arr[], int first, int last) {
   // Generate a random number in between
    // low .. high
    int n = last - first + 1;
    int random = arr[first + abs(arr[first]) % n];
 
    // Swap A[random] with A[high]
    swap(arr[random], arr[first]);
 
    return partirComHoarePadrao(arr, first, last);
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

void quickSortLomutoPadrao(int arr[] , int first , int last){
    if (first < last)
    {
        int pivotIndexAfterPartir = partirComLomutoPadrao(arr , first , last);
        quickSortLomutoPadrao(arr , first , pivotIndexAfterPartir - 1);
        quickSortLomutoPadrao(arr , pivotIndexAfterPartir + 1 , last);
    }
    
}
void quickSortLomutoAleatorio(int arr[] , int first , int last){
    if (first < last)
    {
        int pivotIndexAfterPartir = partirComLomutoAleatorio(arr , first , last);
        quickSortLomutoAleatorio(arr , first , pivotIndexAfterPartir - 1);
        quickSortLomutoAleatorio(arr , pivotIndexAfterPartir + 1 , last);
    }
    
}
void quickSortHoarePadrao(int arr[], int low, int high) {
    if (low < high) {
        int pi = partirComHoareAleatorio(arr, low, high);
        quickSortHoarePadrao(arr, low, pi);    // Note que a recursão vai até 'pi', não 'pi - 1'
        quickSortHoarePadrao(arr, pi + 1, high);
    }
}
void quickSortHoareAleatorio(int arr[], int low, int high) {
    if (low < high) {
        int pi = partirComHoareAleatorio(arr, low, high);
        quickSortHoareAleatorio(arr, low, pi);    // Note que a recursão vai até 'pi', não 'pi - 1'
        quickSortHoareAleatorio(arr, pi + 1, high);
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


    quickSortHoareAleatorio(arr, 0, n - 1);

    cout << "Array ordenado : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
