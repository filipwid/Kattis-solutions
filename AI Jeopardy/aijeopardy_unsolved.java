import java.util.Scanner;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.math.RoundingMode;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger target = sc.nextBigInteger();        

        BigInteger bestN = BigInteger.TEN.pow(100);
        BigInteger bestK = BigInteger.ONE;

        for (BigInteger k = BigInteger.ONE; k.compareTo(BigInteger.valueOf(170)) <= 0; k=k.add(BigInteger.ONE)) {
            if (target.equals(BigInteger.ONE)) {
                bestN = BigInteger.ZERO;
                bestK = BigInteger.ZERO;
                break;
            }

            if (comb(k.multiply(BigInteger.valueOf(2)), k).compareTo(target) == 1) {
                break;
            }

            BigInteger upper = k.multiply(BigInteger.valueOf(2));
            while (comb(upper, k).compareTo(target) == -1) {
                upper = upper.multiply(BigInteger.valueOf(2));
            }

            BigDecimal lowerDecimal = new BigDecimal(upper).divide(BigDecimal.valueOf(2), 0, RoundingMode.HALF_UP);
            BigInteger lower = lowerDecimal.toBigInteger();
            while (upper.compareTo(lower) >= 0) {
                BigDecimal mid = new BigDecimal(upper.add(lower)).divide(BigDecimal.valueOf(2), 0, RoundingMode.HALF_UP);
                BigInteger temp = comb(mid.toBigInteger(), k);

                int compare = temp.compareTo(target);
                if (compare == 0) {
                    if (mid.toBigInteger().compareTo(bestN) == -1) {
                        bestN = mid.toBigInteger();
                        bestK = k;
                    }
                    break;
                }
                else if (compare == 1) {
                    upper = mid.toBigInteger().subtract(BigInteger.ONE);
                }
                else if (compare == -1) {
                    lower = mid.toBigInteger().add(BigInteger.ONE);
                }
            }

        }

        System.out.printf("%s %s\n", bestN.toString(), bestK.toString());
    }


    static BigInteger comb(BigInteger n, BigInteger r) {   
          return fact(n).divide((fact(r).multiply(fact(n.subtract(r)))));   
    }   
    
    //Method to calculate the factorial of the number
    static BigInteger fact(BigInteger n) {   
        BigInteger res =  BigInteger.valueOf(1);   
        for (BigInteger i = BigInteger.valueOf(2); n.compareTo(i) >= 0; i = i.add(BigInteger.ONE)) {  
            res = res.multiply(i);
        }   
        return res;   
    }   
}
