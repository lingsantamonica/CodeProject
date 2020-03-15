
 
 
  CREATE TABLE LYP_COURSE(
  
     course_number  number(7),
     course_name    varchar2(20),
  
  );
  
  Drop table LYP-COURSE;

  
 DECLARE 
    con_today  DATE      := SYSDATE;
    var_fullname       varchar2(30)       :='YunPeng Ling'; 
    var_rowcount       number(1);
    var_course_name   varchar(40);
      
 BEGIN
      dbms_output.enable;
 
   
  Insert into LYP_COURSE
     (course_number, course_name)
     values
     ('cs60', 'database concepts and Applications');
     
Insert into  LYP_COURSE
     (course_number, course_name)
     values
     ('cs61', 'microsoft sql server datebase');
     
Insert into LYP_COURSE
    (course_number, course_name)
    values
    ('cs65', 'Oracle_Programming');
    
SELECT course_name 
    INTO var_course_name
    from LYP_COURSE
    where Course_name = 'cs60';
    
dbms_output.put_line('The course name for cs60 is ' || var_course_name);

SELECT count(*)
       into var_rowcount
       from LYP_COURSE;
   dbms_output.output.put_line('the number of rows in this table is'||count(*));
      



SET serveroutput ON
 
DECLARE 
    var_reversed_fullname varchar2(30);
    var_letter    char(1);
    var_fullname       varchar2(30)    := 'YunPeng Ling'; 

    
BEGIN
  dbms_output.enable;
  
  FOR i IN REVERSE 1..LENGTH(var_fullname) LOOP
      var_letter := SUBSTR(var_fullname, i,1);
      var_reversed_fullname := var_reversed_fullname || var_letter;
  END LOOP;
   dbms_output.put_line(var_reversed_fullname);
END;
/
show error
