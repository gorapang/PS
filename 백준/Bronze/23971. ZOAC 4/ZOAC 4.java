import java.util.*;

public class Main
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        int H = scan.nextInt();
        int W = scan.nextInt();
        int N = scan.nextInt();
        int M = scan.nextInt();

        int a = (W-1) / (M+1) +1;
        int b = (H-1) / (N+1) +1;
        System.out.println(a*b);
    }
}