//------------------------------------------------------------------------
// Trialx.h
// (c) 1999 by Modern Software Publishing, Inc.
// Header file for TrialX return codes
//
//------------------------------------------------------------------------

#ifndef __TRIALX_H

// error codes
#define ERROR_START					513
#define ERROR_CAPTIONTOBIG			514
#define ERROR_CANTWRITEDISK			515	
#define ERROR_ACCESSFAILURE			516
#define ERROR_BADDEMODATE			517
#define ERROR_BADDATEVALUE			518
#define ERROR_DATESETBACK			519
#define ERROR_BADVALUE				520
#define ERROR_DEMONOTFOUND			521
#define ERROR_RUNTIME				522
#define ERROR_INVALIDINQUIRY		523
#define ERROR_INVALIDSIGNATURE		524
#define ERROR_EXPIRED				525
#define ERROR_USERCANCEL			526
#define ERROR_PERMISSIONDENIED		527
#define ERROR_OUTOFCODES			528
#define ERROR_STOP					529
#define ERROR_TRIALPERIODEXPIRED	4096

// remote action constants
#define REMOTEACTIONS_CCRESET		0
#define REMOTEACTIONS_CCREMOVE		1
#define REMOTEACTIONS_CCEXTEND		2
#define REMOTEACTIONS_CCMAKERETAIL	3
#define REMOTEACTIONS_CCACTIONCODE	4

// check styles constants
#define CHECKSTYLES_CCSTART			0
#define CHECKSTYLES_CCEND			1
#define CHECKSTYLES_CCBOTH			2 
#define CHECKSTYLES_CCNEVER			3

// trial states constants
#define TRIALSTATES_CCTRIAL			0
#define TRIALSTATES_CCRETAIL		1
#define TRIALSTATES_CCEXPIRED		2
#define TRIALSTATES_CCDATESETBACK	3
#define TRIALSTATES_CCUSERDECLINE	4
#define TRIALSTATES_CCBADUNLOCK		5
#define TRIALSTATES_CCINVALID		6
#define TRIALSTATES_CCNOTINSTALLED	7

// trial styles constants
#define TRIALSTYLES_CCDAYS			0
#define TRIALSTYLES_CCDATE			1
#define TRIALSTYLES_CCRUNS			2
#define TRIALSTYLES_CCFEATURE		3
#define TRIALSTYLES_CCTIME			4	
#else
#define __TRIALX_H
#endif