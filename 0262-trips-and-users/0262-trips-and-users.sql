# Write your MySQL query statement below

SELECT request_at as day, ROUND(SUM(If(status='completed',0,1))/ count(status),2) as 'Cancellation Rate' 
FROM 
trips
where
client_id not in (select users_id from users where Banned='yes')
and driver_id not in (select users_id from users where Banned='yes')
and request_at between '2013-10-01' and '2013-10-03' 
GROUP BY Request_at;


# SELECT request_at as Day, round(sum(if(status='completed',0,1))/count(status),2) as 'Cancellation Rate'
# from 
# Trips
# where driver_id not in 
#     (select users_id from Users where banned='Yes') 
#     and    client_id not in (select users_id from Users where banned='Yes') 
#     and request_at between '2013-10-01' and '2013-10-03'
# # group by request_at;
# GROUP BY Request_at;