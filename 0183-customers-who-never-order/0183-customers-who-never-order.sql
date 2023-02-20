# Write your MySQL query statement below

# SELECT name as customers form customers c
# LEFT JOIN orders o on c.id = o.customerid
# WHERE o.customerid is null

SELECT Name as customers from Customers WHERE Id NOT IN (SELECT CustomerId from Orders )

# SELECT Name as customers from Customers  WHERE Id NOT IN (SELECT CustomerId from Orders )