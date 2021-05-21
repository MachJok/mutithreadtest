#include <XPLMDefs.h>

#include <cstring>

PLUGIN_API int XPluginStart
(
    char * outName,
    char * outSig,
    char * outDesc
)
{
    strcpy(outName, "Plugin");
    strcpy(outSig, "omi.plugin.test");
    strcpy(outDesc, "nonsense plugin");
    return 1;
}

PLUGIN_API int XPluginEnable(void)
{
    return 1;
}

PLUGIN_API void XPluginDisable(void)
{

}

PLUGIN_API void XPluginStop()
{
    
}