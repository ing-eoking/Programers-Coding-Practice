SELECT USER_ID, NICKNAME, CONCAT(CITY,' ', STREET_ADDRESS1,' ', STREET_ADDRESS2),
CONCAT(SUBSTRING(TLNO, 1, 3),'-', SUBSTRING(TLNO,4,4),'-', SUBSTRING(TLNO,8,4))
FROM USED_GOODS_USER
WHERE USER_ID IN (select writer_id from used_goods_board group by writer_id having count(board_id) >= 3)
ORDER BY USER_ID DESC
