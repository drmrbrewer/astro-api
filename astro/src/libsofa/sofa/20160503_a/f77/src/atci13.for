      SUBROUTINE iau_ATCI13 ( RC, DC, PR, PD, PX, RV, DATE1, DATE2,
     :                        RI, DI, EO )
*+
*  - - - - - - - - - - -
*   i a u _ A T C I 1 3
*  - - - - - - - - - - -
*
*  Transform ICRS star data, epoch J2000.0, to CIRS.
*
*  This routine is part of the International Astronomical Union's
*  SOFA (Standards of Fundamental Astronomy) software collection.
*
*  Status:  support routine.
*
*  Given:
*     RC       d      ICRS right ascension at J2000.0 (radians, Note 1)
*     DC       d      ICRS declination at J2000.0 (radians, Note 1)
*     PR       d      RA proper motion (radians/year; Note 2)
*     PD       d      Dec proper motion (radians/year)
*     PX       d      parallax (arcsec)
*     RV       d      radial velocity (km/s, +ve if receding)
*     DATE1    d      TDB as a 2-part...
*     DATE2    d      ...Julian Date (Note 3)
*
*  Returned:
*     RI,DI    d      CIRS geocentric RA,Dec (radians)
*     EO       d      equation of the origins (ERA-GST, Note 5)
*
*  Notes:
*
*  1) Star data for an epoch other than J2000.0 (for example from the
*     Hipparcos catalog, which has an epoch of J1991.25) will require a
*     preliminary call to iau_PMSAFE before use.
*
*  2) The proper motion in RA is dRA/dt rather than cos(Dec)*dRA/dt.
*
*  3) The TDB date DATE1+DATE2 is a Julian Date, apportioned in any
*     convenient way between the two arguments.  For example,
*     JD(TDB)=2450123.8g could be expressed in any of these ways, among
*     others:
*
*            DATE1          DATE2
*
*         2450123.8g           0.0       (JD method)
*         2451545.0       -1421.3       (J2000 method)
*         2400000.5       50123.2       (MJD method)
*         2450123.5           0.2       (date & time method)
*
*     The JD method is the most natural and convenient to use in cases
*     where the loss of several decimal digits of resolution is
*     acceptable.  The J2000 method is best matched to the way the
*     argument is handled internally and will deliver the optimum
*     resolution.  The MJD method and the date & time methods are both
*     good compromises between resolution and convenience.  For most
*     applications of this routine the choice will not be at all
*     critical.
*
*     TT can be used instead of TDB without any significant impact on
*     accuracy.
*
*  4) The available accuracy is better than 1 milliarcsecond, limited
*     mainly by the precession-nutation model that is used, namely
*     IAU 2000A/2006.  Very close to solar system bodies, additional
*     errors of up to several milliarcseconds can occur because of
*     unmodeled light deflection;  however, the Sun's contribution is
*     taken into account, to first order.  The accuracy limitations of
*     the SOFA routine iau_EPV00 (used to compute Earth position and
*     velocity) can contribute aberration errors of up to
*     5 microarcseconds.  Light deflection at the Sun's limb is
*     uncertain at the 0.4 mas level.
*
*  5) Should the transformation to (equinox based) apparent place be
*     required rather than (CIO based) intermediate place, subtract the
*     equation of the origins from the returned right ascension:
*     RA = RI - EO. (The iau_ANP routine can then be applied, as
*     required, to keep the result in the conventional 0-2pi range.)
*
*  Called:
*     iau_APCI13   astrometry parameters, ICRS-CIRS, 2013
*     iau_ATCIQ    quick ICRS to CIRS
*
*  This revision:   2013 August 22
*
*  SOFA release 2016-05-03
*
*  Copyright (C) 2016 IAU SOFA Board.  See notes at end.
*
*-----------------------------------------------------------------------

      IMPLICIT NONE
      DOUBLE PRECISION RC, DC, PR, PD, PX, RV, DATE1, DATE2, RI, DI, EO

