from typing import List

def merge(arr : List[int], p : int, q : int, r : int):  # p, q r are index positions 
    left_len  = q + 1 - p 
    right_len = r - q 

    left  = []
    right = []

    for i in range(left_len):
        left.append(arr[p+i])                           # left list contains everything from [p:q]
    for j in range(right_len):                                      
        right.append(arr[q + j + 1])                    # right list contains everything from (q:r] 

    i = j = 0
    for k in range(p, r + 1):
        # first two cases take care of either list being completely iterated through
        if(i == left_len):
            arr[k] = right[j]
            j += 1 
        elif(j == right_len):
            arr[k] = left[i]
            i += 1 
        # last two cases take the lowest value from the sorted left or sorted right list
        elif(left[i] <= right[j]):
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1

def merge_sort(arr : List[int], p : int, r: int) -> List[int]:
    # testing for base case where there is only one element in the list 
    if(r <= p):
        return arr                  

    q = (p + r) // 2
    merge_sort(arr, p, q)
    merge_sort(arr, q+1, r)
    merge(arr, p, q , r)

if __name__ == "__main__":
    example_arr = [7,6,5,4,3,2,1] 
    merge_sort(example_arr, 0, len(example_arr) - 1)
    print(example_arr)