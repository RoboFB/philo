


# Programming:
- [x] parsing
    - [x] check input
    - [x] save input
    - [x] return error


- [x] threads
- [x] mutex
- [x] philes
- [x] print logs
- [ ] error handeling
- [ ] 1 philo test if fork left == right thaen make spacel and error/exit
- [ ] timing is ov somehowe check it
- [ ] improve error hadeling and clean the logig up
- [ ] printf errors in writtes to stderr (2) umwandeln
- [ ] clean up code
- [ ] ./philo 199 190 60 60 50
- [ ] ./philo 200 130 60 60 50





<!-- # Testers -->

## Functions
### NOT allowed
libft
exit (schade)


### allowed
malloc, free, memset    (memory)  
write, printf           (printing)  
usleep, gettimeofday,   (time)  

pthread_create,         (pthread)  
pthread_join,  
pthread_detach,  

pthread_mutex_init,     (mutex make)  
pthread_mutex_destroy,  

pthread_mutex_lock,     (mutex look)  
pthread_mutex_unlock  


## user input
- index:   |     0    |  1    |  2  |  3  |   4   |   (5)
- example: | ./philo  | 100   | 200 | 300 |  400  |  (500)
- type:    |    exe   |  num  | ms  | ms  |   ms  |  (num)
- short:   | programm | count | die | eat | sleep | (end eat)
- all:     | programm | number_of_philosophers | time_to_die | time_to_eat | time_to_sleep | (number_of_times_each_philosopher_must_eat)

---

- need: argc == 5/6

## log output

- timestamp_in_ms X has taken a fork
- timestamp_in_ms X is eating
- timestamp_in_ms X is sleeping
- timestamp_in_ms X is thinking
- timestamp_in_ms X died


## programm abauf


⬇
think(awake)
⬇
eat
⬇
slepp
⬇︎
...


...
dead -> brake and finsh all without another print
...

time_to_die -> time to die: form start to eaten to eaten to eaten to another died or end of simulation
time_to_eat -> how long eat
time_to_sleep -> how long sleep

             2               5                
       X             X               X
🍴  P1 🍴 P2  🍴  P3  🍴  P4  🍴  P5  🍴  P6  




             2               4                
       X             X               X
🍴  P1 🍴 P2  🍴  P3  🍴  P4  🍴  P5  🍴  P6  


## Feedback


---
# Over all doku

## coments:
// R: (0)ok  (-1)Error   | parses argc and argv

## git commit cheat chett
1. feat: A new feature
2. fix: A bug fix
3. build: build system like akefile or ci/cl
4. docs: Documentation only changes
5. refactor: A code change that neither fixes a bug nor adds a feature
6. style: Changes that do not affect the meaning of the code (white-space, formatting, missing semi-colons, etc)
7. perf: A code change that improves performance
8. test: Adding missing tests














- [] Norm
- [] no leaks
- [] no crash, no undefined behavior
- [] no Global variables
- [] one thread per philosopher
- [] only one fork per philosopher
- [] a mutex per fork and that it's used to check the fork value and/or change
- [] outputs are never mixed
- []
- []
- []
- []





Check how the death of a philosopher is verified and if there is a mutex to prevent a philosopher from dying and starting eating at the same time.

Do not test with more than 200 philosophers.
Do not test with time_to_die or time_to_eat or time_to_sleep set to values lower than 60 ms.
Test 1 800 200 200. The philosopher should not eat and should die.
Test 5 800 200 200. No philosopher should die.
Test 5 800 200 200 7. No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.
Test 4 410 200 200. No philosopher should die.
Test 4 310 200 100. One philosopher should die.
Test with 2 philosophers and check the different times: a death delayed by more than 10 ms is unacceptable.
Test with any values of your choice to verify all the requirements. Ensure philosophers die at the right time, that they don't steal forks, and so forth.