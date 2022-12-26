SELECT  d.name AS 'dName'
FROM demo
WHERE NOT IN (
SELECT  other
FROM others )