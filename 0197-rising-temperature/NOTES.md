SELECT w2.id from weather w1, weather w2
where datediff(w2.recorddate,w1.recorddate)=1 and w2.temperature>w1.temperature;
​
​
SELECT w2.id from Weather w1,Weather w2
WHERE datediff(w2.recordDate, w1.recordDate) = 1 AND w2.temperature > w1.temperature;