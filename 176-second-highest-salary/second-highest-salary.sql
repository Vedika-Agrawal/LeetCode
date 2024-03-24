# Write your MySQL query statement below


SELECT MAX(salary) as secondhighestsalary FROM Employee 
where 
salary < (SELECT MAX(salary) FROM Employee);


# SELECT IFNULL ((SELECT distinct salary FROM Employee order by salary desc limit 1 offset 1),NULL) as SecondHighestSalary

