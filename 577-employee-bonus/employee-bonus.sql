# Write your MySQL query statement below
SELECT e.name ,b.bonus 
FROM Employee as e
LEFT JOIN Bonus as b 
ON e.empID=b.empID
WHERE bonus < 1000 OR bonus is  null

