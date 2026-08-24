# Write your MySQL query statement below
select actor_id,director_id from
(select actor_id,director_id,
row_number() over (partition by actor_id,director_id order by actor_id) as rn
from ActorDirector)t where t.rn = 3;