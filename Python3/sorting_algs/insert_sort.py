from typing import List

def insert_sort(arr: List[int]) -> List[int]:
    for j in range(1, len(arr)):                # starting from second element since a single element list is trivially sorted
        print("key: " + str(arr[j]))
        key = arr[j]                            # keeping track of current element 
        i = j - 1                               # index of prev element 
        while key < arr[i] and i >= 0:
             arr[i+1] = arr[i] 
             i -= 1
        arr[i+1] = key                          # every num till the index of the key is sorted 
        print("loop invariance in action: " + str(arr) + " till index " + str(j)) 

    return arr 


if __name__ == "__main__":     
    print(insert_sort([5,4,3,2,1]))

            