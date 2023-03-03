SELECT apnt_no, pt_name, a.pt_no, a.mcdp_cd, dr_name, apnt_ymd
from appointment a
left join doctor b
on a.mddr_id = b.dr_id
left join patient c
on a.pt_no = c.pt_no
where date(a.apnt_ymd) = '2022-04-13' and a.apnt_cncl_ymd is null and a.mcdp_cd = 'CS'
order by apnt_ymd
