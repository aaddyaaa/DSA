with duplicate_tiv as (
    select tiv_2015
    from insurance
    group by tiv_2015
    having count(*) > 1
),
unique_location as (
    select lat, lon
    from insurance
    group by lat, lon
    having count(*) = 1
)

select
    round(sum(i.tiv_2016), 2) as tiv_2016
from insurance i
join duplicate_tiv d
    on i.tiv_2015 = d.tiv_2015
join unique_location u
    on i.lat = u.lat
   and i.lon = u.lon;