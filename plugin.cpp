#include "plugin.h"
#include "acfutils/dr_cmd_reg.h"
#include "acfutils/log.h"
#include "acfutils/thread.h"

static void
log_dbg_string(const char *str)
{
    XPLMDebugString(str);
}

static float 
floop(float elapsed1, float elapsed2, int counter, void *refcon);

static void
new_main(void *args)
{
    
};

PLUGIN_API int XPluginStart
(
    char * outName,
    char * outSig,
    char * outDesc
)
{
    strcpy(outName, "Plugin");
    strcpy(outSig, "omi.MTplugin.test");
    strcpy(outDesc, "multithreading test");

    log_init(log_dbg_string,"OMI MultiThreading Test");

    dcr_init();
    
    thread_t my_thread;
    thread_create(&my_thread, new_main, NULL);
    if (!thread_create(&my_thread, new_main, NULL))
    fprintf(stderr, "thread create failed!\n");
    mutex_init(&state_lock);



    return 1;
}

PLUGIN_API int XPluginEnable(void)
{
    new_main();
    return 1;
}

PLUGIN_API void XPluginDisable(void)
{

}

PLUGIN_API void XPluginStop()
{
    mutex_destroy(&state_lock);
    dcr_fini();
    log_fini();
}