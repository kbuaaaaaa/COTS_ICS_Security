#include "Process.h"
#include "rtwtypes.h"
#include "Process_private.h"
#include "rt_logging_mmi.h"
#include "Process_capi.h"
#include "Process_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.8 (R2022b) 13-May-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void crsbt1gvys ( SimStruct * rtS_e ) { if ( ssGetTaskTime ( rtS_e
, 1 ) != ssGetTStart ( rtS_e ) ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS_e ) ; } } void gwree4nwij ( SimStruct * rtS_p ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_p ) ; } void nirot44yst (
SimStruct * rtS_i , real_T * c5k5tp3gwa , real_T * adv4mzsv2u , ejpefa4a5s *
localP ) { if ( ssIsSampleHit ( rtS_i , 1 , 0 ) ) { * c5k5tp3gwa = localP ->
Constant_Value ; * adv4mzsv2u = localP -> Constant1_Value ; } } void
MdlInitialize ( void ) { rtDW . kk3d1ljcrv [ 0 ] = rtP .
Delay_InitialCondition ; rtDW . oabrh5zhpn [ 0 ] = rtP .
Delay1_InitialCondition ; rtDW . dfxcwkl2ea [ 0 ] = rtP .
Delay2_InitialCondition ; rtDW . kk3d1ljcrv [ 1 ] = rtP .
Delay_InitialCondition ; rtDW . oabrh5zhpn [ 1 ] = rtP .
Delay1_InitialCondition ; rtDW . dfxcwkl2ea [ 1 ] = rtP .
Delay2_InitialCondition ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} rtDW . mpquw0r2p5 = true ; gwree4nwij ( rtS ) ; gwree4nwij ( rtS ) ;
gwree4nwij ( rtS ) ; rtDW . esfqqyyxs2 = - 1 ; MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T dariivppl2 ; int8_T rtAction ; int8_T
rtPrevAction ; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { srClearBC ( rtDW .
nirot44ystd . nhj2kgd4hk ) ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
oynpoupann = rtDW . kk3d1ljcrv [ 0 ] ; if ( rtDW . mpquw0r2p5 ) { rtDW .
mpquw0r2p5 = false ; dariivppl2 = rtP . IC_Value ; } else { dariivppl2 = rtB
. oynpoupann ; } rtB . o3s2clwylg = ( rtP . Multiply1_Gain * rtDW .
dfxcwkl2ea [ 0 ] + rtP . Multiply_Gain * rtDW . oabrh5zhpn [ 0 ] ) * rtP . Q
/ rtP . A + dariivppl2 ; rtPrevAction = rtDW . esfqqyyxs2 ; if ( rtB .
o3s2clwylg > 100.0 ) { rtAction = 0 ; } else if ( rtB . o3s2clwylg < 90.0 ) {
rtAction = 1 ; } else { rtAction = 2 ; } rtDW . esfqqyyxs2 = rtAction ; if (
rtPrevAction != rtAction ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; switch ( rtPrevAction ) { case 0 : gwree4nwij ( rtS ) ; break ; case 1 :
gwree4nwij ( rtS ) ; break ; case 2 : gwree4nwij ( rtS ) ; break ; } } switch
( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { crsbt1gvys ( rtS )
; } nirot44yst ( rtS , & rtB . f2jx2i0s5j , & rtB . pcli5f4qrp , & rtP .
nirot44ystd ) ; srUpdateBC ( rtDW . nirot44ystd . nhj2kgd4hk ) ; break ; case
1 : if ( rtAction != rtPrevAction ) { crsbt1gvys ( rtS ) ; } nirot44yst ( rtS
, & rtB . f2jx2i0s5j , & rtB . pcli5f4qrp , & rtP . eg4zllxvv0 ) ; srUpdateBC
( rtDW . eg4zllxvv0 . nhj2kgd4hk ) ; break ; default : if ( rtAction !=
rtPrevAction ) { crsbt1gvys ( rtS ) ; } nirot44yst ( rtS , & rtB . f2jx2i0s5j
, & rtB . pcli5f4qrp , & rtP . db1cetzuzs ) ; srUpdateBC ( rtDW . db1cetzuzs
. nhj2kgd4hk ) ; break ; } } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . kk3d1ljcrv [ 0U ] = rtDW .
kk3d1ljcrv [ 1U ] ; rtDW . kk3d1ljcrv [ 1 ] = rtB . o3s2clwylg ; rtDW .
oabrh5zhpn [ 0U ] = rtDW . oabrh5zhpn [ 1U ] ; rtDW . oabrh5zhpn [ 1 ] = rtB
. pcli5f4qrp ; rtDW . dfxcwkl2ea [ 0U ] = rtDW . dfxcwkl2ea [ 1U ] ; rtDW .
dfxcwkl2ea [ 1 ] = rtB . f2jx2i0s5j ; } UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlTerminate
( void ) { } static void mr_Process_cacheDataAsMxArray ( mxArray * destArray
, mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void
mr_Process_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_Process_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_Process_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_Process_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_Process_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_Process_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) ; static uint_T
mr_Process_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_Process_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_Process_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_Process_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_Process_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_Process_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_Process_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_Process_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_Process_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T
fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray
, i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; }
mxArray * mr_Process_GetDWork ( ) { static const char * ssDWFieldNames [ 3 ]
= { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_Process_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 8 ] = {
"rtDW.kk3d1ljcrv" , "rtDW.oabrh5zhpn" , "rtDW.dfxcwkl2ea" , "rtDW.esfqqyyxs2"
, "rtDW.mpquw0r2p5" , "rtDW.db1cetzuzs.nhj2kgd4hk" ,
"rtDW.eg4zllxvv0.nhj2kgd4hk" , "rtDW.nirot44ystd.nhj2kgd4hk" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 8 , rtdwDataFieldNames ) ;
mr_Process_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & ( rtDW
. kk3d1ljcrv ) , sizeof ( rtDW . kk3d1ljcrv ) ) ;
mr_Process_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & ( rtDW
. oabrh5zhpn ) , sizeof ( rtDW . oabrh5zhpn ) ) ;
mr_Process_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & ( rtDW
. dfxcwkl2ea ) , sizeof ( rtDW . dfxcwkl2ea ) ) ;
mr_Process_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & ( rtDW
. esfqqyyxs2 ) , sizeof ( rtDW . esfqqyyxs2 ) ) ;
mr_Process_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & ( rtDW
. mpquw0r2p5 ) , sizeof ( rtDW . mpquw0r2p5 ) ) ;
mr_Process_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & ( rtDW
. db1cetzuzs . nhj2kgd4hk ) , sizeof ( rtDW . db1cetzuzs . nhj2kgd4hk ) ) ;
mr_Process_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & ( rtDW
. eg4zllxvv0 . nhj2kgd4hk ) , sizeof ( rtDW . eg4zllxvv0 . nhj2kgd4hk ) ) ;
mr_Process_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & ( rtDW
. nirot44ystd . nhj2kgd4hk ) , sizeof ( rtDW . nirot44ystd . nhj2kgd4hk ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_Process_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_Process_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 ,
sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0
, 1 ) ; mr_Process_restoreDataFromMxArray ( ( void * ) & ( rtDW . kk3d1ljcrv
) , rtdwData , 0 , 0 , sizeof ( rtDW . kk3d1ljcrv ) ) ;
mr_Process_restoreDataFromMxArray ( ( void * ) & ( rtDW . oabrh5zhpn ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . oabrh5zhpn ) ) ;
mr_Process_restoreDataFromMxArray ( ( void * ) & ( rtDW . dfxcwkl2ea ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . dfxcwkl2ea ) ) ;
mr_Process_restoreDataFromMxArray ( ( void * ) & ( rtDW . esfqqyyxs2 ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . esfqqyyxs2 ) ) ;
mr_Process_restoreDataFromMxArray ( ( void * ) & ( rtDW . mpquw0r2p5 ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . mpquw0r2p5 ) ) ;
mr_Process_restoreDataFromMxArray ( ( void * ) & ( rtDW . db1cetzuzs .
nhj2kgd4hk ) , rtdwData , 0 , 5 , sizeof ( rtDW . db1cetzuzs . nhj2kgd4hk ) )
; mr_Process_restoreDataFromMxArray ( ( void * ) & ( rtDW . eg4zllxvv0 .
nhj2kgd4hk ) , rtdwData , 0 , 6 , sizeof ( rtDW . eg4zllxvv0 . nhj2kgd4hk ) )
; mr_Process_restoreDataFromMxArray ( ( void * ) & ( rtDW . nirot44ystd .
nhj2kgd4hk ) , rtdwData , 0 , 7 , sizeof ( rtDW . nirot44ystd . nhj2kgd4hk )
) ; } } mxArray * mr_Process_GetSimStateDisallowedBlocks ( ) { mxArray * data
= mxCreateCellMatrix ( 1 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 1 ] = { "Scope" , } ; static const char * blockPath [ 1 ]
= { "Process/Scope" , } ; static const int reason [ 1 ] = { 0 , } ; for (
subs [ 0 ] = 0 ; subs [ 0 ] < 1 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateDoubleScalar ( ( double ) reason [ subs [ 0 ] ] ) ) ; } }
return data ; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough
( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 23 ) ;
ssSetNumBlockIO ( rtS , 4 ) ; ssSetNumBlockParams ( rtS , 14 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 6000.0 ) ; ssSetOffsetTime ( rtS , 0 , 1.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2740902445U ) ; ssSetChecksumVal ( rtS , 1 ,
1980205787U ) ; ssSetChecksumVal ( rtS , 2 , 2735989325U ) ; ssSetChecksumVal
( rtS , 3 , 2641814223U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0
, sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 23 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } Process_InitializeDataMapInfo ( )
; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Process" ) ; ssSetPath ( rtS , "Process" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 300000.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 2 , 2
, 2 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 } ; static
int_T rt_LoggedStateDimensions [ ] = { 2 , 2 , 2 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ;
static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"DSTATE" , "DSTATE" , "DSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "Process/Delay" , "Process/Delay1" ,
"Process/Delay2" } ; static const char_T * rt_LoggedStateNames [ ] = {
"DSTATE" , "DSTATE" , "DSTATE" } ; static boolean_T rt_LoggedStateCrossMdlRef
[ ] = { 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [
] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 3 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 3 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) rtDW . kk3d1ljcrv ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) rtDW . oabrh5zhpn ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) rtDW . dfxcwkl2ea ; } rtliSetLogT
( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS )
, "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "xFinal" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetStepSize ( rtS , 6000.0 ) ; ssSetMinStepSize (
rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError (
rtS , 0 ) ; ssSetMaxStepSize ( rtS , 6000.0 ) ; ssSetSolverMaxOrder ( rtS , -
1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL )
) ; ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
2740902445U ) ; ssSetChecksumVal ( rtS , 1 , 1980205787U ) ; ssSetChecksumVal
( rtS , 2 , 2735989325U ) ; ssSetChecksumVal ( rtS , 3 , 2641814223U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 4 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = (
sysRanDType * ) & rtDW . nirot44ystd . nhj2kgd4hk ; systemRan [ 2 ] = (
sysRanDType * ) & rtDW . db1cetzuzs . nhj2kgd4hk ; systemRan [ 3 ] = (
sysRanDType * ) & rtDW . eg4zllxvv0 . nhj2kgd4hk ; rteiSetModelMappingInfoPtr
( ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_Process_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS
, mr_Process_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_Process_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
