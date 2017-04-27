/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.28 from the
 * contents of Astro.xs. Do not edit this file, edit Astro.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Astro.xs"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "math.h"
#include "ppport.h"

#include "astroEvent.h"

#define true 1
#define false 0

#line 23 "Astro.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
	    Perl_croak_nocontext("Usage: %s::%s(%s)", hvname, gvname, params);
        else
	    Perl_croak_nocontext("Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
	Perl_croak_nocontext("Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#define croak_xs_usage        S_croak_xs_usage

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#if PERL_VERSION_LE(5, 21, 5)
#  define newXS_deffile(a,b) Perl_newXS(aTHX_ a,b,file)
#else
#  define newXS_deffile(a,b) Perl_newXS_deffile(aTHX_ a,b)
#endif

#line 167 "Astro.c"

XS_EUPXS(XS_Astro__Astro_xs_jplephOpen); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Astro__Astro_xs_jplephOpen)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "path");
    {
#line 18 "Astro.xs"
    int status;
    char *crc250;
    int slen;
    int clen;
#line 181 "Astro.c"
	char*	path = (char *)SvPV_nolen(ST(0))
;
#line 23 "Astro.xs"
        slen = strlen(path);
        crc250 = calloc(sizeof(char), 251);
        jplephopen_(path, crc250, &status, &slen, &clen);
        if (status != 0){croak("Error %d jplephOpen: '%s' '%s'", status, path,crc250);}
	free (crc250);
#line 190 "Astro.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Astro__Astro_xs_jplephClose); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Astro__Astro_xs_jplephClose)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
#line 32 "Astro.xs"
        jplephclose_();        
#line 205 "Astro.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Astro__Astro_xs_JDToDTG); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Astro__Astro_xs_JDToDTG)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "JD");
    {
	double	JD = (double)SvNV(ST(0))
;
	int	year;
	int	month;
	int	mday;
	int	hour;
	int	min;
	double	secs;
#line 38 "Astro.xs"
        jd2date_(&JD, &year, &month, &mday, &hour, &min, &secs);
#line 228 "Astro.c"
	XSprePUSH;	EXTEND(SP,6);
	PUSHs(sv_newmortal());
	sv_setiv(ST(0), (IV)year);
	PUSHs(sv_newmortal());
	sv_setiv(ST(1), (IV)month);
	PUSHs(sv_newmortal());
	sv_setiv(ST(2), (IV)mday);
	PUSHs(sv_newmortal());
	sv_setiv(ST(3), (IV)hour);
	PUSHs(sv_newmortal());
	sv_setiv(ST(4), (IV)min);
	PUSHs(sv_newmortal());
	sv_setnv(ST(5), (double)secs);
    }
    XSRETURN(6);
}


