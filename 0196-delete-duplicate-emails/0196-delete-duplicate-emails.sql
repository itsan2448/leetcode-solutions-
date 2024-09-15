# Write your MySQL query statement below

delete from person
where id not in (
    select m_id 
    from (
        select min(id) as m_id
        from person
        group by email
    ) as a
);


