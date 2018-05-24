import java.util.*;
import java.math.*;
import java.lang.*;
class Main{
	public static void main(String[] args)
	{	
		Scanner scan = new Scanner(System.in);
		while(scan.hasNext())
		{
				BigDecimal a = scan.nextBigDecimal();
				int b = scan.nextInt();
				BigDecimal c;
				c = a.pow(b);
				String s = c.toPlainString();
				int len = s.length();
				String res = "";
				int j = 0;
				int i = len - 1;
				while(s.charAt(j) == '0')
				{
					j++;
				}
				if(s.charAt(len-1)=='0')
				{
						
						while(s.charAt(i)=='0')
						{
								i --;
						}
						
				}
				for(;j<=i;j++)
					System.out.print(s.charAt(j));
				System.out.println("");
		}
	}
	
} 
