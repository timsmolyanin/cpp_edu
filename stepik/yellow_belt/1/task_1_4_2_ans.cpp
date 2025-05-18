#include <tuple>
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum class TaskStatus {
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
};

using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
private:
    map<string, TasksInfo> persons_tasks_db;

    void RemoveZeros(TasksInfo& tasks) {
        vector<TaskStatus> to_remove;
        for (const auto& [status, count] : tasks) {
            if (count == 0) {
                to_remove.push_back(status);
            }
        }
        for (TaskStatus status : to_remove) {
            tasks.erase(status);
        }
    }

public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return persons_tasks_db.at(person);
    }

    void AddNewTask(const string& person) {
        persons_tasks_db[person][TaskStatus::NEW]++;
    }

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        TasksInfo& tasks = persons_tasks_db[person];
        TasksInfo initial = tasks;

        // Считаем общее количество невыполненных задач
        int total_undone = 0;
        for (const auto& [status, count] : initial) {
            if (status != TaskStatus::DONE) {
                total_undone += count;
            }
        }
        task_count = min(task_count, total_undone);

        // Определяем, сколько задач переместить из каждого статуса
        vector<TaskStatus> order = {TaskStatus::NEW, TaskStatus::IN_PROGRESS, TaskStatus::TESTING};
        map<TaskStatus, int> moved;
        
        // 4
        /*
        NEW: 3
        INP: 1
        TEST: 1
        DONE: 1
        */

        // task_count = 4
        for (TaskStatus status : order) { // IN_PROGRESS
            if (task_count <= 0) break;
            int available = initial[status]; // 1
            if (available == 0) continue;
            int move = min(available, task_count); // 1
            moved[status] = move; // IN_PROGRESS = 1
            task_count -= move; // task_count = 0
        }

        // Обновляем текущие задачи
        for (const auto& [status, count] : moved) {
            tasks[status] -= count;
            TaskStatus next_status = static_cast<TaskStatus>(static_cast<int>(status) + 1);
            tasks[next_status] += count;
        }

        // Формируем обновленные и необновленные задачи
        TasksInfo updated, untouched;

        for (const auto& [status, count] : moved) {
            TaskStatus next = static_cast<TaskStatus>(static_cast<int>(status) + 1);
            updated[next] += count;
        }

        for (TaskStatus status : order) {
            int initial_count = initial[status];
            int moved_count = moved.count(status) ? moved[status] : 0;
            int remaining = initial_count - moved_count;
            if (remaining > 0) {
                untouched[status] = remaining;
            }
        }

        // Удаляем нулевые элементы и DONE из untouched
        RemoveZeros(updated);
        RemoveZeros(untouched);
        untouched.erase(TaskStatus::DONE);

        return {updated, untouched};
    }
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}