# Write your MySQL query statement below

# select stock_name , sum(s2.price - s1.price) as capital_gain_loss
# from stock s1 , stock s2
# where s1.stock_name = s2.stock_name 
# and s1.operation = 'buy'
# and s2.operation = 'sell

select stock_name , sum(
    case 
    WHEN operation = 'Buy' THEN -price
        ELSE price
    END
    
)
as capital_gain_loss
from stocks
group by stock_name

# select stock_name , sum((case 
#     WHEN operation = 'Buy' THEN -price
#         ELSE price
#     END))
# as capital_gain_loss
# from Stocks
# group by stock_name