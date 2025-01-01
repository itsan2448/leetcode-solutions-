# Write your MySQL query statement below

select request_at as day, 
round(sum(status in ('cancelled_by_driver','cancelled_by_client'))/count(*),2) as 'Cancellation Rate'
from Trips
where client_id in (select users_id from users where banned='No' and role='client')
and 
driver_id in (select users_id from users where banned='No' and role='driver')
and 
request_at between "2013-10-01" and "2013-10-03"
group by request_at 