select q.person_name
from queue as q
join(
select person_id, sum(weight) over (order by turn) as running  
from queue
) as xl
on q.person_id = xl.person_id
where xl.running <= 1000 
order by turn desc
limit 1;

