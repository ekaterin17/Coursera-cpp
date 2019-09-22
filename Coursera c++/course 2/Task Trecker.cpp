//#include <iostream>
//#include <string>
//#include <map>
//
//using namespace std;
//
//// Перечислимый тип для статуса задачи
//enum class TaskStatus {
//    NEW,          // новая
//    IN_PROGRESS,  // в разработке
//    TESTING,      // на тестировании
//    DONE          // завершена
//};
//
//// Объявляем тип-синоним для map<TaskStatus, int>,
//// позволяющего хранить количество задач каждого статуса
//using TasksInfo = map<TaskStatus, int>;
//
//class TeamTasks {
//public:
//    // Получить статистику по статусам задач конкретного разработчика
//    const TasksInfo& GetPersonTasksInfo(const string& person) const {
//        return PersonTasks.at(person);
//    }
//
//    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
//    void AddNewTask(const string& person) {
//        PersonTasks[person][TaskStatus::NEW] += 1;
//    }
//
//    // Обновить статусы по данному количеству задач конкретного разработчика,
//    // подробности см. ниже
//    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
//        TasksInfo upgrade;
//        TasksInfo update;
//        TasksInfo untouched;
//        auto& taskInfo = PersonTasks[person];
//        for (auto& item : taskInfo) {
//            if (item.first == TaskStatus::NEW && item.second > 0) {
//                int newTasksCount = item.second;
//                while (task_count > 0 && newTasksCount > 0) {
//                    upgrade[TaskStatus::IN_PROGRESS] += 1;
//                    update[TaskStatus::IN_PROGRESS] += 1;
//                    newTasksCount -= 1;
//                    task_count -= 1;
//                }
//                if (newTasksCount > 0) {
//                    untouched[TaskStatus::NEW] += newTasksCount;
//                    upgrade[TaskStatus::NEW] += newTasksCount;
//                }
//            }
//            if (item.first == TaskStatus::IN_PROGRESS && item.second > 0) {
//                int inProgressTasksCount = item.second;
//                while (task_count > 0 && inProgressTasksCount > 0) {
//                    upgrade[TaskStatus::TESTING] += 1;
//                    update[TaskStatus::TESTING] += 1;
//                    inProgressTasksCount -= 1;
//                    task_count -= 1;
//                }
//                if (inProgressTasksCount > 0) {
//                    untouched[TaskStatus::IN_PROGRESS] += inProgressTasksCount;
//                    upgrade[TaskStatus::IN_PROGRESS] += inProgressTasksCount;
//                }
//            }
//            if (item.first == TaskStatus::TESTING && item.second > 0) {
//                int testingTasksCount = item.second;
//                while (task_count > 0 && testingTasksCount > 0) {
//                    upgrade[TaskStatus::DONE] += 1;
//                    update[TaskStatus::DONE] += 1;
//                    testingTasksCount -= 1;
//                    task_count -= 1;
//                }
//                if (testingTasksCount > 0) {
//                    untouched[TaskStatus::TESTING] += testingTasksCount;
//                    upgrade[TaskStatus::TESTING] += testingTasksCount;
//                }
//            }
//            if (item.first == TaskStatus::DONE && item.second > 0) {
//                upgrade[TaskStatus::DONE] += item.second;
//            }
//
//        }
//        PersonTasks[person] = upgrade;
//        return make_tuple(update,untouched);
//    }
//
//private:
//    map<string, TasksInfo> PersonTasks;
//};
//
//
//
//// Принимаем словарь по значению, чтобы иметь возможность
//// обращаться к отсутствующим ключам с помощью [] и получать 0,
//// не меняя при этом исходный словарь
//void PrintTasksInfo(TasksInfo tasks_info) {
//    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
//    ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
//    ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
//    ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
//}
//
//int main() {
//    TeamTasks tasks;
//    tasks.AddNewTask("Ilia");
//    for (int i = 0; i < 3; ++i) {
//        tasks.AddNewTask("Ivan");
//    }
//    cout << "Ilia's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//    cout << "Ivan's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//
//    TasksInfo updated_tasks, untouched_tasks;
//
//    tie(updated_tasks, untouched_tasks) =
//    tasks.PerformPersonTasks("Ivan", 2);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    tie(updated_tasks, untouched_tasks) =
//    tasks.PerformPersonTasks("Ivan", 2);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    return 0;
//}
