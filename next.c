const int MAXJOB=50; // maximum number of jobs
//data structure of jobs
typedef enum { false, true } bool;
typedef struct node
{
    int number; // job number
    int reach_time;// arrival time
    int need_time;// execution time
    int privilege;// priority
    float excellent;// response ratio
    int start_time;// start time
    int wait_time;// waiting time
    int visited;// if the job is accessed
    bool isreached;// if the job has arrived
}
job;
job jobs[MAXJOB];//job sequence