# Write your MySQL query statement below
select d.name as 'Department',t.name as 'Employee',t.salary as 'Salary' from
(select name,salary,departmentId,
dense_rank() over (partition by departmentId order by salary desc) as rnk
from Employee)t left join Department d on t.departmentId = d.id where rnk<=3;