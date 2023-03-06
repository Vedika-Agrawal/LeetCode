# Write your MySQL query statement below

SELECT CLASS From courses group by class having count(student)>=5;