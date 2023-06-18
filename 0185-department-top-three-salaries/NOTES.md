select d.name as department, e.name as employee, e.salary
from
(select * ,dense_rank()  over (partition by departmentId order by salary desc ) as r from employee) e
INNER JOIN
department as d
on
d.id = e.departmentId
where r<=3;