# Write your MySQL query statement below
SELECT teacher_id , COUNT(distinct subject_id)AS cnt 
FROM TEACHER 
GROUP BY teacher_id