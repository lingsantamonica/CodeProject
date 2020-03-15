

--CS60_Final_D_LING_YUNPENG.SQL  12-12-2017

DECLARE
    var_total number :=0;
    
set serveroutput ON

BEGIN
   dbms_output.enable;
  For i IN 1..2000 LOOP
   IF (i/2 != 0) then
     var_total := Total + i;
     dbms_output.put_line('the sum of the odd digits is '||var_total);
     END IF;
  END LOOP;
  END
  /


--Below are the code of creat table

CREATE TABLE LYP_DatabaseDeveloper(
   ID                number(7) NOT NULL, 
   LastName          varchar2(20) UNIQUE,
   EnrollmentDate     DATE  NOT NULL,

  CONSTRAINT PK_LYP_DatebaseDeveloper PRIMARY KEY(ID)
  );

 Insert into LYP_DatabaseDeveloper
   (ID, LastName, EnrollmentDate)
  values
  (1526000, 'LING', SYSDATE);
  
 Insert into LYP_DatabaseDeveloper
   (ID, LastName, EnrollmentDate)
  values
  (1500000, 'Smith', 18-15-17);
  
SELECT * FROM LYP_DatabaseDeveloper;

UPDATE LYP_DatabaseDeveloper
    SET LastName = 'Jones'
    where LastName = 'Smith';
    
DELETE FROM LYP_DatabaseDeveloper
   WHERE ID = 1500000;
   
DROP TABLE LYP_DatabaseDeveloper;