SELECT movies.title FROM movies
INNER JOIN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Chadwick Boseman'))
AS chadMovies ON chadMovies.movie_id = movies.id
INNER JOIN ratings ON ratings.movie_id = movies.id;
ORDER BY ratings.rating DESC
LIMIT 5;