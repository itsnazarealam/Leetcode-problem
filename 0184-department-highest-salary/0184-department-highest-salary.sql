Select Department, Employee, Salary
FROM(
    SELECT
        d.name Department,
        e.name Employee,
        e.salary as Salary,
        Dense_Rank() Over(
            partition by e.departmentid
            order by e.salary Desc
        ) as rank_num    
    FROM
    Employee AS e
    INNER JOIN Department AS d
    ON e.departmentId = d.id
) ranked
where rank_num=1;