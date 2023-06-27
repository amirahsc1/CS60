#include <iostream>
# include <string>
# include <cmath>
using namespace std;
void max (int arr[], int size){
  //size = sizeof(arr) / sizeof(arr[0]);
  int currentLarge = 0;
  int currentLarge2 = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > currentLarge) {
        currentLarge = arr[i];
        }
    }
    // return currentLarge;
  }
void swap (int arr[], int size){
  //size = sizeof(arr) / sizeof(arr[0]);
  int currentLarge = 0;
  int currentLargeindex = 0;
  int lastpostion = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > currentLarge) {
        currentLarge = arr[i];
        currentLargeindex = i;
        }
    }
    lastpostion = arr[size -1];
     arr[currentLargeindex] = lastpostion;
     arr[size - 1] = currentLarge;
    }

void printArr(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swapagain (int arr[], int size){
  //size = sizeof(arr) / sizeof(arr[0]);
  int currentLarge = 0;
  int currentLargeindex = 0;
  int currentLarge2 = 0;
  int currentLargeindex2 = 0;
  int lastpostion = 0;
   int lastpostion2 = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > currentLarge) {
        currentLarge = arr[i];
        currentLargeindex = i;
        }
    }
 for (int i = 0; i < size; i++){
    if (arr[i] > currentLarge2 && arr[i] < currentLarge){
        currentLarge2 = arr[i];
        currentLargeindex2 = i;
    }
 }
    lastpostion = arr[size - 1];
    arr[currentLargeindex] = lastpostion;
    arr[size - 1] = currentLarge;
    lastpostion2 = arr[size - 2];
    arr[currentLargeindex2] = lastpostion2;
    arr[size - 2] = currentLarge2;
    }

int main() {
int array[] = {2, 9, 4, 8, 7, 6};
int size = sizeof(array) / sizeof(array[0]);
// cout << max(array, size) << endl;
swapagain(array, size);
printArr(array,6);

}