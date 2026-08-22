# Write your MySQL query statement below
select player_id,event_date as 'first_login' from
(select player_id,event_date,
dense_rank() over (partition by player_id order by event_date) as rnk 
from Activity)t where rnk=1;