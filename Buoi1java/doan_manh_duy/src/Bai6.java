import java.io.EOFException;
import java.util.*;
public class Bai6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        System.out.println("Nhap  n>=0  \n ");
        Float n = sc.nextFloat(); 
        System.out.printf("sqrt(%f) = %.5f ",n,Math.sqrt(n) );
    }
}
