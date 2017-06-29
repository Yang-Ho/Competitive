import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class C
{
    public static void main(String[] args)
    {
        PriorityQueue<BigInteger> queue = new PriorityQueue<BigInteger>();
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T = in.nextInt();
        for (int i = 1; i <= T; i++) {
            BigInteger N = in.nextBigInteger();
            BigInteger K = in.nextBigInteger();
            BigInteger two = BigInteger.valueOf(2);
            BigInteger curr_max = N.divide(two);
            BigInteger curr_min = N.divide(two);
            if (curr_max.add(curr_min) == N) {
                if (curr_min == BigInteger.valueOf(0)) {
                    curr_min = curr_min.add(BigInteger.valueOf(-1));
                }
            }
            queue.add(curr_max);
            queue.add(curr_min);
            for (int j = 1; j < K.intValue(); j++) {
                BigInteger current = queue.poll();
                curr_max = current.divide(two);
                curr_min = current.divide(two);
                if (curr_max + curr_min == current) {
                    if (curr_min > 0) {
                        curr_min -= 1;
                    }
                }
                queue.add(curr_max);
                queue.add(curr_min);
            }

            System.out.print("Case #");
            System.out.print(i);
            System.out.print(": ");
            System.out.print(curr_max);
            System.out.print(" ");
            System.out.println(curr_min);
        }
    }
}
