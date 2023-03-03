SELECT a.HISTORY_ID,
 ((datediff(end_date, start_date) + 1) * b.daily_fee)*(100 - ifnull(c.discount_rate, 0)) DIV 100 as FEE
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY a
left join car_rental_company_car b
on a.car_id = b.car_id
left join car_rental_company_discount_plan c
on b.car_type = c.car_type and c.duration_type = (
    case
        when datediff(end_date, start_date) + 1 >= 7 and datediff(end_date, start_date) + 1 < 30 then '7일 이상'
        when datediff(end_date, start_date) + 1 >= 30 and datediff(end_date, start_date) + 1 < 90 then '30일 이상'
        when datediff(end_date, start_date) + 1 >= 90 then '90일 이상'
    end
)
where b.car_type = '트럭'
order by fee desc, a.history_id desc
