#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Process_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "Process.h"
#include "Process_capi.h"
#include "Process_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Process/Delay" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "Process/PLC/If Action Subsystem" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"Process/PLC/If Action Subsystem" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 ,
0 } , { 3 , 0 , TARGET_STRING ( "Process/PLC/If Action Subsystem1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"Process/PLC/If Action Subsystem1" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 ,
0 } , { 5 , 0 , TARGET_STRING ( "Process/PLC/If Action Subsystem2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"Process/PLC/If Action Subsystem2" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 ,
0 } , { 7 , 0 , TARGET_STRING ( "Process/PLC/Merge" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING ( "Process/PLC/Merge1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"Process/Water Tank/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 10 , TARGET_STRING (
"Process/Delay" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 11
, TARGET_STRING ( "Process/Delay1" ) , TARGET_STRING ( "InitialCondition" ) ,
0 , 0 , 0 } , { 12 , TARGET_STRING ( "Process/Delay2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 13 , TARGET_STRING (
"Process/Water Tank/Multiply" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , {
14 , TARGET_STRING ( "Process/Water Tank/Multiply1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 15 , TARGET_STRING ( "Process/Water Tank/IC" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 16 , TARGET_STRING (
"Process/PLC/If Action Subsystem/Constant" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 17 , TARGET_STRING (
"Process/PLC/If Action Subsystem/Constant1" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 18 , TARGET_STRING (
"Process/PLC/If Action Subsystem1/Constant" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 19 , TARGET_STRING (
"Process/PLC/If Action Subsystem1/Constant1" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 20 , TARGET_STRING (
"Process/PLC/If Action Subsystem2/Constant" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 21 , TARGET_STRING (
"Process/PLC/If Action Subsystem2/Constant1" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals
rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 22 , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 23 ,
TARGET_STRING ( "Q" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . oynpoupann , & rtB . f2jx2i0s5j ,
& rtB . pcli5f4qrp , & rtB . f2jx2i0s5j , & rtB . pcli5f4qrp , & rtB .
f2jx2i0s5j , & rtB . pcli5f4qrp , & rtB . f2jx2i0s5j , & rtB . pcli5f4qrp , &
rtB . o3s2clwylg , & rtP . Delay_InitialCondition , & rtP .
Delay1_InitialCondition , & rtP . Delay2_InitialCondition , & rtP .
Multiply_Gain , & rtP . Multiply1_Gain , & rtP . IC_Value , & rtP .
nirot44ystd . Constant_Value , & rtP . nirot44ystd . Constant1_Value , & rtP
. db1cetzuzs . Constant_Value , & rtP . db1cetzuzs . Constant1_Value , & rtP
. eg4zllxvv0 . Constant_Value , & rtP . eg4zllxvv0 . Constant1_Value , & rtP
. A , & rtP . Q , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 6000.0 , 0.0 } ;
static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 1 , ( uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 10 , rtRootInputs , 0 , rtRootOutputs , 0 }
, { rtBlockParameters , 12 , rtModelParameters , 2 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 2740902445U , 1980205787U , 2735989325U ,
2641814223U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * Process_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Process_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Process_host_InitializeDataMapInfo ( Process_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
