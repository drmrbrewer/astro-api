      SUBROUTINE iau_LD ( BM, P, Q, E, EM, DLIM, P1 )
*+
*  - - - - - - -
*   i a u _ L D
*  - - - - - - -
*
*  Apply light deflection by a solar-system body, as part of
*  transforming coordinate direction into natural direction.
*
*  This routine is part of the International Astronomical Union's
*  SOFA (Standards of Fundamental Astronomy) software collection.
*
*  Status:  support routine.
*
*  Given:
*     BM       d      mass of the gravitating body (solar masses)
*     P        d(3)   direction from observer to source (unit vector)
*     Q        d(3)   direction from body to source (unit vector)
*     E        d(3)   direction from body to observer (unit vector)
*     EM       d      distance from body to observer (au)
*     DLIM     d      deflection limiter (Note 4)
*
*  Returned:
*     P1       d(3)   observer to deflected source (unit vector)
*
*  Notes:
*
*  1) The algorithm is based on Expr. (70) in Klioner (2003) and
*     Expr. (7.63) in the Explanatory Supplement (Urban & Seidelmann
*     2013), with some rearrangement to minimize the effects of machine
*     precision.
*
*  2) The mass parameter BM can, as required, be adjusted in order to
*     allow for such effects as quadrupole field.
*
*  3) The barycentric position of the deflecting body should ideally
*     correspond to the time of closest approach of the light ray to
*     the body.
*
*  4) The deflection limiter parameter DLIM is phi^2/2, where phi is the
*     angular separation (in radians) between source and body at which
*     limiting is applied.  As phi shrinks below the chosen threshold,
*     the deflection is artificially reduced, reaching zero for phi = 0.
*
*  5) The returned vector P1 is not normalized, but the consequential
*     departure from unit magnitude is always negligible.
*
*  6) To accumulate total light deflection taking into account the
*     contributions from several bodies, call the present routine for
*     each body in succession, in decreasing order of distance from the
*     observer.
*
*  7) For efficiency, validation is omitted.  The supplied vectors must
*     be of unit magnitude, and the deflection limiter non-zero and
*     positive.
*
*  References:
*
*     Urban, S. & Seidelmann, P. K. (eds), Explanatory Supplement to
*     the Astronomical Almanac, 3rd ed., University Science Books
*     (2013).
*
*     Klioner, Sergei A., "A practical relativistic model for micro-
*     arcsecond astrometry in space", Astr. J. 125, 1580-1597 (2003).
*
*  Called:
*     iau_PDP      scalar product of two p-vectors
*     iau_PXP      vector product of two p-vectors
*
*  This revision:   2013 September 3
*
*  SOFA release 2016-05-03
*
*  Copyright (C) 2016 IAU SOFA Board.  See notes at end.
*
*-----------------------------------------------------------------------

      IMPLICIT NONE
      DOUBLE PRECISION BM, P(3), Q(3), E(3), EM, DLIM, P1(3)

*  Schwarzschild radius of the Sun (au)
*  = 2 * 1.32712440041 D20 / (2.99792458 D8)^2 / 1.49597870700 D11
      DOUBLE PRECISION SRS
      PARAMETER ( SRS = 1.97412574336D-08 )

      INTEGER I
      DOUBLE PRECISION QPE(3), QDQPE, W, EQ(3), PEQ(3)

* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

*  Q . (Q + E).
      DO 1 I=1,3
         QPE(I) = Q(I) + E(I)
 1    CONTINUE
      CALL iau_PDP ( Q, QPE, QDQPE )

*  2 x G x BM / ( EM x c^2 x ( Q . (Q + E) ) ).
      W = BM * SRS / EM / MAX ( QDQPE, DLIM )

*  P x (E x Q).
      CALL iau_PXP ( E, Q, EQ )
      CALL iau_PXP ( P, EQ, PEQ )

*  Apply the deflection.
      DO 2 I = 1,3
         P1(I) = P(I) + W*PEQ(I)
 2    CONTINUE

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
