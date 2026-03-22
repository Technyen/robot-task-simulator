#include "Robot.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Constructor: initialize robot at (0,0)
Robot::Robot() {
    x = 0;
    y = 0;
}

// Move one step in a direction
void Robot::move(string direction) {
    if (direction == "up") y++;
    else if (direction == "down") y--;
    else if (direction == "left") x--;
    else if (direction == "right") x++;

    cout << "[STEP] Position: (" << x << ", " << y << ")" << endl;

    // Simulate delay
    this_thread::sleep_for(chrono::milliseconds(300));
}

// Move step-by-step to target position
void Robot::moveTo(int targetX, int targetY) {
    cout << "[INFO] Moving to (" << targetX << ", " << targetY << ")" << endl;

    while (x != targetX) {
        if (x < targetX) move("right");
        else move("left");
    }

    while (y != targetY) {
        if (y < targetY) move("up");
        else move("down");
    }

    cout << "[INFO] Reached destination!" << endl << endl;
}

// Add a task to the queue
void Robot::addTask(int targetX, int targetY) {
    tasks.push({ targetX, targetY });
}

// Process all tasks
void Robot::processTasks() {
    while (!tasks.empty()) {
        Task t = tasks.front();
        tasks.pop();

        moveTo(t.x, t.y);
    }
}
//Entry point: receives target position from command line
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: Robot.exe <x> <y>" << endl;
        return 1;
    }

    int x = stoi(argv[1]);
    int y = stoi(argv[2]);

    Robot robot;
    robot.moveTo(x, y);

    return 0;
}