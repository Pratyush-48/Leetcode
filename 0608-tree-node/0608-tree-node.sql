# Write your MySQL query statement below

# count the child nodes of each of the node
# if p_id = null it is root
# if number of child nodes is 0 then it is leaf
# else it is inner
select id,
case when p.p_id is null then 'Root'
when chil>0 then 'Inner'
else 'Leaf'
end as type
from Tree p left join
(select p_id,count(id) as 'chil'
from Tree
group by p_id
order by p_id)t on p.id = t.p_id;