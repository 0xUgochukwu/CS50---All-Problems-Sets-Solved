SELECT COUNT(movies.title) FROM movies
INNER JOIN (
    SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Johnny Depp')
    UNION
    SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Helena Bonham')
    )
AS newMovies ON newMovies.movie_id = movies.id

