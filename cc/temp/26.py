def moveZerosToEnd(arr, n):
    count = 0
    for i in range(n):
        if (arr[i] != 0):
            arr[i], arr[count] = arr[count], arr[i]
            count = count + 1

def printArray(arr, n):
    for i in range(0, n):
        print(arr[i],end=" ")

# if __name__ == '__main__':
arr = [ 0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9 ]
n = len(arr)

print("Original array:", end=" ")
printArray(arr, n)

moveZerosToEnd(arr, n)

print("\nModified array: ", end=" ")
printArray(arr, n)
