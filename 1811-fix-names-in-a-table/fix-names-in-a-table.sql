# Write your MySQL query statement below
select x.user_id, concat(upper(left(x.name,1)), substring(x.name,2)) as name
from (
select user_id , lower(name) as name
from Users) as x
order by user_id
