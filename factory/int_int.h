// emacs edit mode for this file is -*- C++ -*-
// $Id: int_int.h,v 1.0 1996-05-17 10:59:41 stobbe Exp $

#ifndef INCL_INTERNALINTEGER_H
#define INCL_INTERNALINTEGER_H

/*
$Log: not supported by cvs2svn $
*/

#include "cf_gmp.h"

#include <iostream.h>
#include "int_cf.h"


class InternalInteger : public InternalCF
{
private:
    MP_INT thempi;
    static int initialized;
    static MP_INT & MPI( const InternalCF * const c );
public:
    InternalInteger();
    InternalInteger( const InternalCF& )
    {
	ASSERT( 0, "ups there is something wrong in your code" );
    }
    InternalInteger( const int i );
    InternalInteger( const char * str );
    InternalInteger( const MP_INT & );
    ~InternalInteger();
    InternalCF* deepCopyObject() const;
    const char * const classname() const { return "InternalInteger"; }
    void print( ostream&, char* );
    bool isZero() const;
    bool isOne() const;
    InternalCF* genZero();
    InternalCF* genOne();

    bool is_imm() const;

    int levelcoeff() const { return IntegerDomain; }
    InternalCF* neg();

    int comparesame( InternalCF* );

    InternalCF* addsame( InternalCF* );
    InternalCF* subsame( InternalCF* );
    InternalCF* mulsame( InternalCF* ); 
    InternalCF* dividesame( InternalCF* );
    InternalCF* modulosame( InternalCF* );
    InternalCF* divsame( InternalCF* ); 
    InternalCF* modsame( InternalCF* );
    void divremsame( InternalCF*, InternalCF*&, InternalCF*& );
    bool divremsamet( InternalCF*, InternalCF*&, InternalCF*& );

    int comparecoeff( InternalCF* );

    InternalCF* addcoeff( InternalCF* );
    InternalCF* subcoeff( InternalCF*, bool );
    InternalCF* mulcoeff( InternalCF* ); 
    InternalCF* dividecoeff( InternalCF*, bool ); 
    InternalCF* modulocoeff( InternalCF*, bool );
    InternalCF* divcoeff( InternalCF*, bool ); 
    InternalCF* modcoeff( InternalCF*, bool );
    void divremcoeff( InternalCF*, InternalCF*&, InternalCF*&, bool );
    bool divremcoefft( InternalCF*, InternalCF*&, InternalCF*&, bool );

    int intval() const;

    int intmod( int p ) const;

    int sign() const;

    InternalCF* sqrt();

    friend class InternalRational;
#ifdef SINGULAR
    friend MP_INT gmp_numerator ( const CanonicalForm & f );
    friend MP_INT gmp_denominator ( const CanonicalForm & f );
#endif /* SINGULAR */
#ifdef MULTIPROTOCOL
    friend MP_INT gmp_numerator_mp ( const CanonicalForm & f );
    friend MP_INT gmp_denominator_mp ( const CanonicalForm & f );
#endif /* MULTIPROTOCOL */
    friend MP_INT getmpi ( InternalCF * value, bool symmetric );
};

inline MP_INT & InternalInteger::MPI( const InternalCF * const c )
{
    return (((InternalInteger*)c)->thempi);
}

#endif /* INCL_INTERNALINTEGER_H */
