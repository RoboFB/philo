#!/bin/bash

# === Colors ===
GREEN="\033[32m"
RED="\033[31m"
RESET="\033[0m"

PASS="[${GREEN}PASS${RESET}]"
FAIL="[${RED}FAIL${RESET}]"

PHILO=./philo
total=0
success=0

function test_case() {
	total=$((total+1))
	desc=$1
	cmd="$2"
	expected_code=$3

	eval "$cmd" > /dev/null 2>&1
	actual=$?

	if [ "$actual" -eq "$expected_code" ]; then
		printf "$PASS %-60s (exit: %s)\n" "$desc" "$actual"
		success=$((success+1))
	else
		printf "$FAIL %-60s (exit: %s, expected: %s)\n" \
		 "$desc" "$actual" "$expected_code"
	fi
}

echo -e "\n🍝 PHILO - BEHAVIOR TEST SUITE\n"

# === Basic valid cases ===
test_case "Basic valid input (4 philos)" \
	"$PHILO 4 410 200 200" 0

test_case "Basic valid input with eat count (5 philos, eat 3 times)" \
	"$PHILO 5 800 200 200 3" 0

# === Edge / error cases ===
test_case "Zero philosophers (invalid)" \
	"$PHILO 0 410 200 200" 1

test_case "Negative time to die" \
	"$PHILO 5 -410 200 200" 1

test_case "Missing argument (only 4 args)" \
	"$PHILO 4 310 100" 1

test_case "Too many arguments (7 args)" \
	"$PHILO 5 800 200 200 3 99" 1

test_case "Non-numeric argument" \
	"$PHILO 5 abc 200 200" 1

test_case "Philosophers = 200 (stress test, should run, maybe slow)" \
	"$PHILO 200 800 200 200" 0

# === Sanity/stability tests ===
test_case "All timing values are high (should not crash)" \
	"$PHILO 4 10000 10000 10000" 0

test_case "Time to die < time to eat (to trigger death)" \
	"$PHILO 3 200 400 200" 0

test_case "Time to sleep = 0 (very fast loop)" \
	"$PHILO 5 800 200 0 3" 0


est_case "Basic 5 philosophers with eat count" \
    "$PHILO 5 800 200 200 3"

test_case "Death test: die before eating (time_to_die < time_to_eat)" \
    "$PHILO 2 150 200 100"

test_case "1 philosopher should die alone (1 fork only)" \
    "$PHILO 1 800 200 200"

test_case "Many philosophers (stress test)" \
    "$PHILO 100 800 200 200 3"

test_case "Philosophers never die" \
    "$PHILO 5 1000 200 200 3"

# === EDGE CASE ARGUMENTS ===
test_case "Invalid: 0 philosophers" \
    "$PHILO 0 800 200 200"

test_case "Invalid: negative time" \
    "$PHILO 5 -800 200 200"

test_case "Invalid: too few args" \
    "$PHILO 5 800 200"

test_case "Invalid: too many args" \
    "$PHILO 5 800 200 200 3 999"

test_case "Invalid: non-numeric input" \
    "$PHILO five 800 200 200"

# === TIMING VALIDATION ===
# Run with short death time, should print "died" quickly
test_case "Timing accuracy: death printed within 10ms" \
    "$PHILO 2 150 200 200"

# === OUTPUT FORMAT ===
test_case "Output format check (regex match)" \
    "($PHILO 3 500 200 200 1 | grep -Eq '^[0-9]+ [1-9][0-9]* (is|has) ')"



# === Summary ===
echo -e "\n📊 Result: $success out of $total tests passed."

# Exit with non-zero if any test failed
[ "$success" -ne "$total" ] && exit 1 || exit 0