nano-ecc java binding
---------------------

a simple JAVA binding for nano-ecc made with help of the native JNI interface


Features
--------

 * simplified JAVA interface int nano_ecc.java
 * test case like main.java file
 * Makefile to build the shared object to be used by java

Usage Notes
-----------

#### Using the Code ####

Run

make && java *.java && java main

 * to build the shared object to be used by the utilized JAVA JNI (make), 
 * to compile the java code
 * to finally run the java test class

#### How it got created ####

nano_ecc.java contains a simplified API version of ../inc/ecc.h which can be utilitzed much easier by JNI.
Compile the java code by calling
 * javac *.java
and run the
 * javah -jni nano_ecc

This process actually creates the nano_ecc.h stubs and thereby the declarations. The definition do still have to be
integated and got defined in nano_ecc.c.

A Makefile got defined to run this process smoothly.