SELECT a.flavor
from (
    select flavor, sum(total_order) as total from first_half
    group by flavor
) a
join (select flavor, sum(total_order) as total from july
     group by flavor) b
on a.flavor = b.flavor
order by a.total + b.total desc
limit 3
