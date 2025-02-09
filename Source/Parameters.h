/*
  ==============================================================================

    Parameters.h
    Created: 21 Jul 2024 1:53:53pm
    Author:  Isak

  ==============================================================================
*/


#pragma once

#include <JuceHeader.h>

const juce::ParameterID gainParamID{ "gain", 1 };
const juce::ParameterID delayTimeParamID{ "delayTime", 1 };
const juce::ParameterID mixParamID{ "mix", 1 };



class Parameters
{
public:
    Parameters(juce::AudioProcessorValueTreeState& apvts);

    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    void update() noexcept;

    void prepareToPlay(double sampleRate) noexcept;

    void reset() noexcept;

    void smoothen() noexcept;

    float gain = 0.0f;
    float delayTime = 0.0f;
    float mix = 1.0f;


    static constexpr float minDelayTime = 0.01f;
    static constexpr float maxDelayTime = 5000.0f;

private:
    juce::AudioParameterFloat* gainParam;
    juce::LinearSmoothedValue<float> gainSmoother;

    juce::AudioParameterFloat* delayTimeParam;

    juce::AudioParameterFloat* mixParam;
    juce::LinearSmoothedValue<float> mixSmoother;

    float targetDelayTime = 0.0f;
    float coeff = 0.0f; // one-pole smoothing

};
