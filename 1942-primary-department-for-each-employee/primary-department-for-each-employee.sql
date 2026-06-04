# Write your MySQL query statement below
select employee_id, department_id 
from employee
where employee_id in (
    SELECT employee_id
    from employee
    group by employee_id
    having count(department_id) = 1
) OR employee_id in (
    SELECT employee_id
    from employee
    group by employee_id
    having count(department_id) > 1 and primary_flag = 'Y'
)
order by employee_id 