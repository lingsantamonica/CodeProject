
/* Step 1.  In the Declaration section, stores SYSDATE in a symbolic constant
named con_today and stores your full name in a variable named var_fullname. 
Then in the executable section that begins with the keyword BEGIN, 
use the procedure dbms_output.put_line(string) to output the variable 
and separately output the symbolic constant.  Just after the BEGIN, 
include dbms_output.enable; */
 
 
 CREATE OR REPLACE FUNTION LING (CON_TODAY IN DATE, VAR_FULLNAME IN VARCHAR2)
 
 RETURN DATE IS 
      CON_TODAY DATE;
      VAR_FULLNAME VARCHAR2;
      
  BEGIN
      dbms_output.put_line(string);
 
 
  CREATE TABLE LYP_COURSE