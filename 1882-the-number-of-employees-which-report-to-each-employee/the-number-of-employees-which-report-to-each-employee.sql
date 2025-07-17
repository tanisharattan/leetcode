# Write your MySQL query statement below
SELECT m.employee_id , m.name , COUNT(e.reports_to) AS reports_count, ROUND(AVG(e.age),0) AS average_age 
FROM Employees m, Employees e
WHERE m.employee_id = e.reports_to


GROUP BY m.employee_id, m.name
ORDER BY m.employee_id 