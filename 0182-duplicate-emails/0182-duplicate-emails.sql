# Write your MySQL query statement below


# SELECT email from (select email, count(email) as cnt from person group by email) temp where temp.cnt>

select Email
from Person
group by Email
having count(email) > 1