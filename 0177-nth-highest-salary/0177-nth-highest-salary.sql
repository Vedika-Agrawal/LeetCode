CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT

BEGIN
  Set N= N-1;
  RETURN (
     IFNULL ((SELECT distinct salary FROM Employee order by salary desc limit 1 offset N),NULL) 
  );
END