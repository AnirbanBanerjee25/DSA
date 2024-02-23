import java.util.*;
public class Stack_push_atBottom {

    public static void pushatBottom(int d,Stack<Integer> s)
    {
        if(s.isEmpty())
        {
            s.push(d);
            return ;
        }
        int top=s.pop();
        pushatBottom(d,s);
        s.push(top);
    }

    public static void main(String args[])
    {
        Stack<Integer>  s=new Stack<>();

        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);

        pushatBottom(50,s);

        while(!s.isEmpty())
        {
            System.out.println(s.peek());
            s.pop();
        }

    }
}
