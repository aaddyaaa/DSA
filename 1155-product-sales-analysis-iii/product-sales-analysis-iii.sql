select s.product_id, x.first_year, s.quantity, s.price
from sales as s
join (
select min(s.year) as first_year, s.product_id
from sales as s
group by product_id
) as x
on x.first_year = s.year
and s.product_id = x.product_id