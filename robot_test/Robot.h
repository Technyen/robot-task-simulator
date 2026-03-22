#pragma once
#include <queue>
#include <string>

// Represents a task with a target position
struct Task {
    int x;
    int y;
};

class Robot {
private:
    int x;  // current X position
    int y;  // current Y position
    std::queue<Task> tasks; // task queue

public:
    Robot();

    // Moves one step in a direction
    void move(std::string direction);

    // Moves to a target position
    void moveTo(int targetX, int targetY);

    // Adds a task to the queue
    void addTask(int targetX, int targetY);

    // Processes all tasks
    void processTasks();
};