XS_EUPXS(XS_Astro__Astro_xs_DTGToJD); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Astro__Astro_xs_DTGToJD)
{
    dVAR; dXSARGS;
    if (items != 6)
       croak_xs_usage(cv,  "year, month, mday, hour, min, secs");
    {
	int	year = (int)SvIV(ST(0))
;
	int	month = (int)SvIV(ST(1))
;
	int	mday = (int)SvIV(ST(2))
;
	int	hour = (int)SvIV(ST(3))
;
	int	min = (int)SvIV(ST(4))
;
	double	secs = (double)SvNV(ST(5))
;
	double	JD;
#line 43 "Astro.xs"
        date2jd_(&JD, &year, &month, &mday, &hour, &min, &secs );
#line 269 "Astro.c"
	XSprePUSH;	EXTEND(SP,1);
	PUSHs(sv_newmortal());
	sv_setnv(ST(0), (double)JD);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Astro__Astro_xs_astroEvent); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Astro__Astro_xs_astroEvent)
{
    dVAR; dXSARGS;
    if (items != 8)
       croak_xs_usage(cv,  "tstartJD, searchCode, tendJD, eventId, neventVal, eventValin, secdec, irc");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 48 "Astro.xs"
      double* eventVal;
      int maxrep = 100;
      int nrep;
      double* repJD;
      int* repId;
      double* repVal;
      char *rep250;
      char *crc250;
      int ii;
      int lenr=250;
#line 298 "Astro.c"
	double	tstartJD = (double)SvNV(ST(0))
;
	int	searchCode = (int)SvIV(ST(1))
;
	double	tendJD = (double)SvNV(ST(2))
;
	int	eventId = (int)SvIV(ST(3))
;
	int	neventVal = (int)SvIV(ST(4))
;
	AV*	eventValin;
	int	secdec = (int)SvIV(ST(6))
;
	int	irc = (int)SvIV(ST(7))
;

	STMT_START {
		SV* const xsub_tmp_sv = ST(5);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVAV){
		    eventValin = (AV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak_nocontext("%s: %s is not an ARRAY reference",
				"Astro::Astro::xs_astroEvent",
				"eventValin");
		}
	} STMT_END
;
#line 59 "Astro.xs"
    /* allocate and assign input array */
    neventVal=av_len(eventValin)+1;
    if (neventVal<=0) { /* make sure at least one element exists */
     eventVal = malloc(sizeof(double));
     neventVal=0;
     eventVal[0]=0.;
    } else {
     eventVal = malloc(sizeof(double)*neventVal);
     for (ii=0; ii < neventVal; ii++ ) {
       SV** elem = av_fetch(eventValin, ii, 0);
       if  (elem != NULL) eventVal[ ii ] = SvNV(*elem);
     }
    }
    /* allocate output arrays */
    repJD = malloc(sizeof(double)*maxrep);
    repId = malloc(sizeof(int)*maxrep);
    repVal = malloc(sizeof(double)*maxrep);
    rep250 = calloc(sizeof(char), lenr*maxrep);
    crc250 = calloc(sizeof(char), lenr);
    nrep=0;
    /* call fortran subroutine */
/*printf("  EV(0)= %d %f", neventVal,eventVal[0]);*/
    astroevent_(&tstartJD,&searchCode,&tendJD,&eventId,&neventVal,eventVal,&maxrep,&nrep,repJD,repId,repVal,rep250,&secdec,crc250,&irc,250,250);
    if (irc != 0 ) {
      free(eventVal);
      free(repJD);
      free(repId);
      free(repVal);
      free(rep250);
//      free(crc250);
      croak("xs_astroEvent Error return from astroevent (irc=%d, nrep=%d eventId=%d '%s')", irc, nrep, eventId,crc250); 
    }
    /* make return stack */
    if (irc == 0) {
       EXTEND(SP, 2+4*nrep);
       PUSHs(sv_2mortal(newSViv(irc)));
       PUSHs(sv_2mortal(newSViv(nrep)));
       for (ii=0; ii < nrep ; ii++ ) {
          PUSHs(sv_2mortal(newSVnv(repJD[ii])));
       }
       for (ii=0; ii < nrep ; ii++ ) {
          PUSHs(sv_2mortal(newSViv(repId[ii])));
       }
       for (ii=0; ii < nrep ; ii++ ) {
          PUSHs(sv_2mortal(newSVnv(repVal[ii])));
       }
       for (ii=0; ii < nrep ; ii++ ) {
          PUSHs(sv_2mortal(newSVpv(&rep250[ii*250],250)));
       }
    };
    free(eventVal);
    free(repJD);
    free(repId);
    free(repVal);
    free(rep250);
    free(crc250);
#line 385 "Astro.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Astro__Astro_xs_astroState); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Astro__Astro_xs_astroState)
{
    dVAR; dXSARGS;
    if (items < 3)
       croak_xs_usage(cv,  "lat, lon, hgt, ...");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 119 "Astro.xs"
      char *crc250;
      int irc;
      int njd;
      int i;
      char *jd;
      char *b30;
      char *jd30;
      int lenc=250;
      int lenj=30;
      STRLEN lens;
#line 412 "Astro.c"
	double	lat = (double)SvNV(ST(0))
;
	double	lon = (double)SvNV(ST(1))
;
	double	hgt = (double)SvNV(ST(2))
;
#line 130 "Astro.xs"
    crc250 = calloc(sizeof(char), lenc);
    njd=items-3;
    /*printf("XXXXXXXXXXXXXXXX njd: %d items=%d\n",njd,items);*/
    jd30 = malloc(sizeof(char)*njd*lenj);
    b30 = malloc(sizeof(char)*lenj);
    for (i=1; i <= njd; i++) {
            jd= (char *)SvPV(ST(i+2),lens);
	    memset(b30,' ',lenj);
            strncpy(b30,jd,fmin(lens,lenj));
            memcpy(&jd30[(i-1)*30],b30,lenj);
	    /*printf("XXXXXXXXXXXXXXXX astroState: %d %s\n",i,b30); */
    }
    /* call fortran subroutine */
    astrostate_(&njd,jd30,&lat,&lon,&hgt,crc250,&irc,lenj,lenc);
    if (irc != 0) {
       free(jd30);
       croak("xs_astroState Error return from state (irc=%d '%s')", irc, crc250); 
    }
    /* make return stack */
    if (irc == 0) {
       EXTEND(SP, 2);
       PUSHs(sv_2mortal(newSViv(irc)));
       PUSHs(sv_2mortal(newSVpv(crc250,strlen(crc250))));
    }; 
    free(b30);
    free(jd30);
    free(crc250);
#line 447 "Astro.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Astro); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Astro)
{
#if PERL_VERSION_LE(5, 21, 5)
    dVAR; dXSARGS;
#else
    dVAR; dXSBOOTARGSXSAPIVERCHK;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(file);

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#if PERL_VERSION_LE(5, 21, 5)
    XS_VERSION_BOOTCHECK;
#  ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#  endif
#endif

        newXS_deffile("Astro::Astro::xs_jplephOpen", XS_Astro__Astro_xs_jplephOpen);
        newXS_deffile("Astro::Astro::xs_jplephClose", XS_Astro__Astro_xs_jplephClose);
        newXS_deffile("Astro::Astro::xs_JDToDTG", XS_Astro__Astro_xs_JDToDTG);
        newXS_deffile("Astro::Astro::xs_DTGToJD", XS_Astro__Astro_xs_DTGToJD);
        newXS_deffile("Astro::Astro::xs_astroEvent", XS_Astro__Astro_xs_astroEvent);
        newXS_deffile("Astro::Astro::xs_astroState", XS_Astro__Astro_xs_astroState);
#if PERL_VERSION_LE(5, 21, 5)
#  if PERL_VERSION_GE(5, 9, 0)
    if (PL_unitcheckav)
        call_list(PL_scopestack_ix, PL_unitcheckav);
#  endif
    XSRETURN_YES;
#else
    Perl_xs_boot_epilog(aTHX_ ax);
#endif
}

