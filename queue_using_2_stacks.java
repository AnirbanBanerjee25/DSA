import java.util.*;
public class queue_using_2_stacks {
    public static class queue{
        Stack<Integer> s1=new Stack<>();
        Stack<Integer> s2=new Stack<>();

        boolean isEmpty()
        {
            return s1.isEmpty();
        }
        void add(int d)
        {
            while(!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
            s1.push(d);
            while(!s2.isEmpty())
            {
                s1.push(s2.pop());
            }
        }
        int remove()
        {
            return s1.pop();
        }
        int peek()
        {
            return s1.peek();
        }
    }
    public static void main(String args[])
    {
        queue q=new queue();
        q.add(10);
        q.add(20);
        q.add(30);
        q.add(40);
        q.add(50);

        while(!q.isEmpty())
        {
            System.out.println(q.peek());
            q.remove();
        }
    }
}
