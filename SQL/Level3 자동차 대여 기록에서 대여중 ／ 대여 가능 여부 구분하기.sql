SELECT A.car_id, IFNULL(B.availability, '대여 가능') AS AVAILABILITY
FROM (select car_id from car_rental_company_rental_history group by car_id) A
LEFT JOIN (select car_id, '대여중' as AVAILABILITY
            from car_rental_company_rental_history
          where date('2022-10-16') >= start_date and date('2022-10-16') <= end_date
          group by car_id) B
ON A.CAR_ID = B.CAR_ID
ORDER BY A.car_id DESC
