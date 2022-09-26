-- Keep a log of any SQL queries you execute as you solve the mystery.

-- starting point
SELECT * FROM crime_scene_reports;

-- incidents on the day
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2021;

-- time of incident
SELECT activity,license_plate,minute FROM bakery_security_logs WHERE year = 2021 AND day = 28 AND month = 7 AND hour = 10;

-- witness statements
SELECT name,transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

-- people who left within 10 mins time frame of robbery
SELECT id, name, phone_number, passport_number FROM people WHERE license_plate in
(SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND day = 28 AND month = 7
AND hour = 10 AND activity = "exit" AND minute > 15 AND minute < 25);

-- atm withdrawal near emma's bakery on leggett street early in the morning
SELECT id, account_number FROM atm_transactions WHERE day = 28 AND month = 7
AND year = 2021 AND transaction_type = "withdraw" AND atm_location = "Leggett Street";

-- people who withdrew money
SELECT name, phone_number FROM people WHERE id in
(SELECT person_id FROM bank_accounts WHERE account_number in
(SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021
AND transaction_type = "withdraw" AND atm_location = "Leggett Street"));

-- people who withdrew money on 28 July from Leggett Street and whose cars left the bakery within 10 mins of the robbery
SELECT id, name, phone_number, passport_number FROM people WHERE license_plate in
(SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND day = 28 AND month = 7
AND hour = 10 AND activity = "exit" AND minute > 15 AND minute < 25) AND id in
(SELECT person_id FROM bank_accounts WHERE account_number in
(SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021
AND transaction_type = "withdraw" AND atm_location = "Leggett Street"));

-- people who made a call on 28 July for less than 1 min
SELECT id, name FROM people WHERE phone_number in (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 AND duration <= 60);

-- people who match all three witness interview description
SELECT id, name, phone_number, passport_number FROM people WHERE license_plate in
(SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND day = 28 AND month = 7
AND hour = 10 AND activity = "exit" AND minute > 15 AND minute < 25)
AND id in (SELECT person_id FROM bank_accounts WHERE account_number in
(SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021
AND transaction_type = "withdraw" AND atm_location = "Leggett Street"))
AND phone_number in (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 AND duration <= 60);

-- Narrowed it down to Diana and Bruce

-- Flights leaving the next day after the robbery
SELECT * FROM flights WHERE day = 29 AND month = 7 AND year = 2021;

-- Find airport_id of Fiftyville airport
SELECT id, abbreviation FROM airports WHERE city = "Fiftyville";

-- Flight on which either Bruce or Diana are travelling in on 29 July with time of departure
SELECT id, hour, minute FROM flights WHERE origin_airport_id = 8 AND year = 2021 AND month = 7 AND day = 29 AND
id in (SELECT flight_id FROM passengers WHERE passport_number in
(SELECT passport_number FROM people WHERE name = "Bruce" OR name = "Diana")) ORDER BY hour ASC, minute ASC;

-- Earliest flight of the day is flight 36, passenger on flight 36 is the thief
SELECT name FROM people WHERE passport_number in (SELECT passport_number FROM people WHERE name = "Bruce" OR name = "Diana")
AND passport_number in (SELECT passport_number FROM passengers WHERE flight_id = 36);

-- Bruce is the thief

-- The place Bruce escaped to
SELECT full_name, city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE id = 36);

-- Accomplice is the person he called
SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE caller =
(SELECT phone_number FROM people WHERE name = "Bruce") AND day = 28 AND month = 7 AND year = 2021);

-- Accomplice is Robin

-- CASE CLOSED SD/- Sherlock Holmes (i.e. I'm the best)