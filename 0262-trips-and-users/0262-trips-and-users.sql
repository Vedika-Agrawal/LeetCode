# Write your MySQL query statement below

select request_at as day , Round(Sum(if(status='completed', 0, 1))/ count(status), 2) as 'Cancellation Rate' 
FROM  trips where
 client_id not in (select users_id from users where banned='yes')
 and
 driver_id not in (select users_id from users where banned='yes')
 and
 request_at between '2013-10-01 ' and '2013-10-03'
 GROUP BY request_at;