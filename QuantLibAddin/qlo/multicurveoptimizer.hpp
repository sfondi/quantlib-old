/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2016 Stefano Fondi

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#ifndef qla_multicurveoptimizer_hpp
#define qla_multicurveoptimizer_hpp

#include <oh/libraryobject.hpp>
#include <ql/termstructures/multibootstrap.hpp>

#include <ql/types.hpp>

typedef QuantLib::MultiCurveOptimizer <
            QuantLib::InterpolatedDiscountCurve <
                QuantLib::Linear >> LinearDiscountMultiCurve;

typedef QuantLib::MultiCurveOptimizer <
            QuantLib::InterpolatedDiscountCurve <
                QuantLib::LogCubicNaturalSpline>> LogCubicDiscountMultiCurve;

typedef QuantLib::MultiCurveOptimizer <
            QuantLib::InterpolatedDiscountCurve <
                QuantLib::MonotonicLogCubicNaturalSpline >> MonotonicLogCubicDiscountMultiCurve;

typedef QuantLib::MultiCurveOptimizer <
            QuantLib::InterpolatedZeroCurve <
                QuantLib::Linear >> LinearZeroMultiCurve;

typedef QuantLib::MultiCurveOptimizer <
            QuantLib::InterpolatedZeroCurve <
                QuantLib::CubicNaturalSpline >> CubicZeroMultiCurve;

typedef QuantLib::MultiCurveOptimizer <
            QuantLib::InterpolatedZeroCurve <
                QuantLib::MonotonicCubicNaturalSpline >> MonotonicCubicZeroMultiCurve;

namespace QuantLibAddin {

    class LinearDiscountMultiCurveOptimizer : public ObjectHandler::LibraryObject<LinearDiscountMultiCurve> 
    {
    
    public:
        void addTermStructure(LinearDiscountMultiCurve& TS) const;

    protected:
        OH_LIB_CTOR(LinearDiscountMultiCurveOptimizer, LinearDiscountMultiCurve);

    };

    class LogCubicDiscountMultiCurveOptimizer : public ObjectHandler::LibraryObject<LogCubicDiscountMultiCurve>
    {

    protected:
        OH_LIB_CTOR(LogCubicDiscountMultiCurveOptimizer, LogCubicDiscountMultiCurve);

    };

    class MonotonicLogCubicDiscountMultiCurveOptimizer : public ObjectHandler::LibraryObject<MonotonicLogCubicDiscountMultiCurve>
    {

    protected:
        OH_LIB_CTOR(MonotonicLogCubicDiscountMultiCurveOptimizer, MonotonicLogCubicDiscountMultiCurve);

    };

    class LinearZeroMultiCurveOptimizer : public ObjectHandler::LibraryObject<LinearZeroMultiCurve>
    {

    protected:
        OH_LIB_CTOR(LinearZeroMultiCurveOptimizer, LinearZeroMultiCurve);

    };

    class CubicZeroMultiCurveOptimizer : public ObjectHandler::LibraryObject<CubicZeroMultiCurve>
    {

    protected:
        OH_LIB_CTOR(CubicZeroMultiCurveOptimizer, CubicZeroMultiCurve);

    };

    class MonotonicCubicZeroMultiCurveOptimizer : public ObjectHandler::LibraryObject<MonotonicCubicZeroMultiCurve>
    {

    protected:
        OH_LIB_CTOR(MonotonicCubicZeroMultiCurveOptimizer, MonotonicCubicZeroMultiCurve);

    };

}

#endif
