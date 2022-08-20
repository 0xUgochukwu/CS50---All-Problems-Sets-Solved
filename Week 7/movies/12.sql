SELECT COUNT(movies.title) FROM movies
INNER JOIN (
    SELECT movie_id AS DeppMovies FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Johnny Depp')
    INNER JOIN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Helena Bonham')) AS helMovies ON helMovies.movie_id = DeppMovies.movie_id

    )
AS newMovies ON newMovies.movie_id = movies.id

