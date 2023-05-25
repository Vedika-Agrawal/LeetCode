# Write your MySQL query statement below

# SELECT name as customers form customers c
# LEFT JOIN orders o on c.id = o.customerid
# WHERE o.customerid is null



# SELECT Name as customers from Customers  WHERE Id NOT IN (SELECT CustomerId from Orders )



# SELECT name as customers from customers as c
# LEFT JOIN  orders o on c.id = o.customerid
# where o.customerid is null

SELECT C.name as customers from Customers as C
left join Orders as O
ON C.id=O.customerId
where O.customerId is NULL;