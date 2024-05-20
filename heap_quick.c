#include <stdio.h>
#include <stdlib.h>

void swap(float *a, float *b) 
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(float A[], int i, int heap_size) 
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest;

    if (l <= heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i) 
    {
        swap(&A[i], &A[largest]);
        MaxHeapify(A, largest, heap_size);
    }
}

void Build_MaxHeap(float A[], int length) 
{
    int heap_size = length - 1;
    for (int i = length / 2 - 1; i >= 0; i--)
        MaxHeapify(A, i, heap_size);
}

void Heap_Sort(float A[], int length) 
{
    int heap_size = length - 1;
    Build_MaxHeap(A, length);
    for (int i = length - 1; i >= 1; i--) 
    {
        swap(&A[0], &A[i]);
        heap_size--;
        MaxHeapify(A, 0, heap_size);
    }
}
// Heap Sort Algorithum Ends

void Quick_Sort(float a[], int m, int n) 
{
    if (m < n) 
    {
        int i = m;
        int j = n + 1;
        float key = a[m];
        while (1) 
        {
            do 
            {
                i++;
            } 
            while (a[i] < key);
            do 
            {
                j--;
            } 
            while (a[j] > key);
            if (i < j) 
            {
                swap(&a[i], &a[j]);
            } 
            else 
            {
                break;
            }
        }
        swap(&a[m], &a[j]);
        Quick_Sort(a, m, j - 1);
        Quick_Sort(a, j + 1, n);
    }
}

void Print_Sorted_Array(float a[], int n)
{
    printf("Sorted Array in Ascending Order: ");
    for (int i = 0; i < n; i++) 
        printf("%.2f ", a[i]);
        
    printf("\n");
}

int main() 
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    float a[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);
        
    int choice = 0;  
    while (choice != 3)   
    {
        printf("\nChoose from the menu : \n1. Heap Sort\n2. Quick Sort\n3. Exit.\n");
        printf("Enter Your Choice - ");
        scanf("%d", &choice);  
        switch(choice)  
        {  
            case 1:  
                Heap_Sort(a, n);
                Print_Sorted_Array(a, n);         
                break;  
            case 2:  
                Quick_Sort(a, 0, n - 1);  
                Print_Sorted_Array(a, n);   
                break;  
            case 3:
                printf("\nProgram Ended.\n");
                exit(0);
                break;  
            default:  
                printf("Please Enter A Valid Choice!\n");  
        }
    }
}
