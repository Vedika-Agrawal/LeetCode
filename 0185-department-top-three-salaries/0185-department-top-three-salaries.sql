# select d.name as department, e1.name as employee, e1.salary
# from employee e1
# join Department d on e1.DepartmentId = d.Id
# where (
    
    
# )


select d.name as department, e.name as employee, e.salary
from 
(select * ,dense_rank()  over (partition by departmentId order by salary desc ) as r from employee) e
INNER JOIN 
department as d 
on 
d.id = e.departmentId
where r<=3;


# WHERE (
# SELECT COUNT(DISTINCT salary)
# FROM Employee AS E2
# WHERE E2.departmentid = D.id AND E2.salary >= E.salary
# ) <= 3