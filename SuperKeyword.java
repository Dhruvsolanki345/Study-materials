/******************************************************************************

In a bank, different customers having saving account. Some customers may have taken a loan from the bank.
So bank always maintains information about bank depositors and borrowers. Design a Base class 
Customer (name, phone-number).Derive a class Depositor (accno , balance) from Customer.
Again derive a class Borrower (loan-no, loan-amt) from Depositor. Write necessary member 
functions to read and display the details of ‘n’ customers.

*******************************************************************************/
import java.util.Scanner;
class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    String name, phone;
	    int accno, lno;
	    double balance, lamt;
	    
	    System.out.println("Enter the number of customers: ");
	    Borrower[] arr = new Borrower[sc.nextInt()];
	    for (int i =0; i < arr.length; i++){
	        System.out.println("Enter details of customer " + (i+1));
	        System.out.println("Name of customer: ");
	        sc.nextLine();
	        name = sc.nextLine();
	        System.out.println("Phone number: ");
	        phone = sc.nextLine();
	        System.out.println("Account number: ");
	        accno = sc.nextInt();
	        System.out.println("Balance : ");
	        balance = sc.nextDouble();
	        System.out.println("Loan number: ");
	        lno = sc.nextInt();
	        System.out.println("Loan amount : ");
	        lamt = sc.nextDouble();
	        arr[i] = new Borrower(name, phone, accno, balance, lno, lamt);
	    } 
	    System.out.println("\n\nPrinting details of all customers \n");
	    for(int i =0; i < arr.length; i++){
	        System.out.println("Detail of Customer " + (i+1));
	        arr[i].display();
	    }
	}
}

class Customer {
    String name, phone;
    Customer(String name, String phone){
        this.name = name;
        this.phone = phone;
    }
    void display(){
        System.out.println("\tName : " + name);
        System.out.println("\tPhone number : " + phone);
    }
}

class Depositor extends Customer {
    int accno;
    double balance;
    Depositor(String name, String phone, int accno, double balance){
        super(name,phone);
        this.accno = accno;
        this.balance = balance;
    }
    void display(){
        super.display();
        System.out.println("\tAccount number : " + accno);
        System.out.println("\tBalance : " + balance);

    }
}

class Borrower extends Depositor {
    int lno;
    double lamt;
    Borrower(String name, String phone, int accno, double balance, int lno, double lamt){
        super(name,phone,accno,balance);
        this.lno = lno;
        this.lamt = lamt;
    }
    void display(){
        super.display();
        System.out.println("\tLoan No. : " + lno);
        System.out.println("\tLoan amount : " + lamt);

    }
}

