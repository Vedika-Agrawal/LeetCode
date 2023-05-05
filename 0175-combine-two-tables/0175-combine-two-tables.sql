# Write your MySQL query statement below

SELECT p.firstName, p.lastName, a.city, a.state 
FROM person p 
LEFT JOIN
Address a
on p.personId = a.personId ;

# SELECT P.firstName, P.lastName, A.city, A.state
# FROM Person P LEFT JOIN Address A
# on P.personId = A.personId