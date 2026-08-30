# Write your MySQL query statement below
with ranked as(
    select *, 
    row_number() over (partition by employee_id order by review_date desc)
    as rn
    from performance_reviews
),
pivoted as(
    select employee_id,
    max(case when rn=1 then rating end) as latest,
    max(case when rn=2 then rating end) as middle,
    max(case when rn=3 then rating end) as oldest,
    count(*) as c
    from ranked
    where rn<=3
    group by employee_id
)
select e.employee_id,e.name,p.latest-p.oldest as improvement_score
from employees e inner join pivoted p
on e.employee_id = p.employee_id 
where p.c = 3 and p.latest>p.middle and p.middle>p.oldest
order by improvement_score desc,name;