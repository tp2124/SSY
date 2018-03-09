#include "testPlugin.h"
#include <maya/MFnPlugin.h>
 
void* TestPlugin::creator() {   return new TestPlugin; } 

MStatus initializePlugin( MObject obj )
{
    MFnPlugin plugin( obj, "Travis Primm", "1.0", "Any");
    MStatus status = plugin.registerCommand( "TestPlugin", TestPlugin::creator );
    CHECK_MSTATUS_AND_RETURN_IT( status );
    return status;
}
 
MStatus uninitializePlugin( MObject obj )
{
    MFnPlugin plugin( obj );
    MStatus status = plugin.deregisterCommand( "TestPlugin" );
    CHECK_MSTATUS_AND_RETURN_IT( status );
    return status;
}

MStatus TestPlugin::doIt( const MArgList& argList )
{
    MGlobal::displayInfo( "Hello World!" );
    return MS::kSuccess;
}