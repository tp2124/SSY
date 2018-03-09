#ifndef TestPlugin_H
#define TestPlugin_H
 
#include <maya/MArgList.h>
#include <maya/MObject.h>
#include <maya/MGlobal.h>
#include <maya/MPxCommand.h>
 
class TestPlugin : public MPxCommand
{
public:
    TestPlugin() {};
    virtual MStatus doIt( const MArgList& argList);
    static  void*   creator();
};
#endif