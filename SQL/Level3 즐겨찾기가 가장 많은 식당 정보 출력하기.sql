SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
FROM REST_INFO
WHERE (FOOD_TYPE, FAVORITES) IN (select food_type, max(favorites) from rest_info group by food_type)
ORDER BY FOOD_TYPE DESC
