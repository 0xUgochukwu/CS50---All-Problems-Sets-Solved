SELECT people.name FROM people
INNER JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id = (SELECT movies.id FROM movies WHERE movies.title = 'Toy Story');