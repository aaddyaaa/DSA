select round(avg(CASE WHEN d.order_date=d.customer_pref_delivery_date THEN 1 ELSE 0 END) * 100, 2) as immediate_percentage
from delivery as d
join (
    select
    d.customer_id,
    min(d.order_date) as first_order_date
    from delivery as d
    group by customer_id
) as f
ON d.customer_id = f.customer_id
AND
d.order_date = f.first_order_date
#d.customer_id, d.order_date, d.customer_pref_delivery_date