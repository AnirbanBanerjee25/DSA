import java.util.*;
public class Stack_ArrayList {
    static class Stack{
        ArrayList<Integer> stack=new ArrayList<>();
        public void push(int d)
        {
            stack.add(d);
        }
        public boolean isEmpty()
        {
            return stack.size()==0;
        }
        public int pop()
        {
            if(isEmpty())
            {
                return -1;
            }
            int top=stack.get(stack.size()-1);
            stack.remove(stack.size()-1);
            return top;
        }
        public int peek()
        {
            if(isEmpty())
            {
                return -1;
            }
            int top=stack.get(stack.size()-1);
            return top;

        }

    }
    public static void main(String args[])
    {
        Stack ob=new Stack();
        ob.push(1);
        ob.push(2);
        ob.push(3);
        ob.push(4);
        while(!ob.isEmpty())
        {
            System.out.println(ob.peek());
            ob.pop();
        }

    }
}
