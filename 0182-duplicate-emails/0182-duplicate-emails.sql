# Write your MySQL query statement below


# SELECT email from (select email, count(email) as cnt from person group by email) temp where temp.cnt>

# select Email
# from Person
# group by Email
# having count(email) > 1

SELECT  distinct p1.email from person p1, person p2
where p1.id <> p2.id 
AND p1.email=p2.email;