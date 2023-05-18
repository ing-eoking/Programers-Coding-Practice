SELECT CONCAT('/home/grep/src/', BOARD_ID,'/',FILE_ID,FILE_NAME,FILE_EXT)
FROM USED_GOODS_FILE
WHERE BOARD_ID = (select board_id from used_goods_board where views = (select max(views) from used_goods_board))
ORDER BY FILE_ID DESC
