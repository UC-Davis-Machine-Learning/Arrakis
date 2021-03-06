/**
 * @file    Configuration.h
 * @author  Nicholas Carrara [nmcarrara@ucdavis.edu]
 * @brief   A struct for holding LArSoft configuration parameters
 *          for the Arrakis module.
 * @version 0.1
 * @date 2022-02-15
 */
#pragma once

// art framework includes
#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Principal/Run.h"
#include "art/Framework/Principal/SubRun.h"
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "canvas/Utilities/InputTag.h"
#include "canvas/Utilities/Exception.h"
#include "canvas/Persistency/Common/FindManyP.h"
#include "fhiclcpp/ParameterSet.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

namespace arrakis
{
    struct Configuration
    {
        fhicl::Atom<bool> Generate2DArrays
        {
            fhicl::Name("Generate2DArrays"),
            fhicl::Comment("Whether to generate tdc/channel/adc arrays.")
        };

        fhicl::Atom<double> ADCThresholdUPlane
        {
            fhicl::Name("ADCThresholdUPlane"),
            fhicl::Comment("ADC threshold value for U plane to use for filling 2D arrays.")
        };

        fhicl::Atom<double> ADCThresholdVPlane
        {
            fhicl::Name("ADCThresholdVPlane"),
            fhicl::Comment("ADC threshold value for V plane to use for filling 2D arrays.")
        };

        fhicl::Atom<double> ADCThresholdZPlane
        {
            fhicl::Name("ADCThresholdZPlane"),
            fhicl::Comment("ADC threshold value for Z plane to use for filling 2D arrays.")
        };

        fhicl::Atom<art::InputTag> LArGeantProducerLabel
        {
            fhicl::Name("LArGeantProducerLabel"),
            fhicl::Comment("Tag of the input data product for the largeant side of the simulation.")
        };
        fhicl::Atom<art::InputTag> IonAndScintProducerLabel
        {
            fhicl::Name("IonAndScintProducerLabel"),
            fhicl::Comment("Tag of the input data product for the IonAndScint side of the simulation.")
        };
        fhicl::Atom<art::InputTag> SimChannelProducerLabel
        {
            fhicl::Name("SimChannelProducerLabel"),
            fhicl::Comment("Tag of the input data product for the SimChannelProducerLabel.")
        };

        fhicl::Atom<art::InputTag> SimChannelInstanceProducerLabel
        {
            fhicl::Name("SimChannelInstanceProducerLabel"),
            fhicl::Comment("Tag of the input data product for the SimChannelInstanceProducerLabel.")
        };

        fhicl::Atom<art::InputTag> TPCInputLabel
        {
            fhicl::Name("TPCInputLabel"),
            fhicl::Comment("Tag of the input data product for the TPCInputLabel.")
        };

        fhicl::Atom<art::InputTag> TPCInstanceLabel
        {
            fhicl::Name("TPCInstanceLabel"),
            fhicl::Comment("Tag of the input data product for the TPCInstanceLabel.")
        };

        // fhicl::Atom<bool> GenerateSemanticLabels
        // {
        //     fhicl::Name("GenerateSemanticLabels"),
        //     fhicl::Comment("Whether to generate semantic labels.")
        // };
    };

    using Parameters = art::EDAnalyzer::Table<Configuration>;
}