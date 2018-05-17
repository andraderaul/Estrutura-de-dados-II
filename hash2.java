import java.util.LinkedList;
import static java.util.Objects.hash;

/**
 *
 * @author andraderaul
 */
public class hash2 {
    static int M = 16;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        char keys[] = {'E', 'A', 'S', 'Y', 'Q', 'U', 'T', 'I', 'O', 'N'};
        char conteudo[] = new char[M];
        char coli[] = new char[M];
        int h[] = new int[M];
        for(int i = 0; i < keys.length; i++){
            int x = hash(keys[i]);
            if(h[x] == 0){
                h[x] = x;
                conteudo[h[x]] = keys[i];
            }else{
                while(h[x]!= 0){
                    x++;
                    x = x % M;//hash((char) x); 
                }
                h[x] = x;
                conteudo[h[x]] = keys[i];
                coli[h[x]] = '*';
            }
         }
        System.out.println();
        for(int i = 0; i<M; i++)
            System.out.println(h[i] +" "+ conteudo[i] + " " + coli[i]);
    }
    public static int hash(char k){
        return 11*k % M;
    }
    
}
