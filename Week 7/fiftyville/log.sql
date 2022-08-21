-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
-- From the desciption the crime took place at 10:15 at the bakery

SELECT * FROM bakery_security_logs WHERE year = 2021 AND day = 28 AND month = 7 AND hour = 10 AND  minute >= 15;
-- If the crime took place at 10:15 then we should track the first exit on or after that time as this will most likely be the thief
