import java.util.*;
public class LL_Collections {
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        LinkedList<String> ll=new LinkedList<>();

        System.out.println("Enter elements in the linked list: ");
        for(int i=0;i<5;i++)
        {
            String s=in.next();
            ll.add(s);
        }
        System.out.println("List is: ");
        System.out.println(ll);
        ll.addLast("!!!!");
        ll.addFirst("Hello");
        System.out.println("List is: ");
        System.out.println(ll);

        ll.set(4,"bad");
        System.out.println("List is: ");
        System.out.println(ll);

        ll.add(0,"Hi!");
        ll.remove(6);
        System.out.println("List is: ");
        System.out.println(ll);

        Collections.sort(ll);
        System.out.println("Sorted List is: ");
        System.out.println(ll);

        ll.removeLast();
        ll.removeFirst();
        System.out.println("List is: ");
        System.out.println(ll);
    }
}
