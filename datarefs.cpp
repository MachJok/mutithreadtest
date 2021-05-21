#include "datarefs.h"
#include "acfutils/dr.h"
#include "acfutils/thread.h"

dr_t SIM_runtime;

void find_datarefs()
{
    fdr_find(&SIM_runtime, "sim/time/total_running_time_sec");
}

void get_datarefs()
{
    state_t state_new = {};
    state_new.timestamp = dr_getf_prot(&SIM_runtime);
    mutex_enter(&state_lock);
    state_global = state_new;
    mutex_exit(&state_lock);
}