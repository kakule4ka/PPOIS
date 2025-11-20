#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    std::string taskId;
    std::string description;
    int estimatedHours;
    int actualHours;
    
public:
    Task(const std::string& id, const std::string& description, int estimatedHours);
    
    double calculateEfficiency() const;
    bool isOverdue() const;
    
    std::string getId() const { return taskId; }
    void setActualHours(int hours) { actualHours = hours; }
};

#endif