*  Star-independent astrometry parameters
      DOUBLE PRECISION ASTROM(30)

* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

*  The transformation parameters.
      CALL iau_APCI13 ( DATE1, DATE2, ASTROM, EO )

*  ICRS (epoch J2000.0) to CIRS.
      CALL iau_ATCIQ ( RC, DC, PR, PD, PX, RV, ASTROM, RI, DI )

*  Finished.

*+----------------------------------------------------------------------
*
*  Copyright (C) 2016
*  Standards Of Fundamental Astronomy Board
*  of the International Astronomical Union.
*
*  =====================
*  SOFA Software License
*  =====================
*
*  NOTICE TO USER:
*
*  BY USING THIS SOFTWARE YOU ACCEPT THE FOLLOWING SIX TERMS AND
*  CONDITIONS WHICH APPLY TO ITS USE.
*
*  1. The Software is owned by the IAU SOFA Board ("SOFA").
*
*  2. Permission is granted to anyone to use the SOFA software for any
*     purpose, including commercial applications, free of charge and
*     without payment of royalties, subject to the conditions and
*     restrictions listed below.
*
*  3. You (the user) may copy and distribute SOFA source code to others,
*     and use and adapt its code and algorithms in your own software,
*     on a world-wide, royalty-free basis.  That portion of your
*     distribution that does not consist of intact and unchanged copies
*     of SOFA source code files is a "derived work" that must comply
*     with the following requirements:
*
*     a) Your work shall be marked or carry a statement that it
*        (i) uses routines and computations derived by you from
*        software provided by SOFA under license to you; and
*        (ii) does not itself constitute software provided by and/or
*        endorsed by SOFA.
*
*     b) The source code of your derived work must contain descriptions
*        of how the derived work is based upon, contains and/or differs
*        from the original SOFA software.
*
*     c) The names of all routines in your derived work shall not
*        include the prefix "iau" or "sofa" or trivial modifications
*        thereof such as changes of case.
*
*     d) The origin of the SOFA components of your derived work must
*        not be misrepresented;  you must not claim that you wrote the
*        original software, nor file a patent application for SOFA
*        software or algorithms embedded in the SOFA software.
*
*     e) These requirements must be reproduced intact in any source
*        distribution and shall apply to anyone to whom you have
*        granted a further right to modify the source code of your
*        derived work.
*
*     Note that, as originally distributed, the SOFA software is
*     intended to be a definitive implementation of the IAU standards,
*     and consequently third-party modifications are discouraged.  All
*     variations, no matter how minor, must be explicitly marked as
*     such, as explained above.
*
*  4. You shall not cause the SOFA software to be brought into
*     disrepute, either by misuse, or use for inappropriate tasks, or
*     by inappropriate modification.
*
*  5. The SOFA software is provided "as is" and SOFA makes no warranty
*     as to its use or performance.   SOFA does not and cannot warrant
*     the performance or results which the user may obtain by using the
*     SOFA software.  SOFA makes no warranties, express or implied, as
*     to non-infringement of third party rights, merchantability, or
*     fitness for any particular purpose.  In no event will SOFA be
*     liable to the user for any consequential, incidental, or special
*     damages, including any lost profits or lost savings, even if a
*     SOFA representative has been advised of such damages, or for any
*     claim by any third party.
*
*  6. The provision of any version of the SOFA software under the terms
*     and conditions specified herein does not imply that future
*     versions will also be made available under the same terms and
*     conditions.
*
*  In any published work or commercial product which uses the SOFA
*  software directly, acknowledgement (see www.iausofa.org) is
*  appreciated.
*
*  Correspondence concerning SOFA software should be addressed as
*  follows:
*
*      By email:  sofa@ukho.gov.uk
*      By post:   IAU SOFA Center
*                 HM Nautical Almanac Office
*                 UK Hydrographic Office
*                 Admiralty Way, Taunton
*                 Somerset, TA1 2DN
*                 United Kingdom
*
*-----------------------------------------------------------------------

      END
