#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
  
   // build heapify
  int largest = root; 
    int l = 2 * root + 1; 
    int r = 2 * root + 2; 
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != root) {
        swap(arr[root], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
  for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
   
  
   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
  srand(time(nullptr));
   
        for (int i = 0; i < 5; i++) {
           int length = rand() % 18 + 3 ; 
           int* arr = new int[length]; // Allocate memory for the array
        
        // Fill the array with random numbers between 0 and 99
        for (int j = 0; j < length; j++) {
            arr[j] = rand() % 100;
        }
          
        int heap_arr[length];
          // Copy the source array to the destination array
        for (int i = 0; i < length; i++) {
            heap_arr[i] = arr[i];
        }

          delete[] arr; 
          
   //int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   auto start_timei = high_resolution_clock::now();
  
   heapSort(heap_arr, n);
   auto end_timei = high_resolution_clock::now();
        auto durationi = duration_cast<nanoseconds>(end_timei - start_timei);
             
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
          cout<<"Total elements in heap sort array: "<<length<<endl;
        cout << "Time taken to heap sort the array: " << durationi.count() << " nanoseconds" << endl; 
          cout<<endl;
        }
}