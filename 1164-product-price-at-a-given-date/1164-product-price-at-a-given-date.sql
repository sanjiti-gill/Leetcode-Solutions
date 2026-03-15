# Write your MySQL query statement below
-- Products that had a price change ON or BEFORE 2019-08-16
-- Pick the LATEST change for each product
SELECT product_id, new_price AS price
FROM Products
WHERE (product_id, change_date) IN (
    SELECT product_id, MAX(change_date)
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
)

UNION

-- Products with NO price change on or before 2019-08-16 → default price 10
SELECT DISTINCT product_id, 10 AS price
FROM Products
WHERE product_id NOT IN (
    SELECT product_id
    FROM Products
    WHERE change_date <= '2019-08-16'
);