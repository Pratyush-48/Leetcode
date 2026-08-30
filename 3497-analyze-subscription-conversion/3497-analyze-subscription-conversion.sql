# Write your MySQL query statement below
# data separated base on user_Id activity and 
with free as(
select user_id,activity_type,avg(activity_duration) as 'avgg'
from UserActivity
where activity_type = 'free_trial'
group by user_id,activity_type
order by user_id
),
paidd as(
select user_id,activity_type,avg(activity_duration) as 'avgg'
from UserActivity
where activity_type = 'paid'
group by user_id,activity_type
order by user_id
)
select f.user_id as user_id,round(f.avgg,2) as trial_avg_duration,round(p.avgg,2) as paid_avg_duration
from free f inner join paidd p on f.user_id = p.user_id;