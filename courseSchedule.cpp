#include <vector>

class CourseSchedule
{
private:
    std::vector<std::vector<int>> courses;
    std::vector<int> memo;
public:
    CourseSchedule() {}
    CourseSchedule(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        courses.resize(numCourses);
        memo.resize(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            courses[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
    }
    bool isPossible()
    {
        for (int i = 0; i < courses.size(); ++i)
        {
            if (!courses[i].empty() && !memo[i])
            {
                if (!checkPrereqs(i)) { return false; }
            }
        }
        return true;
    }
    bool checkPrereqs(int courseNumber)
    {
        if (memo[courseNumber] == -1) { return false;}
        if ( memo[courseNumber] == 1) { return true; } 
        memo[courseNumber] = -1;
        for (int i = 0; i < courses[courseNumber].size(); ++i)
        {
            if (!checkPrereqs(courses[courseNumber][i])) { return false; }
        }
        memo[courseNumber] = 1;
        return true;
    }
};

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
    CourseSchedule mySchedule(numCourses, prerequisites);
    return mySchedule.isPossible();
}