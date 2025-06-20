#include "app/EngineApplication.h"
int main()
{
    EngineApplication application;
    application.init();
    application.process();
    application.close();
}