package org.example;
import java.util.*;
public class ArrayLists {
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        ArrayList<Integer> arr=new ArrayList<>();
        System.out.println("Enter elements in the arraylist: ");
        for(int i=0;i<6;i++)
        {
            int d=in.nextInt();
            arr.add(d);
        }
        System.out.println("List is: ");
        for(int j=0;j<6;j++)
        {
            System.out.print(arr.get(j)+" ");
        }
        System.out.println();
        arr.add(0,0);
        arr.add(1,77);
        arr.set(7,7);
        arr.remove(3);
        System.out.println("Modified list is: ");
        System.out.println(arr);
        System.out.println("Sorted List is: ");
        Collections.sort(arr);
        System.out.println(arr);
        System.out.println("Size of array list is: ");
        System.out.println(arr.size());
    }
}
