SELECT D.Name AS Department ,E.Name AS Employee ,E.Salary 
from 
	Employee E,
	Department D 
WHERE E.DepartmentId = D.id 
  AND (DepartmentId,Salary) in 
  (SELECT DepartmentId,max(Salary) as max FROM Employee GROUP BY DepartmentId)

# SELECT d.name as department, e.name as employee, E.Salary 
# from
# employee e ,
# department d
# where e.departmentId = d.id

# select D.name as Department, E.name as Employee, E.salary as Salary from Employee as E, Department as D
# where E.departmentId=D.id
# and (E.departmentId,E.salary) in (select departmentId,max(salary) from Employee group by departmentId);