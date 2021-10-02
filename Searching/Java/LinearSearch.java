class LinearSearchClass{

    //Example of the linear search algo with the return index by given element in array of any types
    static int linearSearch(Object arr[], Object elementToSearch) {
    
        for (int index = 0; index < arr.length; index++) { //Scan step by step the array

            if (arr[index] == elementToSearch) //When element is found return its index
                return index;

        }
        return -1; //If the element is not found return -1
    }

    public static void main(String[] args) {

        //Array to give to linear search method
        String words[] = {"Hello", "World", "!", "Hacktoberfest"};
        
        //Search the index
        int index = linearSearch(words, "Hacktoberfest");

        //Print the index of the element
        System.out.println("Element index is: " + index);
    }
    
}