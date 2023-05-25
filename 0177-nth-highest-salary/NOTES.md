```
**# CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
# BEGIN
#  INT M
#  SET M = N-1
​
#   RETURN (
#       # Write your MySQL query statement below.
#       SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT M, 1
#   );
# END******
```