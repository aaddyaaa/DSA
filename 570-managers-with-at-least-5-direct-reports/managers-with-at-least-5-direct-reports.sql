# Write your MySQL query statement below
select mgr.name
from employee as ee
join employee as mgr
on ee.managerId = mgr.id
group by mgr.id
having count(ee.id) >= 5