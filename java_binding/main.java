 import java.util.StringTokenizer ;
 public class main {
   public static void main(String argv[]) {
/*     String property = System.getProperty("java.library.path");
     StringTokenizer parser = new StringTokenizer(property, ";");
while (parser.hasMoreTokens()) {
    System.err.println(parser.nextToken());
    }
    */
     System.loadLibrary("nano_ecc");
     //EccPoint point;
/*     nano_iecc.ecc_make_key( )e
     System.out.println(nano_ecc.getMy_variable());
     System.out.println(nano_ecc.fact(5));
     System.out.println(nano_ecc.get_time());
     */
   }
 }