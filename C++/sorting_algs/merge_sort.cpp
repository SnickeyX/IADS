#include <iostream>

void merge(int arr[], int p, int q, int r) 
{
    int left_len  = q + 1 - p; 
    int right_len = r - q; 

    int left[left_len], right[right_len]; 

    // dividing sorted arrays 
    for(int i = 0; i < left_len; i++)
    {
        left[i] = arr[p + i]; 
    }

    for(int j = 0; j < right_len; j++)
    {
        right[j] = arr[q+j+1];
    }

    int i = 0, j = 0;               // not int i,j = 0 coz that only sets j to 0 :(  

    for(int k = p; k < (r+1); k++)
    {
        // first two cases take care of either list being completely iterated through
        if(i == left_len)
        {
            arr[k] = right[j]; 
            j++; 
        }
        else if(j == right_len) 
        {
            arr[k] = left[i];
            i++; 
        }
        // last two cases take the lowest value from the sorted left or sorted right list
        else if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++; 
        }
    } 
}

void merge_sort(int arr[], int p, int r)
{
    if(p < r)
    { 
        int q = (p + r) / 2; 
        merge_sort(arr, p, q); 
        merge_sort(arr, q+1, r); 
        merge(arr, p, q, r); 
    }
}


int main() 
{
    // example array
    int arr[] = {2,1,0,5,10,11,9,3,4};
    int arr_len = sizeof(arr) / sizeof(arr[0]); 

    merge_sort(arr, 0, arr_len-1);  

    bool first = true; 

    for (int i : arr)
    {
        std::cout << (first ? "Sorted Array: " : ", ") << i;
        first = false;
    }

    return 0; 
}