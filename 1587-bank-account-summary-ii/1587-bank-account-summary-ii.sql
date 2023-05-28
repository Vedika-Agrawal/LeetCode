# Write your MySQL query statement below




select u.name, sum(t.amount) balance
from Users u
join Transactions t
on u.account = t.account
group by
    t.account
having
    balance > 10000;
