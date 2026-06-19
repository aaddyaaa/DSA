with t as (
    select id,name,salary,departmentId,dense_rank() over(partition by departmentId order by salary desc ) as rn
    from employee
)
select d.name as Department, t.name as Employee, t.salary as Salary
from t
join department as d
on d.id = t.departmentId
where t.rn <= 3


