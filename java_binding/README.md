nano-ecc java binding
---------------------

a simple JAVA binding for nano-ecc made with help of SWIG3.0 see http://www.swig.org/


Features
--------

 * simple integration into JAVA

Usage Notes
-----------

#### Using the Code ####

Run

 * swig3.0 -java nano_ecc.i 

to create the java files and the corresponding wrapper dynamically. 
Compile the wrapper containing the ecc object and the dynamically created wrapper

 * make

 