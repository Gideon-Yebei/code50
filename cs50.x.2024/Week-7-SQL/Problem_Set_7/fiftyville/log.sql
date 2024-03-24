-- Keep a log of any SQL queries you execute as you solve the mystery.
--
-- What I Know
-- Crime Date: July 28
-- Crime Scene: Humphrey Street
--
-- Goal
-- Who the thief is
-- What city the thief escaped to
-- Who the thief's accomplice is (who helped them escape)
--
-- Step 1
-- Find crime scene description
SELECT
	description
FROM
	crime_scene_reports
WHERE
	month = 7
	AND day = 28
	AND street = 'Humphrey Street';

-- Time of crime: 10:15am
-- Place of crime: Humphrey Street bakery
-- Witness: 3 Witnesses
-- Description: The bakery Littering took place at 16:36.
--
-- Step 2
-- Take a look at the bakery security logs to see if I can find any clues about the thief
SELECT *
FROM
	bakery_security_logs
WHERE
	month = 7
	AND day = 28
	AND hour = 10
	AND minute BETWEEN 10 AND 20;

-- Step 3
-- Find the information about the car that was parked in front of the bakery and the person who was driving it
SELECT DISTINCT
	people.name,
	people.license_plate
FROM
	people
	JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE
	month = 7
	AND day = 28
	AND hour = 10
	AND minute BETWEEN 10 AND 20;

-- Step 4
-- Look for phone calls made by the thief
SELECT
	phone_calls.caller,
	phone_calls.receiver,
	phone_calls.duration
FROM
	phone_calls
WHERE
	month = 7
	AND day = 28;
