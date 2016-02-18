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

#ifndef qla_iboroisbasisswap_hpp
#define qla_iboroisbasisswap_hpp

#include <qlo/swap.hpp>
#include <ql/instruments/iboroisbasisswap.hpp>

namespace QuantLib {
    class IBOROISBasisRateHelper;
}

namespace QuantLibAddin {

    class IBOROISBasisSwap : public Swap {
    public:
        IBOROISBasisSwap(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            QuantLib::IBOROISBasisSwap::Type type,
            std::vector<QuantLib::Real> nominals,
            const boost::shared_ptr<QuantLib::Schedule>& floatingSchedule,
            const boost::shared_ptr<QuantLib::IborIndex>& iborIndex,
            const QuantLib::DayCounter& floatingDayCount,
            const boost::shared_ptr<QuantLib::Schedule>& overnightSchedule,
            const boost::shared_ptr<QuantLib::OvernightIndex>& overnightIndex,
            QuantLib::Spread spread,
            const QuantLib::DayCounter& overnightDayCount,
            boost::optional<QuantLib::BusinessDayConvention> paymentConvention,
            bool arithmeticAveragedCoupon,
            bool permanent);
        IBOROISBasisSwap( // MakeIBOROISBasisSwap
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            QuantLib::Natural settlDays,
            const QuantLib::Period& swapTenor,
            const boost::shared_ptr<QuantLib::IborIndex>& iborIndex,
            const boost::shared_ptr<QuantLib::OvernightIndex>& overnightIndex,
            QuantLib::Rate spread,
            const QuantLib::Period& fwdStart,
            bool permanent);
        IBOROISBasisSwap( // MakeDatedIBOROISBasisSwap
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::Date& startDate,
            const QuantLib::Date& enddate,
            const boost::shared_ptr<QuantLib::IborIndex>& iborIndex,
            const boost::shared_ptr<QuantLib::OvernightIndex>& overnightIndex,
            QuantLib::Rate spread,
            bool permanent);
        IBOROISBasisSwap( // IBOROISBasisRateHelper->swap()
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const boost::shared_ptr<QuantLib::IBOROISBasisRateHelper>& swapRH,
            bool permanent);
        std::vector<std::vector<ObjectHandler::property_t> > floatingLegAnalysis(
            const QuantLib::Date& d);
        std::vector<std::vector<ObjectHandler::property_t> > overnightLegAnalysis(
            const QuantLib::Date& d);
    };

}

#endif
