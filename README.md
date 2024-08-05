# Philosophers - Concurrency Simulation

## Overview

This project simulates the classic "Dining Philosophers" problem to explore concurrency issues such as deadlock and starvation. The simulation involves philosophers sitting at a round table, eating spaghetti, thinking, and sleeping. Philosophers need two forks to eat, which they take from their left and right. The simulation stops when a philosopher dies of starvation or when all philosophers have eaten a specified number of times.

## Features

- **Concurrency Management**: Implement philosophers first as threads, then as processes to simulate concurrent actions.
- **Fork Management**: Use mutexes with threads, and semaphores with processes to manage fork usage and avoid conflicts.
- **State Logging**: Log the state changes of each philosopher with precise timestamps.
- **Death Detection**: Detect and log philosopher death due to starvation within a specified time frame.

## Arguments

The program takes the following command-line arguments:

1. `number_of_philosophers`: The number of philosophers and forks.
2. `time_to_die`: Time in milliseconds before a philosopher dies if they don't start eating.
3. `time_to_eat`: Time in milliseconds a philosopher spends eating.
4. `time_to_sleep`: Time in milliseconds a philosopher spends sleeping.
5. `[number_of_times_each_philosopher_must_eat]` (optional): The simulation stops when all philosophers have eaten at least this many times. If not specified, the simulation stops when a philosopher dies.

## Getting started

1. Clone the repository:
   ```sh
   git clone <repository-url>

2. Compile the project (philosophers as threads):
   ```sh
   make

3. Run the project (philosophers as threads):
   ```sh
   ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

4. Compile the project (philosophers as processes):
   ```sh
   make bonus

5. Run the project (philosophers as processes):
   ```sh
   ./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

## Acknowledgements

- The 42 School for providing the project specifications and environment.
