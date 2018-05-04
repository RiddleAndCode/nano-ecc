import java.security.SecureRandom;
import java.security.NoSuchAlgorithmException;
import java.security.MessageDigest;
import java.nio.charset.StandardCharsets;
import javax.xml.bind.DatatypeConverter;
import java.nio.file.Paths;
import java.nio.file.Path;


 public class test_java_interface{
   private static void PrintArray( String name, byte[] _array ){
    System.out.println( name + " : " + DatatypeConverter.printHexBinary(_array));  
   }
   public static void main(String argv[]) {

     Path currentRelativePath = Paths.get("");
     String thePath = currentRelativePath.toAbsolutePath().toString();
     //System.load("/c/dev/RaC/nano-ecc/java_binding2/nano_ecc.so");
     System.load(thePath + "/nano_ecc.so");

     byte[] x = new byte[32];
     byte[] y = new byte[32];
     byte[] priv = new byte[32];
     byte[] rnd = new byte[32];
     
     //
     // private key creation
     //
     SecureRandom random = new SecureRandom();
     random.nextBytes(rnd);

     //
     // create public key (complete the pair)
     //
     System.out.println("\nStep 1: Generating keys ...");
     if( nano_ecc.api_ecc_make_key( x,y,priv,rnd ) == 0 )
     {
       System.out.println("Key generation FAILED !!!");
       return;
     }
     System.out.println("Key pair generated :");
     PrintArray("Public Key X", x);    
     PrintArray("Public Key Y", y);
     PrintArray("Private Key", priv);
     PrintArray("Entropy", rnd);

     
     //
     //verify if the key is valid, stop tests otherwise
     //
     System.out.println("\nStep 2: Verify key integrity ...");
     if( nano_ecc.ecc_valid_public_key( x, y ) == 0 )
     {
       System.out.println("The generated public key is not valid: FAILED !!!");
       return;
     }
     System.out.println("The generated public key is valid.");
      
     //
     // as we do now have the private an the public key we can sign a message 
     // and verify if the hash corresponds to the publich key
     //
     System.out.println("Create Message and start signing process ...");
     String message = "I am not yet encrypted. Please sign me.";
     System.out.println("Message : " + message);
     byte [] msg_hash;
     try{
       MessageDigest digest = MessageDigest.getInstance("SHA-256");
       msg_hash = digest.digest(message.getBytes(StandardCharsets.UTF_8));
       PrintArray( "Message digest", msg_hash);
     }
     catch( NoSuchAlgorithmException e)
     {
      System.err.println("I'm sorry, but the requested algorithms is not supported");
      return;
     }

     //
     // sign the message hash 
     //
     System.out.println("\nStep 3: signing ...");
     byte[] rnd_number = new byte[32];
     byte[] s = new byte[32];
     byte[] r = new byte[32];
     random.nextBytes(rnd_number);
     if( nano_ecc.ecdsa_sign( r,s, priv, rnd_number, msg_hash) == 0 )
     {
       System.out.println( "The signature could not be created !!!");
       return;
     }
     System.out.println( "Successfully created the signature.");
     PrintArray( "r", r);
     PrintArray( "s", s);

     //
     // verify if the hash is valid and can be contributed to the public key
     //
     System.out.println("\nStep 4: verify signature...");
     if( nano_ecc.ecdsa_verify( x,y, msg_hash, r, s) == 0 )
     {
        System.out.println( "The signed message hash can not be contributed to the given public key !!!");
        return;
     }
     System.out.println( "The signed hash is valid.");
     
    }
 }
