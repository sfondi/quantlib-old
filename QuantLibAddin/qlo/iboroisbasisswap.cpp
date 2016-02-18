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

#if defined(HAVE_CONFIG_H)
    #include <qlo/config.hpp>
#endif

#include <qlo/iboroisbasisswap.hpp>
#include <ql/instruments/makeiboroisbasisswap.hpp>
#include <ql/termstructures/yield/oisbasisratehelper.hpp>
#include <ql/time/ecb.hpp>

using std::vector;
using ObjectHandler::property_t;
using QuantLib::Period;
using QuantLib::MakeIBOROISBasisSwap;
using boost::shared_ptr;

namespace QuantLibAddin {

    IBOROISBasisSwap::IBOROISBasisSwap(
            const shared_ptr<ObjectHandler::ValueObject>& properties,
            QuantLib::IBOROISBasisSwap::Type type,
            std::vector<QuantLib::Real> nominals,
            const shared_ptr<QuantLib::Schedule>& floatingSchedule,
            const shared_ptr<QuantLib::IborIndex>& iborIndex,
            const QuantLib::DayCounter& floatingDayCount,
            const shared_ptr<QuantLib::Schedule>& overnightSchedule,
            const shared_ptr<QuantLib::OvernightIndex>& overnightIndex,
            QuantLib::Spread spread,
            const QuantLib::DayCounter& overnightDayCount,
            boost::optional<QuantLib::BusinessDayConvention> paymentConvention,
            bool arithmeticAveragedCoupon,
            bool permanent)
    : Swap(properties, permanent)
    {
        libraryObject_ = shared_ptr<QuantLib::Instrument>(new
            QuantLib::IBOROISBasisSwap(type, nominals,*floatingSchedule,
                                       iborIndex, floatingDayCount,
                                       *overnightSchedule, overnightIndex,
                                       spread, overnightDayCount,
                                       paymentConvention,
                                       arithmeticAveragedCoupon));
    }

    // MakeIBOROISBasisSwap
    IBOROISBasisSwap::IBOROISBasisSwap(
            const shared_ptr<ObjectHandler::ValueObject>& properties,
            QuantLib::Natural settlDays,
            const QuantLib::Period& swapTenor,
            const shared_ptr<QuantLib::IborIndex>& iborIndex,
            const shared_ptr<QuantLib::OvernightIndex>& overnightIndex,
            QuantLib::Rate spread,
            const QuantLib::Period& fwdStart,
            bool permanent)
    : Swap(properties, permanent)
    {
        libraryObject_ = MakeIBOROISBasisSwap(swapTenor, iborIndex, overnightIndex, spread, fwdStart)
                        .withSettlementDays(settlDays)
                        .operator shared_ptr<QuantLib::IBOROISBasisSwap>();
    }

    // MakeDatedIBOROISBasisSwap
    IBOROISBasisSwap::IBOROISBasisSwap(
            const shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::Date& startDate,
            const QuantLib::Date& enddate,
            const shared_ptr<QuantLib::IborIndex>& iborIndex,
            const shared_ptr<QuantLib::OvernightIndex>& overnightIndex,
            QuantLib::Rate spread,
            bool permanent)
    : Swap(properties, permanent)
    {
        QuantLib::Date effectiveDate = startDate;
        if (effectiveDate==QuantLib::Date())
            effectiveDate = QuantLib::ECB::nextDate();

        QuantLib::Date terminationDate = enddate;
        if (terminationDate==QuantLib::Date())
            terminationDate = QuantLib::ECB::nextDate(effectiveDate);

        libraryObject_ = MakeIBOROISBasisSwap(Period(), iborIndex, overnightIndex, spread)
                        .withEffectiveDate(effectiveDate)
                        .withTerminationDate(terminationDate)
                        .operator shared_ptr<QuantLib::IBOROISBasisSwap>();
    }

    IBOROISBasisSwap::IBOROISBasisSwap(
        const shared_ptr<ObjectHandler::ValueObject>& properties,
        const shared_ptr<QuantLib::IBOROISBasisRateHelper>& swapRH,
        bool permanent)
    : Swap(properties, permanent)
    {
        libraryObject_ = swapRH->swap();
    }

    vector<vector<property_t> > IBOROISBasisSwap::floatingLegAnalysis(
                                                    const QuantLib::Date& d) {
        return Swap::legAnalysis(0, d);
    }

    vector<vector<property_t> > IBOROISBasisSwap::overnightLegAnalysis(
                                                    const QuantLib::Date& d) {
        return Swap::legAnalysis(1, d);
    }

}
