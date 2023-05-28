# # Write your MySQL query statement below

# select u.name, sum(r.distance) as travelled_distance from users u
# left join
# rides r on 
#   u.id = r.user_id
# group by r.user_id
# ORDER BY desc, u.name;

# # Write your MySQL query statement below
# SELECT u.name,case when r.distance is NULL then 0
#               else sum(r.distance) end
# as travelled_distance from users u
# left join Rides r on u.id=r.user_id
# group by r.user_id
# order by sum(r.distance) desc,u.name;


# Write your MySQL query statement below
SELECT u.name,case when r.distance is NULL then 0
              else sum(r.distance) end
as travelled_distance from users u
left join Rides r on u.id=r.user_id
group by r.user_id
ORDER BY sum(r.distance) DESC,u.name;