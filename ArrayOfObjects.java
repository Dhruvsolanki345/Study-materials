/******************************************************************************
a) Write a program to accept two distance values in terms of kilometers and meters from the user and
calculate the resultant distance. Define input() to accept the distance value from user.
Define add () method to add the given two distances. Define sub() method to calculate the difference
between the given two distances. Define display() method to print the distance value in kilometers and meters.
Use these methods in main() appropriately. 

b) For part a) use array of objects to deal with the two input distance values and the resultant distance value  
*******************************************************************************/
import java.util.Scanner;
class Main
{
	public static void main(String[] args) {
	   /*
	   part a)
	    Distance d1	= new Distance(),
	            d2 = new Distance();
	   int choice = 0;
	   Scanner sc = new Scanner(System.in);
	   System.out.println("Enter the details of first distance");
	   d1.input();
	   d1.display();
	   System.out.println("Enter the details of second distance");
	   d2.input();
	   d2.display();
	   
	   System.out.println("Adding both distances");
	   Distance d3 = Distance.add(d1,d2);
	   d3.display();
	   
	   System.out.println("Subtracting both distances");
	   Distance d4 = Distance.sub(d1,d2);
	   d4.display();
	   
	   */
	   
	   //part b)
	   Distance d[] = new Distance[4];
	   for (int i = 0; i<2;i++ ) {
	       System.out.println("Enter details of distance " + (i+1));
	       d[i] = new Distance();
	       d[i].input();
	       d[i].display();
	   } 
	   System.out.println("Adding both distances");
	   d[2] = Distance.add(d[0], d[1]);
	   d[2].display();
	   
	    System.out.println("Subtracting both distances");
	    d[3] = Distance.sub(d[0],d[1]);
	    d[3].display();
	}
}

class Distance {
    int kilometers, meters;
    
    void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter distance in kilometer: ");
        kilometers = sc.nextInt();
        System.out.println("Enter distance in meter:  ");
        meters = sc.nextInt();
    }
    public static Distance add(Distance d1, Distance d2) {
        Distance d3 = new Distance();
        d3.meters = d1.meters + d2.meters;
        d3.kilometers = d1.kilometers + d2.kilometers;
        if (d3.meters >= 1000){
            d3.kilometers++;
            d3.meters -= 1000;
        }
        return d3;
    }
    public static Distance sub(Distance d1, Distance d2){
        int one,two,res;
        Distance d3 = new Distance();
        one = d1.kilometers*1000 + d1.meters;
        two = d2.kilometers*1000 + d2.meters;
        res = Math.abs(one - two);
        d3.kilometers = res / 1000;
        d3.meters = res % 1000;
        return d3;
    }
    void display(){
        System.out.println("Distance: " + kilometers + " km " + meters + " m");
    }
} 

