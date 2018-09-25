import java.io.EOFException; 
import java.util.*;
public class Bai7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        System.out.println("Nhap vao duong kinh hinh tron \n");
        Float d = sc.nextFloat();
        System.out.printf("C = %.5f \n",d*3.14);
        System.out.printf("S = %.5f",d*d*3.14/4.0);
    }
}
