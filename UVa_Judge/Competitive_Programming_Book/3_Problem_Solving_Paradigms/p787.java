import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

/**
1 2 3 -999999
-5 -2 2 -30 -999999
-8 -999999
-1 0 -2 -999999
 */

public class p787 {
  public static void main(String[] arg) {
    Scanner in = new Scanner(System.in);
    ArrayList<Integer> list = new ArrayList<>();

    while (in.hasNext()) {
      int a = in.nextInt();

      if (a != -999999) {
        list.add(a);
      } else {
        BigInteger ans = new BigInteger("" + list.get(0));
        BigInteger p_ans = BigInteger.ONE;

        for (int i = 0; i < list.size(); i++) {
          p_ans = BigInteger.ONE;
          for (int j = i; j < list.size(); j++) {
            p_ans = p_ans.multiply(new BigInteger("" + list.get(j)));

            ans = ans.max(p_ans);
          }
        }

        System.out.println(ans);

        list.clear();
      }
    }
  }
}
