# Write your MySQL query statement below
SELECT e.name 
FROM Employee AS e
INNER JOIN Employee b
ON e.id=b.managerId
GROUP BY b.managerId
HAVING COUNT(b.managerId)>=5;

