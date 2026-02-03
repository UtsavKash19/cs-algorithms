#include<bits/stdc++.h>
using namespace std;
// Bubble sort performs the swapping of adjacent pairs without the use of any major data structure. 
// Hence Bubble sort algorithm is an in-place algorithm.
// Bubble sort is stable
// It is adaptable to different data types, it will also work for String, Float data types.

void bubble(int arr[], int n){
    // for (int i = 0; i < n-1; i++)
    for (int i = 1; i < n; i++) // for round 1 to n-1
    {
        for (int j = 0; j < n-1; j++){
            if (arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
            } 
            
        }
        
    }
}

// more optimized
void bubble(int arr[], int n){
    // for (int i = 0; i < n-1; i++) for this j is from 0 to n-i-1
    for (int i = 1; i < n; i++) // for round 1 to n-1
    {
        bool swapped = false;
        for (int j = 0; j < n-i; j++){
        // for (int j = 0; j < n-i-1; j++){
            // process element till n-i th index
            if (arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
                swapped = true;
            }
            
        }
        if (swapped == false)
        {
            // already sorted
            break;
        }
        
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {    
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int even[] = {25,45,35,67,2,4};
    int odd[] = {45,35,67,2,4};
    printArray(even,6);
    printArray(odd,5);
    bubble(even,6);
    printArray(even,6);
    bubble(odd,5);
    printArray(odd,5);
    return 0;
}
