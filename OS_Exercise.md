Χρήσιμοι Ορισμοί

- <u>Response time (Χρόνος Απόκρισης)</u> = Time at which the process gets the CPU for the first time - Arrival time = Start time - Arrival time
- <u>Waiting time (Χρόνος Αναμονής)</u> = Turn_around Time - Burst time = Time spend in ready queue
- <u>Burst time("Χρονος/Διαρκεια Ολοκληρωσης")</u> = Total  time taken by the process for its execution on the CPU.
- <u>Arrival time(Χρόνος Άφιξης)</u> =Τhe time when a process enters into the ready state(ίσως το ready queue) and is ready for its execution.
- <u>Turn_around time(Χρόνος Διαικπεραίωσης)</u> = Turnaround time is the total amount of time spent by the process from coming in the ready state for the first time to its completion = (Burst time + Waiting time) = **Exit/Completion time - Arrival time**



Δεδομένα

| Διαδικασία | Χρόνος Άφιξης | Χρόνος Ολοκλήρωσης | Προτεραιότητα |
| :--------: | :-----------: | :----------------: | :-----------: |
|     P1     |       0       |         5          |       3       |
|     P2     |       1       |         6          |       5       |
|     P3     |       3       |         2          |       2       |
|     P4     |       9       |         4          |       1       |
|     P5     |      12       |         3          |       4       |

$$
TAT = CT - AT \\
WT = TAT - BT \\
RT = ST - AΤ \\
$$



### FCFS(First Come First Serve)

**First Come First Serve (FCFS)** is an operating system scheduling algorithm that automatically executes queued requests and processes in order of their arrival.

| Gantt |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   | 10   |  11  | 12   |  13  |  14  |  15  |  16  |  17  |  18  |  19  |  20  |
| ----- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | ---- | :--: | ---- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|       |  P1  |  P1  |  P1  |  P1  |  P1  |  P2  |  P2  |  P2  |  P2  | P2   |  P2  | P3   |  P3  |  P4  |  P4  |  P4  |  P4  |  P5  |  P5  |  P5  |

|                      |  P1   |   P2    |   P3    |   P4    |   P5    |
| :------------------: | :---: | :-----: | :-----: | :-----: | :-----: |
| Χρόνος Διακπεραίωσης | 5-0=5 | 11-1=10 | 13-3=10 | 17-9=8  | 20-12=8 |
|   Χρόνος Αναμονής    | 5-5=0 | 10-6=4  | 10-2=8  | 8-4 = 4 |  8-3=5  |
|  Αριθμός εναλλαγών   |   0   |    0    |    0    |    0    |    0    |

Παρατήρησεις:



### Priority based preemtive (PP)

**Priority Scheduling** is a method of scheduling processes that is based on priority. In this algorithm, the scheduler selects the tasks to work as per the priority.

| Gantt |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   | 10   |  11  | 12   |  13  |  14  |  15  |  16  |  17  |  18  |  19  |  20  |
| ----- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | ---- | :--: | ---- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|       |  P1  |  P2  |  P2  |  P2  |  P2  |  P2  |  P2  |  P1  |  P1  | P1   |  P1  | P3   |  P5  |  P5  |  P5  |  P3  |  P4  |  P4  |  P4  |  P4  |

|                      |   P1    |  P2   |          P3           |    P4    |   P5    |
| :------------------: | :-----: | :---: | :-------------------: | :------: | :-----: |
| Χρόνος Διακπεραίωσης | 11-0=11 | 7-1=6 |        16-3=13        | 20-9=11  | 15-12=3 |
|   Χρόνος Αναμονής    | (7-1)=6 |   0   | (11-3)+(15-12)=8+3=11 | (16-9)=7 |    0    |
|  Αριθμός εναλλαγών   |    0    |   0   |           1           |    0     |    0    |

### Shortest Remaining Time First (SRTF)

This Algorithm is the **preemptive version** of **SJF(Sortest Job First) scheduling**. In SRTF, the execution of the process can be stopped after certain amount of time. At the arrival of every process, the short term scheduler schedules the process with the least remaining burst time among the list of available processes and the running process.

If burst times of 2 processes are the same, the process which will be executed is the one with higher priority

| Gantt |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   | 10   |  11  | 12   |  13  |  14  |  15  |  16  |  17  |  18  |  19  |  20  |
| ----- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | ---- | :--: | ---- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|       |  P1  |  P1  |  P1  |  P1  |  P1  |  P3  |  P3  |  P2  |  P2  | P2   |  P2  | P2   |  P2  |  P5  |  P5  |  P5  |  P4  |  P4  |  P4  |  P4  |

|                      |  P1   |    P2     |   P3    |    P4    |     P5     |
| :------------------: | :---: | :-------: | :-----: | :------: | :--------: |
| Χρόνος Διακπεραίωσης | 5-0=5 |  13-1=12  |  7-3=4  | 20-9=11  |  16-12=4   |
|   Χρόνος Αναμονής    |   0   | (7-1) = 6 | (5-3)=2 | (16-9)=7 | (13-12)= 1 |
|  Αριθμός εναλλαγών   |   0   |     0     |    0    |    0     |     0      |

### Round Robin (RR)

Round Robin is a CPU scheduling algorithm where each process is assigned a fixed time slot in a cyclic way.

| Gantt |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   | 10   |  11  | 12   |  13  |  14  |  15  |  16  |  17  |  18  |  19  |  20  |
| ----- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | ---- | :--: | ---- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|       |  P1  |  P2  |  P1  |  P2  |  P3  |  P1  |  P2  |  P3  |  P1  | P2   |  P4  | P1   |  P2  |  P4  |  P5  |  P2  |  P4  |  P5  |  P4  |  P5  |

|                      |  P1  |  P2  |  P3  |  P4  |  P5  |
| :------------------: | :--: | :--: | :--: | :--: | :--: |
| Χρόνος Διακπεραίωσης |      |      |      |      |      |
|   Χρόνος Αναμονής    |      |      |      |      |      |
|  Αριθμός εναλλαγών   |      |      |      |      |      |