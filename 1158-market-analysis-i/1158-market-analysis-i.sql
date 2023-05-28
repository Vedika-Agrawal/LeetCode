# Write your MySQL query statement below

# select u.user_id as buyer_id , u.join_date,  count(o.order_date) as  orders_in_2019 from users u left join orders o
# having
# year(o.order_date)=2019
# group by buyer_id
# order by user_id;




SELECT u.user_id as buyer_id, u.join_date, count(o.order_id) as orders_in_2019
FROM users u
LEFT JOIN Orders o
ON o.buyer_id=u.user_id AND YEAR(order_date)='2019'
GROUP BY u.user_id