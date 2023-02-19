# Write your MySQL query statement below
SELECT MAX(salary) as secondhighestsalary FROM Employee 
where 
salary < (SELECT MAX(salary) FROM Employee);