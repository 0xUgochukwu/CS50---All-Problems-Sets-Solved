SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Johnny Depp')
UNION
SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Helena Bonham');