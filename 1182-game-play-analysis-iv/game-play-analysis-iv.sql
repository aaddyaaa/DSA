SELECT
    ROUND(
        COUNT(a.event_date) / COUNT(*) * 1.0,
        2
    ) AS fraction
FROM (
    SELECT
        player_id,
        MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
) n
LEFT JOIN Activity a
    ON a.player_id = n.player_id
   AND a.event_date = DATE_ADD(n.first_date, INTERVAL 1 DAY);