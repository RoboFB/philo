


# Programming:
-[] parsing
	-[OK] check input
	-[OK] save input
	-[OK] return error


-[] threads
-[] mutex
-[] philes
-[] print logs
-[] error handeling





# Testers
-[OK]https://github.com/gmarcha/pipexMedic (for linux env)
-[OK]paco
./pipex infile "ls -l" "wc -l" outfile
< infile ls -l | wc -l >

./pipex input "awk '{print \$0}'" "awk -F=:efe '{count++} END {printf \"lines: %d\", count}'" out

End tests:


gst | cat | cat |cat -e| cat
./pipex 


        < test.txt ls -l | cat -e | cat -e | cat -e > test2.txt
./ pipex test.txt "ls -l" "cat -e" "cat -e" "cat -e" test2.txt

        < test.txt ls -l | cat -e > test2.txt
./ pipex test.txt "ls -l" "cat -e" test2.txt


# NOT allowed functions
libft
exit (schade)


# allowed functions
malloc, free, memset	(memory)
write, printf			(printing)
usleep, gettimeofday,	(time)

pthread_create,			(pthread)
pthread_join,
pthread_detach,

pthread_mutex_init,		(mutex make)
pthread_mutex_destroy,

pthread_mutex_lock,		(mutex look)
pthread_mutex_unlock


# user input
index:   |     0    |  1    |  2  |  3  |   4   |   (5)
example: | ./philo  | 100   | 200 | 300 |  400  |  (500)
type:    |    exe   |  num  | ms  | ms  |   ms  |  (num)
short:   | programm | count | die | eat | sleep | (end eat)
all:     | programm | number_of_philosophers | time_to_die | time_to_eat | time_to_sleep | (number_of_times_each_philosopher_must_eat)

need
argc == 5/6


# log output

◦timestamp_in_ms X has taken a fork
◦timestamp_in_ms X is eating
◦timestamp_in_ms X is sleeping
◦timestamp_in_ms X is thinking
◦timestamp_in_ms X died



# coments:
// R: (0)ok  (-1)Error   | parses argc and argv


# Feedback


# git commit cheat chett

feat: A new feature
fix: A bug fix
docs: Documentation only changes
style: Changes that do not affect the meaning of the code (white-space, formatting, missing semi-colons, etc)
refactor: A code change that neither fixes a bug nor adds a feature
perf: A code change that improves performance
test: Adding missing tests
build: build system like akefile or ci/cl