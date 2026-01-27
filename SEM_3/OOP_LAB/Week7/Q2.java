import MyPackages.p1.Maximum;

public class Q2{
    public static void main(String[] args) {
        System.out.println("1, 5, 3 : " + Maximum.max(1,5,3));
        System.out.println("1.3, 5.1, 3.8 : " + Maximum.max(1.3f,5.1f,3.8f));
        System.out.println(" [1, 5, 3] : " + Maximum.max(new int[]{1,5,3}));
        System.out.println(" [[1,4], [5,8], [3,9]] : " + Maximum.max(new int[][]{new int[]{1,4}, new int[]{5,8}, new int[]{3,9}}, 3, 2));
    }
}