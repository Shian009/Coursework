import java.util.*;
public class Rev{
	public static void rev(String a,int i)
	{
		if(i<0 || a.charAt(i)=='\0')
			return;
		else
			rev(a,i+1);
			System.out.print(a.charAt(i));
	}

	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		String s=new String();
		s=sc.next();
		s=s+'\0';
		rev(s,0);
		System.out.println();
		return;
	}
}