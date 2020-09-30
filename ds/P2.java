import java.util.Scanner;
class P2
{
	public static double power(double m,int n)
	{
		if(n==0)
			return 1.0;
		if(n<0)
			return ((1.0/m)*power(m,n+1));
		else
			return (m*power(m,n-1));
	}

	public static void main(String []args)
	{
		
		Scanner sc=new Scanner(System.in);
		System.out.println("\n Enter the base: ");
		double m=sc.nextDouble();
		System.out.println("\nEnter the no. for power: ");
		int n=sc.nextInt();
		double res=power(m,n);
		System.out.println("result is: "+res);

	}
}