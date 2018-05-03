import java.security.SecureRandom;
import java.security.NoSuchAlgorithmException;
import java.security.MessageDigest;
import java.nio.charset.StandardCharsets;

 public class main {
   public static void main(String argv[]) {
     System.load("/c/dev/RaC/nano-ecc/java_binding2/nano_ecc.so");

     byte[] x = new byte[33];
     byte[] y = new byte[33];
     byte[] priv = new byte[33];
     byte[] rnd = new byte[33];
     
     // private key creation
     SecureRandom random = new SecureRandom();
     random.nextBytes(rnd);

     
     System.out.println("x : " +new String(x));
     System.out.println("y : " +new String(y));
     System.out.println("p : " +new String(priv));
     System.out.println("r : " +new String(rnd));

     // create public key (complete the pair)
     nano_ecc.api_ecc_make_key( x,y,priv,rnd );
     
     System.out.println("x : " +new String(x));
     System.out.println("y : " +new String(y));
     System.out.println("p : " +new String(priv));
     System.out.println("r : " +new String(rnd));
     //verify if the key is valid

      

     // as we do now have the private an the public key we can sign a message 
     // and verify if the hash corresponds to the publich key
     String message = "I am not yet encrypted. Please sign me.";
     System.out.println("Message : " + message);
     try{
       MessageDigest digest = MessageDigest.getInstance("SHA-256");
       byte[] hash = digest.digest(message.getBytes(StandardCharsets.UTF_8));
       
       System.out.println("Message digest: " + new String(hash));
     }
     catch( NoSuchAlgorithmException e)
     {
      System.err.println("I'm sorry, but the requested algorithms is not supported");

     }
     // created the hash, let's verify the key
    }
 }