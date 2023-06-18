# select id , (if(p_id=NULL , 'root',  )) as type from tree

select id,

    case 
        when p_id is null then 'Root'
        when id in (select distinct p_id from Tree) then 'Inner'
        else 'Leaf'
    end as type
from Tree

