#ifndef RTW_HEADER_Process_h_
#define RTW_HEADER_Process_h_
#ifndef Process_COMMON_INCLUDES_
#define Process_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Process_types.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Process
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (4) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { int8_T nhj2kgd4hk ; } m3htxtnbe3 ; typedef struct { real_T
oynpoupann ; real_T o3s2clwylg ; real_T f2jx2i0s5j ; real_T pcli5f4qrp ; } B
; typedef struct { real_T kk3d1ljcrv [ 2 ] ; real_T oabrh5zhpn [ 2 ] ; real_T
dfxcwkl2ea [ 2 ] ; struct { void * LoggedData ; } pli32qezqk ; int8_T
esfqqyyxs2 ; boolean_T mpquw0r2p5 ; m3htxtnbe3 db1cetzuzs ; m3htxtnbe3
eg4zllxvv0 ; m3htxtnbe3 nirot44ystd ; } DW ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct ejpefa4a5s_ { real_T
Constant_Value ; real_T Constant1_Value ; } ; struct P_ { real_T A ; real_T Q
; real_T Delay_InitialCondition ; real_T Delay1_InitialCondition ; real_T
Delay2_InitialCondition ; real_T IC_Value ; real_T Multiply1_Gain ; real_T
Multiply_Gain ; ejpefa4a5s db1cetzuzs ; ejpefa4a5s eg4zllxvv0 ; ejpefa4a5s
nirot44ystd ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B
rtB ; extern DW rtDW ; extern P rtP ; extern mxArray * mr_Process_GetDWork (
) ; extern void mr_Process_SetDWork ( const mxArray * ssDW ) ; extern mxArray
* mr_Process_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * Process_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
