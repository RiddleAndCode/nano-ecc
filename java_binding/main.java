 public class main {
   public static void main(String argv[]) {
     System.load("/c/dev/RaC/nano-ecc/java_binding/nano_ecc.so");

     String x = "                                                              ";
     String y = "                                                              ";
     String priv = "                                                              ";
     String rnd = "asdfpoaidsjfpoiajfökajsdfölhdsfksnbökhjbönbksbgmkjfdpoigÖFOKN";

     nano_ecc.api_ecc_make_key( x,y,priv,rnd );
     System.out.println( "java x =" + x );
     System.out.println( "java y =" + y );
     System.out.println( "java priv = " + priv );
     // create public key
    /* EccPoint pubKey = new EccPoint();
     long rnd = 23094;
     SWIGTYPE_p_uint8_t privKey = new SWIGTYPE_p_uint8_t();
     SWIGTYPE_p_uint8_t rndNumber = new SWIGTYPE_p_uint8_t( rnd, true);

     nano_ecc.ecc_make_key( pubKey, privKey, rndNumber);
     System.out.println(pubKey.getX());  
     System.out.println(pubKey.getY());  
     */
   }
 }