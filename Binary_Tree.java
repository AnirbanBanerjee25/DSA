import java.util.*;
public class Binary_Tree {
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int d)
        {
            this.data=d;
            this.left=null;
            this.right=null;
        }
    }
    static class binarytree{
        int index=-1;
        Node buildtree(int nodes[])
        {
            index++;
            if(nodes[index]==-1)
            {
                return null;
            }

            Node newnode=new Node(nodes[index]);
            newnode.left=buildtree(nodes);
            newnode.right=buildtree(nodes);
            return newnode;
        }

    }

    public static void preorder(Node root)
    {
        if(root==null)
        {
            return;
        }
        System.out.print(root.data+" ");
        preorder(root.left);
        preorder(root.right);
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
    public static void levelorder(Node root)
    {
        Queue<Node> q=new LinkedList<>();
        q.add(root);
        q.add(null);

        while(!q.isEmpty())
        {
            Node current=q.remove();
            if(current==null)
            {
                System.out.println();
                if(q.isEmpty())
                {
                    break;
                }
                else{
                    q.add(null);
                }
            }
            else{
                System.out.print(current.data+" ");
                if(current.left!=null)
                {
                    q.add(current.left);
                }
                if(current.right!=null)
                {
                    q.add(current.right);
                }
            }
        }
    }
    public static void postorder(Node root)
    {
        if(root==null)
        {
            return;
        }
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data+" ");
    }
    public static int sum(Node root)
    {
        if(root==null)
        {
            return 0;
        }

        int leftsum=sum(root.left);
        int rightsum=sum(root.right);

        return leftsum+rightsum+ root.data;
    }
    public static int count(Node root)
    {
        if(root==null)
        {
            return 0;
        }

        int left=count(root.left);
        int right=count(root.right);

        return left+right+1;
    }
    public static int height(Node root)
    {
        if(root==null)
        {
            return 0;
        }

        int left=height(root.left);
        int right=height(root.right);

        int height=Math.max(left,right)+1;
        return height;
    }
    public static int diameter(Node root)
    {
        if(root==null)
        {
            return 0;
        }
        int dia1=diameter(root.left);
        int dia2=diameter(root.right);
        int dia3=height(root.left) + height(root.right) + 1;

        return Math.max(dia3,Math.max(dia1,dia2));
    }

    public static void main(String args[])
    {
        int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

        binarytree tree=new binarytree();
        Node root=tree.buildtree(nodes);
        System.out.println("Preorder traversal is: ");
        preorder(root);
        System.out.println();
        System.out.println("Inorder traversal is: ");
        inorder(root);
        System.out.println();
        System.out.println("Postorder traversal is: ");
        postorder(root);
        System.out.println();
        System.out.println("Level order traversal is:");
        levelorder(root);

        int c=count(root);
        System.out.println("Number of nodes: "+c);

        int s=sum(root);
        System.out.println("Sum of nodes: "+s);

        int h=height(root);
        System.out.println("Height of the tree is: "+h);

        int d=diameter(root);
        System.out.println("Diameter of the tree is: "+d);

    }
}
