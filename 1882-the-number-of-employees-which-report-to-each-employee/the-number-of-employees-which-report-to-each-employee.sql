select x.employee_id, x.name, count(e.reports_to) as reports_count, round(avg(e.age)) as average_age
from employees as e
left join employees as x
on e.reports_to = x.employee_id
where e.reports_to is not null
group by x.employee_id, x.name
order by x.employee_id