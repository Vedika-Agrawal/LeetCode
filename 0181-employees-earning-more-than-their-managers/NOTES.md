​
​
SELECT e1.name as employee from employee e1
JOIN employee e2 ON e1.managerid = e2.id and e1.salary>e2.salary