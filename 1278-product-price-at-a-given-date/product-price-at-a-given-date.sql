select product_id, 10 as price
from products
group by product_id
having min(change_date) > '2019-08-16'

union

select p.product_id , p.new_price as price
from products as p
join(
select p.product_id, max(p.change_date) as change_date
from products as p
where change_date <= '2019-08-16'
group by product_id
) as xl
on p.product_id = xl.product_id
and p.change_date = xl.change_date