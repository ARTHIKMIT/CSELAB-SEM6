package MyPackages.p1;

public class Maximum {
    public static int max(int a, int b, int c){
        if (a>b){
            if (a>c)
                return a;
            else return c;
        }
        else if (b>c)
            return b;
        else return c;
    }
    public static float max(float a, float b, float c){
        if (a>b){
            if (a>c)
                return a;
            else return c;
        }
        else if (b>c)
            return b;
        else return c;
    }
    public static int max(int[] a){
        int max = a[0];
        for (int i=0; i<a.length; i++)
            if(a[i]>max)
                max = a[i];
        return max;
    }

    public static int max(int[][] a, int r, int c){
        int max = a[0][0];
        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++)
                if(a[i][j]>max)
                    max = a[i][j];
        return max;
    }
}