// robot_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <queue>
#include <thread>
#include <chrono>

using namespace std;
struct Task {
    int x;
    int y;
};


class Robot {
private:
    int x;
    int y;
    queue<Task> tasks;

public:
    Robot() {
        x = 0;
        y = 0;
    }

    void move(string direction) {
        if (direction == "up") y++;
        else if (direction == "down") y--;
        else if (direction == "left") x--;
        else if (direction == "right") x++;

        cout << "[STEP] Robot position: (" << x << ", " << y << ")" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    void moveTo(int targetX, int targetY) {
        cout << "[INFO] Moving to (" << targetX << ", " << targetY << ")" << endl;

        while (x != targetX) {
            cout << "Moviendo en X..." << endl;
            if (x < targetX) move("right");
            else move("left");
        }
        while (y != targetY) {
            cout << "Moviendo en Y..." << endl;
            if (y < targetY) move("up");
            else move("down");
        }

        cout << "Lleg¨® al destino!" << endl;
    }

    void addTask(int targetX, int targetY) {
        tasks.push({ targetX, targetY });
    }

    void processTasks() {
        while (!tasks.empty()) {
            Task t = tasks.front();
            tasks.pop();

            moveTo(t.x, t.y);
        }
    }
};

int main() {
    cout << "Inicio del programa" << endl;

    Robot robot;

    robot.addTask(3,2);
    robot.addTask(0,0);
    robot.addTask(2,1);

    robot.processTasks();

    system("pause");
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
