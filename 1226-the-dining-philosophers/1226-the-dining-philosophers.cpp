class DiningPhilosophers {
public:
    mutex forks[5];

    void wantsToEat(
        int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork
    ) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        // Lock both forks without deadlock
       lock(forks[left], forks[right]);

        // Now both forks are ours
        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

        forks[left].unlock();
        forks[right].unlock();
    }
};