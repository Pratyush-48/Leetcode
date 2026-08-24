# Write your MySQL query statement below
select name,su as 'balance' from
Users u inner join(
select account,sum(amount) as 'su'
from Transactions
group by account
having su>10000
)t on u.account=t.account;
