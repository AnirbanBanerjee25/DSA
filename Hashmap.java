import java.util.*;
public class Hashmap {
    public static void main(String args[])
    {
        HashMap<String, Integer> map=new HashMap<>();

        map.put("India",100);
        map.put("China",80);
        map.put("USA",50);

        System.out.println(map);
        map.put("USA",30);
        System.out.println("Updated: "+map);

        if(map.containsKey("USA"))
        {
            System.out.println("Key is present");
            System.out.println("Key value is:"+map.get("USA"));
        }
        else{
            System.out.println("Key is not present");
        }

        //Iteration in a hash map
        System.out.println("Map is: ");
        for(Map.Entry<String,Integer> e: map.entrySet())
                {
                    System.out.println(e.getKey());
                    System.out.println(e.getValue());
                }
        map.remove("China");
        System.out.println(map);
    }
}
