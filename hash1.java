import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author andraderaul
 */
public class hash1 {
     static int M = 100;
    /**
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        Set<String> arq = new HashSet();
        arq = processDocument();
        histograma(arq);
    }
    private static void histograma(Set<String> s){
        int[] vetor = new int[M];
        System.out.println(s.size());
        for(String y: s){
            int x = hash(y);
            vetor[x] = vetor[x] + 1;
        }
        for (int i = 0; i < M; i++){
            System.out.println("Palavras :" +vetor[i]);  
        }
    }   
    
    private static int hash(String x) { 
        return (x.hashCode() & 0x7fffffff) % M; 
    }
    
    public static HashSet processDocument() throws FileNotFoundException, IOException{
        BufferedReader doc = null;
        
        doc = new BufferedReader(new FileReader("tale.txt"));
        HashSet<String> wd = new HashSet();
        
            String line = doc.readLine();
            while(line!=null){
                String[] split = line.split(" ");
                wd.addAll(Arrays.asList(split));
                line = doc.readLine();
        }
            return wd;
    }
}
