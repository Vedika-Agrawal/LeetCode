# Write your MySQL query statement below



UPDATE salary    
SET sex =
case 
when sex='f' then 'm' else 'f'
end;