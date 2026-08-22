# Write your MySQL query statement below
select score,rnk as 'rank' from
(select id,score,
dense_rank() over (order by score desc) rnk
from Scores)t;
