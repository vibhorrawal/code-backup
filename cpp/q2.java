import java.util.Scanner;
import java.util.Arrays;

class anagrom
{
	static boolean check(String s1, String s2)
	{
		s1=s1.replaceAll("\\s","");
		s2=s2.replaceAll("\\s","");
		
		s1=s1.toLowerCase();
		s2=s2.toLowerCase();
		
		char[] a= s1.toCharArray();
		char[] b= s2.toCharArray();
		
		Arrays.sort(a);
		Arrays.sort(b);
		
		s1=String.valueOf(a);
		s2=String.valueOf(b);
		
		return s1.equals(s2);
	}
	
	public static void main(String args[])
	{
		String s1, s2;
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter String 1:");
		s1=input.nextLine();
		
		System.out.print("Enter String 2:");
		s2=input.nextLine();
		
		if(check(s1,s2))
		{
			System.out.println("They are anagrams of each other");
		}
		else
		{
			System.out.println("They are NOT anagrams");
		}
	}
}