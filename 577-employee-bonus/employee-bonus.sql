# Write your MySQL query statement below
select emp.name,bon.bonus
from employee as emp
left join bonus as bon
on emp.empId = bon.empId
where bon.bonus < 1000 OR bon.bonus is null


