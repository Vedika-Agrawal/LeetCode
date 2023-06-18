CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN

set N = N-1;

  RETURN (
      
      # Write your MySQL query statement below.
      SELECT IFNULL ((SELECT distinct salary FROM Employee order by salary desc limit 1 offset  N),NULL) 
  );
END


# CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
# BEGIN
#   RETURN (
#       # Write your MySQL query statement below.
#       select ifNULL((select salary from Employee 
#       order by salary desc
#       limit 1 offset N),NULL)
#   );
# END