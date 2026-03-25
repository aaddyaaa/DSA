select w1.id 
from weather w1
join weather w2
ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
WHERE w1.temperature> w2.temperature 