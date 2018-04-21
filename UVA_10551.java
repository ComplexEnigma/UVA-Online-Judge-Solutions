import java.math.BigInteger;
import java.util.Scanner;

class Main{

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        BigInteger base , number, mod;
        while( scan.hasNext() )
        {
            base = scan.nextBigInteger();
            if( base.toString().equals("0"))
                break;
            number = scan.nextBigInteger();
            mod = scan.nextBigInteger();
            if( base.toString().equals("10"))
            {
                System.out.println(number.mod(mod));
            }
            else
            {
                Solution ob = new Solution();
                BigInteger num , m;
                num = ob.toDEC( number, base);
               // System.out.println( num );
                m = ob.toDEC( mod, base );
               // System.out.println( m );
                num = num.mod(m);
                num = ob.toBase( num, base);
                System.out.println( num );
            }
        }
    }
    
}

class Solution{
    BigInteger toDEC(BigInteger a, BigInteger b)
    {
        BigInteger res = new BigInteger("0");
        String s = a.toString();
        int len = s.length();
        int j = len-1;
        for( int i=0;i<len;i++)
        {
            String temp = s.substring(i, i+1);
            BigInteger c = new BigInteger(temp);
            // System.out.println(c);
            res = res.add(c.multiply(b.pow(j)));
            j--;
        }
        return res;
    }
    BigInteger toBase( BigInteger a, BigInteger b)
    {
        BigInteger res;
        String s = new String();
        if( a.toString().equals("0"))
        {
            s = "0";
        }
        while( !a.toString().equals("0") )
        {
            s += a.mod(b).toString();
            a = a.divide(b);
        }
        s = new StringBuilder(s).reverse().toString();
        res = new BigInteger(s);
        return res;
    }
}
