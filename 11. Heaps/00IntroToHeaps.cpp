#include <bits/stdc++.h>
using namespace std;
// Heap --> Complete BT, comes with heap order property
// Complete BT --> every level is completely filled except the last one & nodes always added from the left
// Heap Order Property-- > Max.Heap(parent > child) & Min.Heap(parent < child)

// Node --> (i)th index
// Left Child --> (2*i)th index
// Right Child --> (2*i+1)th index
// Parent Node --> (i/2)th index
// Leaf Nodes --> (n/2 +1)th to (n)th index

// *** Insertion of Node in a Heap ***
// 1. insert the node at the end of an array
// 2. take it to the right position
// 3. compare with the parent node (parent > child) & swap

// *** Deletion of Root Node in a Heap ***
// 1. put the value of last node in the first node
// 2. remove the last node (which was initially the root node)
// 3. propagate root node in its correct position

// *** Heapify Algorithm ***
// arr --> convert into heap
// leaf nodes are themselves a heap
// thus, no need to process the leaf nodes
// therefore, we'll process from (n/2)th to 0th index

class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insertHeap(int val) // T.C --> O(log(N))
    {
        // 1. insert at end of array
        size++;
        int index = size;
        arr[index] = val;

        // 2. take it to right postion
        while (index > 1)
        {
            int parent = index / 2;
            // 3. compare with parent
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteHeap() // T.C --> O(log(N))
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        // 1. put last ndoe in first node
        arr[1] = arr[size];

        // 2. remove the last node
        size--;

        // 3. take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (arr[i] < arr[leftIndex] && leftIndex < size)
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (arr[i] < arr[rightIndex] && rightIndex < size)
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int size, int i) // T.C --> O(log(N))
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && arr[largest] < arr[left])
    {
        // swap(arr[largest], arr[left]);
        largest = left;
    }

    if (right <= size && arr[largest] < arr[right])
    {
        // swap(arr[largest], arr[right]);
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void HeapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    // Heap h;
    // h.insertHeap(40);
    // h.insertHeap(30);
    // h.insertHeap(23);
    // h.insertHeap(54);
    // h.deleteHeap();
    // h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the heapified array: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    HeapSort(arr, n);

    cout << "Printing the sorted array: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}