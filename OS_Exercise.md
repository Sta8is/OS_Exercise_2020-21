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

| Gantt |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   | 10   |  11  | 12   |  13  |  14  |  15  |  16  |  17  |  18  |  19  |  20  |
| ----- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | ---- | :--: | ---- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|       |  P1  |  P1  |  P1  |  P1  |  P1  |  P2  |  P2  |  P2  |  P2  | P2   |  P2  | P3   |  P3  |  P4  |  P4  |  P4  |  P4  |  P5  |  P5  |  P5  |

|                                     |  P1   |   P2    |   P3    |   P4    |   P5    |
| :---------------------------------: | :---: | :-----: | :-----: | :-----: | :-----: |
|        Χρόνος Διακπεραίωσης         | 5-0=5 | 11-1=10 | 13-3=10 | 17-9=8  | 20-12=8 |
|           Χρόνος Αναμονής           | 5-5=0 | 10-6=4  | 10-2=8  | 8-4 = 4 |  8-3=5  |
| Χρόνος Απόκρισης??(Αντί  Συνολικός) |       |         |         |         |         |
|          Αριθμός εναλλαγών          |   0   |    0    |    0    |    0    |    0    |

Παρατήρησεις:

