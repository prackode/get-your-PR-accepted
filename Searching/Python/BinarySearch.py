# Python Program for recursive binary search.
  
# Returns index of x in arr if present, else -1
def binarySearch (arr, l, r, x):
  
    # Check base case
    if r >= l:
  
        mid = l + (r - l) // 2
  
        # If element is present at the middle itself
        if arr[mid] == x:
            return mid
          
        # If element is smaller than mid, then it 
        # can only be present in left subarray
        elif arr[mid] > x:
            return binarySearch(arr, l, mid-1, x)
  
        # Else the element can only be present 
        # in right subarray
        else:
            return binarySearch(arr, mid + 1, r, x)
  
    else:
        # Element is not present in the array
        return -1
  
# Driver Code
arr = []
n=int(input("Enter length of array"))
print("Enter the elements")
for i in range(n):
	y=int(input())
	arr.append(y)
x = int(input("Enter number to search."))
  
# Function call
result = binarySearch(arr, 0, n-1, x)
  
if result != -1:
    print ("Element is present at index % d" % result)
else:
    print ("Element is not present in array")