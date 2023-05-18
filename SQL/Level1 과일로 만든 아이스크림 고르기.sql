SELECT FLAVOR
FROM FIRST_HALF
WHERE FLAVOR in (select flavor from icecream_info where ingredient_type like '%fruit%')
GROUP BY FLAVOR
HAVING SUM(TOTAL_ORDER) > 3000
ORDER BY SUM(TOTAL_ORDER) DESC
