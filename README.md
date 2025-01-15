# Philosophers

## Overview
**Philosophers** is a project inspired by the classic "Dining Philosophers Problem," which illustrates the challenges of managing shared resources in a concurrent environment. The goal is to implement a solution where philosophers (threads) alternate between eating, thinking, and sleeping while avoiding deadlocks and resource starvation.

This project enhances your understanding of concurrency, multithreading, and synchronization mechanisms in C.

---

## Features
- **Thread-based Simulation**: Each philosopher is represented as a thread.
- **Shared Resources**: Forks (chopsticks) are shared between philosophers, requiring careful synchronization.
- **State Management**: Philosophers alternate between eating, thinking, and sleeping.
- **Concurrency Issues**: Avoids deadlocks and resource starvation using synchronization techniques.

---

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/philosophers.git
   cd philosophers

2. Build the project:
    ```bash
    make
    ```
    This will create the philo executable.

## Usage

Run the program with the following arguments:
   ```bash
   ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
   ```
**Arguments:**
- `number_of_philosophers:` Number of philosophers and forks (≥ 1).
- `time_to_die:` Time (in milliseconds) a philosopher can live without eating.
- `time_to_eat:` Time (in milliseconds) it takes for a philosopher to eat.
- `time_to_sleep:` Time (in milliseconds) a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat (optional):` Simulation ends when all philosophers have eaten this many times.

### Example:
   ```bash
   ./philo 5 800 200 200
   ```
**Output:**
   ```bash
   0ms 1 has taken a fork
   0ms 1 has taken a fork
   0ms 1 is eating
   200ms 1 is sleeping
   ```

## Rules:
1. A philosopher must pick up two forks to eat.
2. A philosopher alternates between:
- Thinking: Waiting to pick up forks.
- Eating: Consuming food with both forks in hand.
- Sleeping: Resting after eating.
3. If a philosopher does not eat within time_to_die, they die.
4. The simulation ends when:
- A philosopher dies, or
- All philosophers have eaten the specified number of times (if provided).

