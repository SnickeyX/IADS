#include <iostream>

void insert_sort(int input_arr[], int arr_len) 
{    
    for (int j = 1; j < arr_len; j++) 
    {
        // current value is remembered
        int key = input_arr[j];     
        int i = j - 1; 
        
        // swap prev value with current value in loop for as long as it is greater
        while(key < input_arr[i] && i >= 0)
        {
            input_arr[i + 1] = input_arr[i];
            i--;   
        } 

        // finally put the key value in the array where it is greater than the num to its left
        input_arr[i + 1] = key; 
    }
}

int main()
{
    // example array
    int arr[] = {2,1,0,5,10,11,9,3,4};
    int arr_len = sizeof(arr) / sizeof(int); 

    insert_sort(arr, arr_len);  

    bool first = true; 

     for (int i : arr)
    {
        std::cout << (first ? "Sorted Array: " : ", ") << i;
        first = false;
    }

    return 0; 
}

