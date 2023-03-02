# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
with temp_table as (
    SELECT id, email, row_number() over(partition by email order by id asc) as row_num
    FROM person
)
 DELETE from person where id in (
     select id from temp_table where row_num <>1
 )