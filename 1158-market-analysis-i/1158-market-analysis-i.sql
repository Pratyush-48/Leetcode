# Write your MySQL query statement below
select u.user_id as buyer_id ,u.join_date as join_date ,coalesce(t.orders_in_2019,0) as 'orders_in_2019'
from Users u
left join
(select buyer_id, sum(case when year(order_date)=2019 then 1 else 0 end) as orders_in_2019
from Orders group by buyer_id) t on u.user_id = t.buyer_id;