# semaphore
when int value is bigger than 0, thread executes following code  
cant be below 0 -> if 0 then it will be blocked
doesnt work together with condition variables  
- sem_wait -> subtracts 1 if value is > than 0
- sem_post -> adds 1
- sem_t

### idea example
5 machines -> 10 customer
use sem_t to represent the 5 machines


# mutex

# conditon variable