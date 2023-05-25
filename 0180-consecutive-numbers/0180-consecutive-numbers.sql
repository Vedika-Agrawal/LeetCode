Select distinct l1. num as ConsecutiveNums  from
logs l1, logs l2, logs l3
Where
l2.id=l1.id+1 AND l2.id = l3.id-1
AND l1.Num = l2.Num
    AND l2.Num = l3.Num
;