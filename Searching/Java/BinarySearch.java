package Searching.Java;

public class BinarySearch {
    public static void main(String[] args){
        int[] arr = {1,2,4,6,8,9,22,77};
        System.out.println(BinarySearchAlgoritm(arr,22));
    }
    public static int BinarySearchAlgoritm(int[] arr,int target){
        // arr is already sorted array in ascending order;
        int start = 0; 
        int end = arr.length - 1;
        while(start <= end){
            // find middle element in each iteration
            int mid = (start+end)/2; 

            if(target > arr[mid]){ 
                //if target element is greater than the element at the middle than the target must be in right side of mid
                //change the value of start to mid + 1 to search in right part of sorted(ascending) array
                start = mid + 1; 
            } else if(target<arr[mid]){
                //if target element is smaller than the element at mid then the target must lie before the middle element 
                //so we search in the left part of array
                //change the value of end to mid-1;
                end = mid-1;
            } else {
                //target is equal to middle element ie. target == arr[mid]
                //we return the index of middle element which is also equal to the index of target element
                return mid;
            }
        }
        //if we don't find the index of target element we return -1
        return -1;
    }
}
