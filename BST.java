import java.util.*;
public class BST {
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int d)
        {
            this.data=d;
        }
    }
    public static Node insert(Node root,int val)
    {
        if(root==null)
        {
            root=new Node(val);
            return root;
        }
        if(val< root.data)
        {
            //left subtree
            root.left=insert(root.left,val);
        }
        else if(val> root.data)
        {
            //right subtree
            root.right=insert(root.right,val);
        }
        return root;
    }
    public static void inorder(Node root)
    {
        if(root==null)
        {
            return;
        }
        inorder(root.left);
        System.out.print(root.data+" ");
        inorder(root.right);
    }
    public static boolean search(Node root,int key)
    {
        if(root==null)
        {
            return false;
        }
        if(key<root.data)
        {
            return search(root.left,key);
        }
        else if(key> root.data)
        {
            return search(root.right,key);
        }
        else {
            return true;
        }
    }
    public static Node delete(Node root,int val)
    {
        //First find where the node is which we want to delete.
        if(root==null)
        {
            return root;
        }
        if(val< root.data)
        {
            root.left=delete(root.left,val);
        }
        else if(val> root.data)
        {
            root.right=delete(root.right,val);
        }
        else{
            //val==root.data
            //Code to handle what value is to be replaced in place of the deleted node.

            //Case 1
            if(root.left==null && root.right==null)
            {
                return null;
            }

            //Case 2
            else if(root.left==null)
            {
                return root.right;
            }
            else if(root.right==null)
            {
                return root.left;
            }

            //Case 3
            Node IS=inordersuccessor(root.right);
            root.data=IS.data;
            root.right=delete(root.right,IS.data);
        }
        return root;
    }
    public static Node inordersuccessor(Node root){
        while(root.left!=null)
        {
            root=root.left;
        }
        return root;
    }

    public static void printInRange(Node root,int x,int y)
    {
        if(root==null)
        {
            return;
        }
        if(root.data>=x && root.data<=y)
        {
            printInRange(root.left,x,y);
            System.out.print(root.data+" ");
            printInRange(root.right,x,y);
        }
        else if(root.data>=y)
        {
            printInRange(root.left,x,y);
        }
        else{
            printInRange(root.right,x,y);
        }
    }
    public static void printPath(ArrayList<Integer> path)
    {
        for (int i = 0; i < path.size(); i++) {
            System.out.print(path.get(i));
            if (i != path.size() - 1) {
                System.out.print("-");
            }
        }
        System.out.println();
    }
    public static void printroot2leaf(Node root,ArrayList<Integer> path)
    {
        if(root==null)
        {
            return;
        }
        path.add(root.data);

        //if a leaf node
        if(root.left==null && root.right==null)
        {
            printPath(path);
        }
        else {
            printroot2leaf(root.left, path);
            printroot2leaf(root.right, path);
        }
        path.remove(path.size()-1);
    }
    public static void main(String args[])
    {
        Node root=null;
        int nodes[]={8,5,3,6,10,11,14};
        for(int i=0;i<nodes.length;i++)
        {
            root=insert(root,nodes[i]);
        }
        System.out.println("Inorder traversal is: ");
        inorder(root);
        boolean answer;
        answer=search(root,3);
        System.out.println();
        System.out.println("Search result is: "+answer);

        delete(root,5);
        System.out.println("Tree after deletion is: ");
        inorder(root);

        System.out.println();
        System.out.println("The nodes in the range are: ");
        printInRange(root,6,10);

        System.out.println();
        System.out.println("The paths are: ");
        printroot2leaf(root,new ArrayList<>());
    }
}
