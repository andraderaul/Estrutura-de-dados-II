/**
 *
 * @author howl
 */
public class hash3 {
    
    private static int M;
    private static int a;
    private static int k;
    private static char key[] = {'S','E','A','R','C','H','X','M','P','L'};
    private static int hash[] = new int[1000];
    private static int primos[] = {1,2,3,5,7,11,13,17,19,23,27,29,31};
    
    public static int calculaHash(int letra){
        return (a * letra) % M;
    }
            
    
    public static void main(String[] args) {
        int c = 0;
        for(int i = 0; i < 13; i++){
            a = primos[i];
            for (int j = 1; j < 100; j++) {
                M = j;
                for (int l = 0; l < 10; l++) {
                    int aux;
                    aux = calculaHash((int)key[l]);
                    if(hash[aux] == 0){
                        hash[aux]++;
                    }    
                    else{
                        c++;
                        break;
                    }
                        
                }
                if(c == 0){
                    System.out.println("a: "+ a + " - " + "M "+ M);
                    break;
                }
                c = 0;
                for (int l = 0; l < 1000; l++) {
                    hash[l] = 0;
                }
            }
        }
    }
    
}
