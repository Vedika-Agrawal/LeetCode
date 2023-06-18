    select  distinct s1.* from stadium s1, stadium s2, stadium s3
    where s1.people>=100 and s2.people>=100 and s3.people>=100
    and ((s1.id=s2.id-1 and s1.id = s3.id-2)
    or (s1.id = s2.id+1 and s1.id=s3.id-1)
    or (s1.id = s3.id+2 and s1.id= s2.id+1))
    order by id;
    
