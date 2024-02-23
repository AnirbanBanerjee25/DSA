
public class Stack_Linked_List {
    public static class Node{
        int data;
        Node next;
        Node(int d)
        {
            data=d;
            next=null;
        }
    }
    public static class Stack{
        public Node head=null;
        public boolean isEmpty()
        {
            return head==null;
        }
        public void push(int d)
        {
            Node newNode=new Node(d);
            if(head==null)
            {
                head=newNode;
                return;
            }
            newNode.next=head;
            head=newNode;
        }
        public int pop()
        {
            if(isEmpty()){
                return -1;
            }
            Node top=head;
            head=head.next;
            return top.data;
        }
        public int peek()
        {
            if(isEmpty())
            {
                return -1;
            }
            Node top=head;
            return top.data;
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
