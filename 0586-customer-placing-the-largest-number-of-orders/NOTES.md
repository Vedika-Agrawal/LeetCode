select customer_number from orders
group by customer_number
order by count(order_number) desc
limit 1;
​
select  customer_number from orders
group by customer_number order by count(order_number) desc
limit 1;
​
SELECT customer_number
FROM orders
Group BY customer_number
HAVING  count(order_number) =
(SELECT max(numOfOrder)
FROM
(SELECT customer_number,count(order_number) as numOfOrder
FROM orders
Group By customer_number) as temp)