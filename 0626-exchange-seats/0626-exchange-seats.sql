select (CASE 
    WHEN id%2=1 and id!=(select count(*) from Seat) THEN id+1
    WHEN id%2=0 THEN id-1
    ELSE id
    END) id,student
from Seat 
order by id;
