# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below


DELETE p 
from
person p,  person d
where p.id > d.id 
AND p.email = d.email


# delete from Person as p1 ,Person p2 where p1.id<p2.id and p1.email=p2.email;

# DELETE p1 FROM Person as p1, Person as p2 WHERE p1.Email = p2.Email AND p1.Id > p2.Id;