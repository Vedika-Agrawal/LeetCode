# Write your MySQL query statement below

SELECT e1.name as employee  from Employee e1, Employee e2
where
e1.managerid = e2.id 
and e1.salary > e2.salary ;
