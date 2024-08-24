public class factorialImp {
    public static void main(String[] args) {
        int n=3,r=1;
        while(n>1){
            r*=n;
            n--;
        }
        System.out.println(r);
    }
}
