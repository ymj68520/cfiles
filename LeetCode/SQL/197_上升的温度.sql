SELECT  a.id
FROM Weather a, Weather b
WHERE 1 = timestampdiff(day, b.recordDate, a.recordDate)
AND a.temperature > b.temperature