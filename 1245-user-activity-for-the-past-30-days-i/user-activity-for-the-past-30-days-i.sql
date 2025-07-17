# Write your MySQL query statement below
SELECT
 activity_date AS day ,
  COUNT(distinct user_id ) AS active_users
FROM Activity
WHERE
 datediff('2019-07-27',activity_date) between 0 and 29
GROUP BY activity_date;