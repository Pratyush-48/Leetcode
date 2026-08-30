# Write your MySQL query statement below
# ek table banao product1_id product2_id aur count 
with tem as(
    select p.user_id as user_id,p.product_id as product_id,pp.category as category
    from ProductPurchases p inner join ProductInfo pp
    on p.product_id = pp.product_id
),
curr as(
    select p1.product_id as product1_id ,p2.product_id as product2_id,p1.category as product1_category ,p2.category as product2_category 
    from tem p1 cross join tem p2
    on p1.user_id = p2.user_id
    where p1.product_id < p2.product_id
)
select product1_id,product2_id,product1_category,product2_category,count(*) as customer_count
from curr 
group by product1_id,product2_Id
having customer_count>=3
order by customer_count desc,product1_id asc,product2_id asc;