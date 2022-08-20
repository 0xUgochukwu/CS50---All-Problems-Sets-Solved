SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Chadwick Boseman');

SELECT movies.title FROM stars
   ...> INNER JOIN movies ON  stars.movie_id = movies.id
   ...> INNER JOIN people ON stars.person_id = people.id