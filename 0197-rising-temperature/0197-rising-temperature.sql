# Write your MySQL query statement below

select e.id 
from
weather w,
weather e 
where
datediff(e.recorddate,w.recorddate)=1
and
e.temperature > w.temperature;