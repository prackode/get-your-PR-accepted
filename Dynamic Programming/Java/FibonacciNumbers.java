//Java program to find the fibonacci number given a number 'n'
import java.util.Scanner;

public class FibonacciNumbers{
    //the method to find the fibonacci number given a number 'n'
    public int getFib(int n){
        //declaring an array of length n+1 to store fibonacci numbers
        int arr[] = new int[n+1];

        //0th fibonacci number is 0
        arr[0] = 0;

        //if n is not 0, then initializing 2nd element of the array with 1st fibonacci number which is 1
        //this is done to handle the case when n=0
        if(n!=0)
            arr[1] = 1;

        //calculating the nth fibonacci number
        for(int i=2; i<n+1; i++)
            //adding 2 previous fibonacci numbers and storing it at arr[i]
            arr[i] = arr[i-2] + arr[i-1];

        //returning the fibonacci number at 'n' as the result
        return arr[n];
    }

    public static void main(String [] args){
        //getting an integer as a user input and assigning it to the variable 'n'
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        //creating an object of the class to access the method 'getFib'
        FibonacciNumbers obj = new FibonacciNumbers();
        //printing the fibonacci number at 'n' as the output of the program
        System.out.println("\nFibonacci number at " + n + " = " + obj.getFib(n));
    }
}
