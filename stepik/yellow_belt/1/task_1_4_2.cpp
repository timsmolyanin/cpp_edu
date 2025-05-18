
#include <tuple>
#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};
  
// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    TeamTasks(string person, int newt, int inprog, int testing, int done){
        persons_tasks_db[person][TaskStatus::NEW] = newt;
        persons_tasks_db[person][TaskStatus::IN_PROGRESS] = inprog;
        persons_tasks_db[person][TaskStatus::TESTING] = testing;
        persons_tasks_db[person][TaskStatus::DONE] = done;
    }
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return persons_tasks_db.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person){
        if (persons_tasks_db.count(person) == 1){
            ++persons_tasks_db[person][TaskStatus::NEW];
        }
        else{
            persons_tasks_db[person] = {
                {TaskStatus::NEW, 1},
                {TaskStatus::IN_PROGRESS, 0},
                {TaskStatus::TESTING, 0},
                {TaskStatus::DONE, 0}
            };
        }
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
        if (task_count > GetUndoneTasks(person)){
            task_count = GetUndoneTasks(person);
        }
        map<string, TasksInfo> tmp_persons_tasks_db = persons_tasks_db;

        TasksInfo updated_tasks = {
            {TaskStatus::NEW, 0},
            {TaskStatus::IN_PROGRESS, 0},
            {TaskStatus::TESTING, 0},
            {TaskStatus::DONE, 0}
        };
        
        TasksInfo untouched_tasks = {
            {TaskStatus::NEW, 0},
            {TaskStatus::IN_PROGRESS, 0},
            {TaskStatus::TESTING, 0},
            {TaskStatus::DONE, 0}
        };

        while (task_count != 0){
            if (persons_tasks_db[person][TaskStatus::NEW] > 0){
                // from NEW -> IN_PROGRESS
                --persons_tasks_db[person][TaskStatus::NEW];
                ++persons_tasks_db[person][TaskStatus::IN_PROGRESS];
                ++updated_tasks[TaskStatus::IN_PROGRESS];
            }
            else if (persons_tasks_db[person][TaskStatus::IN_PROGRESS] > 0){
                // from IN_PROGRESS -> TESTING
                --persons_tasks_db[person][TaskStatus::IN_PROGRESS];
                ++persons_tasks_db[person][TaskStatus::TESTING];
                ++updated_tasks[TaskStatus::TESTING];

            }
            else if (persons_tasks_db[person][TaskStatus::TESTING] > 0){
                // from TESTING -> DONE
                --persons_tasks_db[person][TaskStatus::TESTING];
                ++persons_tasks_db[person][TaskStatus::DONE];
                ++updated_tasks[TaskStatus::DONE];
            }
            --task_count;
        }

        untouched_tasks[TaskStatus::NEW] = persons_tasks_db[person][TaskStatus::NEW] - updated_tasks[TaskStatus::NEW];
        untouched_tasks[TaskStatus::IN_PROGRESS] = persons_tasks_db[person][TaskStatus::IN_PROGRESS] - updated_tasks[TaskStatus::IN_PROGRESS];
        untouched_tasks[TaskStatus::TESTING] = persons_tasks_db[person][TaskStatus::TESTING] - updated_tasks[TaskStatus::TESTING];

        // Удаляем нулевые элементы и DONE из untouched
        RemoveZeros(updated_tasks);
        RemoveZeros(untouched_tasks);
        untouched_tasks.erase(TaskStatus::DONE);

        return {updated_tasks, untouched_tasks};

    }   


private:
    map<string, TasksInfo> persons_tasks_db;

    int GetUndoneTasks(const string& person){
        int undone_tasks_cnt =  persons_tasks_db[person][TaskStatus::NEW] + 
                                persons_tasks_db[person][TaskStatus::IN_PROGRESS] + 
                                persons_tasks_db[person][TaskStatus::TESTING];
        
        return undone_tasks_cnt;
    }
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

    TeamTasks tasks("Ivan", 3, 2, 4, 1);
    
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 4);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}