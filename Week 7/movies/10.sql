SELECT people.name FROM directors
INNER JOIN ratings ON directors.movie_id = ratings.movie_id
INNER JOIN people ON directors.person_id = people.id
WHERE ratings.rating >= 9.0;