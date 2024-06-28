import java.util.*;

public class Main
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        String[] arr = new String[N];

        scan.nextLine();

        for (int i=0;i<N;i++)
        {
            arr[i] = scan.nextLine();
        }


        Arrays.sort(arr, new Comparator<String>() {
            public int compare(String s1, String s2) {
                if (s1.length() == s2.length()) {
                    return s1.compareTo(s2);
                }
                else {
                    return s1.length() - s2.length();
                }
            }
        });

        System.out.println(arr[0]);
        for (int i=1;i<N;i++) {
            if (!arr[i].equals(arr[i-1])) {
                System.out.println(arr[i]);
            }
        }
    }
}