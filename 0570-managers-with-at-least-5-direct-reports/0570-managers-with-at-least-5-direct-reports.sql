SELECT
    e1.name
FROM Employee AS e1
INNER JOIN Employee AS e2
ON
    e1.id = e2.managerId
GROUP BY
    e2.managerId
HAVING
    COUNT(*) >= 5;