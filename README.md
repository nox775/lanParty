# Tournament Management System

## Description
This program manages a tournament by reading input files containing team and match data, processing the matches, and generating outputs related to team rankings and performance. It utilizes various data structures like linked lists, queues, stacks, binary search trees (BST), and AVL trees to efficiently manage and process tournament data.

## Features
- **Team Management**: Reads and processes team data from input files.
- **Match Processing**: Simulates matches and determines winners based on predefined criteria.
- **Data Structures**: Implements linked lists, queues, stacks, BSTs, and AVL trees for efficient data handling.
- **Ranking System**: Computes and displays rankings of teams based on performance.
- **File Handling**: Reads input from files and writes results to output files.

## File Structure
```
├── headers/
│   ├── main.h
│   ├── taskFunctions.h
│   ├── liste.h
│   ├── stack.h
│   ├── queue.h
│   ├── BSTree.h
│   ├── AVLtree.h
├── source/
│   ├── main.c
│   ├── taskFunctions.c
│   ├── liste.c
│   ├── stack.c
│   ├── queue.c
│   ├── BSTree.c
│   ├── AVLtree.c
├── data_in/
│   ├── c.in
│   ├── d.in
├── data_out/
│   ├── r.out
├── Makefile
```

## Installation & Compilation

### Prerequisites
- C compiler (e.g., gcc)
- Standard C libraries

### Compilation Command
To compile the application, use the Makefile:
```sh
make
```

### Running the Application
```sh
./tournament c.in d.in r.out
```

### Cleaning Up
To remove the compiled binary:
```sh
make clean
```

## Usage Guide
1. **Input Files**
   - `c.in`: Contains task execution flags.
   - `d.in`: Contains teams and player data.
2. **Processing Flow**
   - Reads and stores team data.
   - Executes tournament rounds based on tasks.
   - Uses BST and AVL trees for ranking.
3. **Output File**
   - `r.out`: Stores final results and rankings.

## Data Structures Used
- **Linked List**: Stores teams dynamically.
- **Queue**: Handles match processing.
- **Stack**: Stores match winners and losers.
- **BST (Binary Search Tree)**: Sorts teams based on points.
- **AVL Tree**: Balances team rankings for efficient search.

## Contributing
Feel free to improve the project, fix bugs, or optimize performance.

## License
This project is open-source and free to use under the MIT License.

