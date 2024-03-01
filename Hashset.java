import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.LinkedList;

public class Hashset {
    public static void main(String args[])
    {
        //LinkedHashSet<Integer> h=new LinkedHashSet<>();//To store elements in the order of their insertion

        HashSet<Integer> h=new HashSet<>();

        h.add(10);
        h.add(20);
        h.add(30);
        h.add(10);//duplicates not allowed
        System.out.println("Size of the set is: "+h.size());


        System.out.println(h);

        if(h.contains(10)){
            System.out.println("Contains 10");
        }

        h.remove(10);
        if(!h.contains(10)){
            System.out.println("Does not contain 10");
        }

        Iterator it=h.iterator();
        while(it.hasNext())
        {
            System.out.println(it.next()+" ");
        }

    }
}
