#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int largest = root;  
   int left = 2*root + 1;  
   int right = 2*root + 2; 
 
   if (left < n && arr[left] > arr[largest])
       largest = left;
   
   if (right < n && arr[right] > arr[largest])
       largest = right;
 
   if (largest != root){
       
      swap(arr[root], arr[largest]);
      heapify(arr, n, largest);
   }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   for (int i = n / 2 - 1; i >= 0; i--)
       heapify(arr, n, i);
  
   //taking elements from heap one by one
   for (int i=n-1; i>=0; i--)
   {
       swap(arr[0], arr[i]);
       heapify(arr, i, 0);  //call max heap
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
   int i,num = 0;
   int size;
   cout << "Enter the size of the array : ";
   cin >> size; 
   int heap_arr[size];
   //int heap_arr[] = {4,17,3,12,9,6,5};
   
   while (i < size) {
        cout << "Enter the " << i+1 << " element: " ;
        cin >> num;
        heap_arr[i] = num;
        i++;
   }

   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}