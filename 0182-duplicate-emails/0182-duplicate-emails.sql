# Write your MySQL query statement below
-- select distinct Email 
-- from Person 
-- group by email
-- having count(*)>1

with tmp as(
    select email,row_number() over(partition by email) as rnk
    from person
)
select distinct email from tmp where rnk>1