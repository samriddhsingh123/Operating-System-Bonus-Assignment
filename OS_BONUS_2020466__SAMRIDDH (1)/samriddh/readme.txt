Compiling the programm:
     Go to the directory. Open terminal and type make command in it.
Running the programm:
     Type ./q1, ./q2, ./q3 to run all three programmes respectively.
We used data structure semaphore which is sem_t.
Logic And Implementation:
    In part a we have to ensure that one philoshper must have to forks in his left and right hand.
    We used semaphore(sem_t) to make semaphore. And sem_init to initialize it.
    To do this we created 5 threads namely t1,t2,t3,t4,t5 where we handled all 5 function related to each philoshpher
    In each function we implement waiting using the call named sem_wait(it return zero if it successfully decrement the semaphore) which decrements the semaphore.
    If the semaphore value is not greater than zero,
    then the calling process blocks until it can decrement the counter, or the call is interrupted by signal.
    We waited(for fork) in such a way that philoshpher would not be in cyclic order(means fork not be in consecutive order) so I set as (1,2) for philoshpher 1,
    (3,2) for philoshpher2, (4,3) for philoshpher 3, (5,4) for philoshpher 4, (1,5) for philoshpher 5.
    And we did same for signal using sem_post. It increement the semaphore.
    If any processes are currently blocked waiting for the semaphore, then one of these processes will return successfully from its call to sem_wait.

    In part 2:
        We have to access any one fork so there is no any need to handle this as we have 5 forks already.
        But for bowl we created semaphore for it and handlled(wait and signal) it with only 1 wait and 1 sem_post
        as we need only one bowl at one time. Since there are four sauce bowl so at each time it is sure at
        least one philoshpher will be able to take that bowl so there is no deadlock in this case.

    In part 3:
        In this case we need to access  two forks as well as bowl to eat so we made one more semaphore variable in this case.
        And implent 3 wait and sem_post: two for fork and 1 for bowl.
        And rest of them are same as 1st