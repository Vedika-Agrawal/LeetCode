# Write your MySQL query statement below


SELECT name from salesperson
where sales_id not in
(
SELECT sales_id from orders where com_id in (SELECT com_id from company where name = 'RED')
)
