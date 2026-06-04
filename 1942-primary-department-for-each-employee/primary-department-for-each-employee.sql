# Write your MySQL query statement below
select t.employee_id, t.department_id 
from (
    select *, count(*) over (partition by employee_id) as count_dept
    from employee
) as t
where t.primary_flag = 'Y' or t.count_dept = 1
order by t.employee_id