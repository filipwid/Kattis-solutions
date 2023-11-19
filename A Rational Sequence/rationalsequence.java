import java.util.Scanner;

/*  Note that there are 3 cases.
    Case 1: A node is the right-most child in the tree. Given by q = 1.
    The next will then be the left-most child one level down where p = 1 and q = p_old +1

    Case 2: A node is the left child of its mother node. Given by p < q.
    The next node will be the right node of the mother node of the original node.
    The mother node will be p/q-p and its right child will therefore be p-p+q/q-p = q/q-p


    Case 3: A node is the right child of its mother node. q > p.
    We need to traverse up the tree until we reach a node which is the left child, go to its
    parent and then the right child. Then we would need to take the left child until we reach 
    the same level as the original node.

    Given that right child is (p+q)/q, the second right child would therefore be (p+p+q)/q and 
    so on. To get the steps until we reach a left child would therefore be p/q and truncate the 
    remainder. Then move to the right child of the parent in the same way as case 2. From that 
    node we take the left node until the right level.
 
*/

class Main {
    public static void main(String[] args) {
        //Scanner sc = new Scanner(System.in);
        Kattio sc = new Kattio(System.in);
        int loops = sc.getInt();
        int currLoop;
        while(loops-- > 0) {
            
            currLoop = sc.getInt();
            String in = sc.getWord();
            String[] arrSplit = in.split("/");
            int numerator = Integer.parseInt(arrSplit[0]);
            int denominator = Integer.parseInt(arrSplit[1]);

            if(denominator == 1) {
                denominator = numerator+1;
                numerator = 1;
            } 
            
            else if(numerator < denominator) {
                int temp = denominator;
                denominator = denominator - numerator;
                numerator = temp;
            } 

            else {
                
                int steps = numerator/denominator; // Truncates the p remainder
                numerator = numerator - steps*denominator;
                int q_new = denominator - numerator;
                numerator = denominator;
                denominator = q_new + (numerator*steps);

            }

            System.out.printf("%d %d/%d\n", currLoop, numerator, denominator);
        }     
    }   

}
