//This file is autogenerated for
//    EventLog.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_EVENTLOG_CALLBACK_DEC_HH
#define ELASTOS_EVENTLOG_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_EventLog_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Base {

struct ElaEventLogCallback
{
    void (*elastos_EventLog_writeEvent)(Int32 tag, Int32 value);
};

void* EventLog::ElaEventLogCallback_Init()
{
    static ElaEventLogCallback sElaEventLogCallback;

    sElaEventLogCallback.elastos_EventLog_writeEvent = &EventLog::WriteEvent;

    Elastos_EventLog_InitCallback((Handle32)&sElaEventLogCallback);
    return &sElaEventLogCallback;
}

static void* sPElaEventLogCallback = EventLog::ElaEventLogCallback_Init();

} // namespace Base
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_EVENTLOG_CALLBACK_DEC_HH
