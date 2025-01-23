#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void heapify(vector<int> &arr, int i, int n) 
{
    int left_node_index = 2*i + 1;
    int right_node_index = 2*i + 2;
    if (right_node_index < n)
    {
        if (arr[right_node_index] > arr[i])
        {
            swap(arr[right_node_index], arr[i]);
        }
    }
    if (left_node_index < n) {
        if (arr[left_node_index] > arr[i])
        {
            swap(arr[left_node_index], arr[i]);
        }
    }
}
void rebuild_heap_from_top(vector<int> &arr, int i, int n)
{
    int left_node_index = 2*i + 1;
    int right_node_index = 2*i + 2;
    int left_node_val = NULL, right_node_val = NULL;

    if (right_node_index < n) {
        if (arr[right_node_index] > arr[left_node_index]) {
            if (arr[right_node_index] > arr[i])
            {
                swap(arr[right_node_index], arr[i]);
                rebuild_heap_from_top(arr, right_node_index, n);
            }
        } else {
            if (arr[left_node_index] > arr[i]) {
                swap(arr[left_node_index], arr[i]);
                rebuild_heap_from_top(arr, left_node_index, n);
            }
        }
    } else if (left_node_index < n) {
        if (arr[left_node_index] > arr[i])
        {
            swap(arr[left_node_index], arr[i]);
            rebuild_heap_from_top(arr, left_node_index, n);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = n-1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }

    int heap_limit = n-1;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[0];
        arr[0] = arr[heap_limit];
        rebuild_heap_from_top(arr, 0, heap_limit);
        arr[heap_limit] = temp;
        heap_limit--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
    
    
    return 0;
}