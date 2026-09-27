SELECT product_id, new_price AS price
From Products
where (product_id, change_date) IN
(
    select product_id, max(change_date)
    From products
    where change_date <= '2019-08-16'
    Group By product_id
)

Union

SELECT product_id, 10 AS price
From Products
Where product_id NOT IN
(
    select product_id
    from products
    where change_date <= '2019-08-16'
)