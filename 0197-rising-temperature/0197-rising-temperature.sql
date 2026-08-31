# Write your MySQL query statement below
select w1.id 
from Weather as w1
join weather as w2
on w1.recordDate = w2.recordDate + interval 1 day  # w1 = w2 date + 1
where w1.temperature > w2.temperature;