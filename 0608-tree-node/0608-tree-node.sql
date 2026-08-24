# Write your MySQL query statement below

# count the child nodes of each of the node
# if p_id = null it is root
# if number of child nodes is 0 then it is leaf
# else it is inner
SELECT id,
    CASE
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN (SELECT p_id FROM Tree) THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree;