# Discrete-time-simulation-
This project involves the development of a queuing system using various queuing algorithms: First In, First Out (FIFO), Shortest Job First (SJF), and a Multi-Level Priority Queue. The system is implemented in C++ and aims to analyze the performance of each queuing algorithm by applying them to a selected dataset.

## Queuing Algorithms

### 1. First In, First Out (FIFO)
The FIFO algorithm follows a simple principle: the first item that arrives is the first one to be served. It maintains a queue of tasks or processes and processes them in the order of their arrival.

### 2. Shortest Job First (SJF)
The SJF algorithm prioritizes the tasks or processes based on their burst time. It selects the process with the shortest burst time first, ensuring the execution of the shortest job at any given time.

### 3. Multi-Level Priority Queue
The Multi-Level Priority Queue is a queuing algorithm that assigns different priorities to different queues. Each queue may have its own scheduling algorithm, such as FIFO or SJF, and tasks are placed in the appropriate queue based on their priority level. The scheduler chooses tasks from the highest priority queue, ensuring that higher priority tasks are executed first.

## Dataset Analysis

The selected dataset is passed through each queuing algorithm to determine the runtime and wait time of each queue. By applying the queuing algorithms to the dataset, we can observe how each algorithm performs in terms of execution time and efficiency.

## Implementation Details

The queuing system is implemented in C++, taking advantage of its features for efficient data handling and algorithm implementation. The system consists of different modules or classes for each queuing algorithm, along with any necessary data structures, such as queues or priority queues, to manage the tasks or processes.

**To use the queuing system:**

1. Ensure you have a C++ compiler installed on your system.

2. Clone the project repository or download the source code files.

3. Open the project in your preferred C++ development environment.

4. Compile and build the project to generate the executable file.

5. Run the executable, providing the necessary input dataset.

6. Observe the output, which will include the runtime and wait time of each queue for each queuing algorithm.

Feel free to experiment with different datasets and observe the performance differences among the queuing algorithms.

## Future Improvements

The queuing system can be further enhanced by incorporating additional queuing algorithms or optimizing the existing ones. Additionally, visualizations or graphical representations can be added to help analyze and compare the performance of different queuing algorithms.
