#include "PluginProcessor.h"
#include "PluginEditor.h"

namespace audio_plugin {

    ProcessorX::ProcessorX()
        : AudioProcessor(
              BusesProperties()
    #if !JucePlugin_IsMidiEffect
    #if !JucePlugin_IsSynth
                  .withInput("Input", juce::AudioChannelSet::stereo(), true)
    #endif
                  .withOutput("Output", juce::AudioChannelSet::stereo(), true)
    #endif
          )
    {
    }

    ProcessorX::~ProcessorX() {}

    const juce::String ProcessorX::getName() const
    {
        return JucePlugin_Name;
    }

    bool ProcessorX::acceptsMidi() const
    {
        #if JucePlugin_WantsMidiInput
          return true;
        #else
          return false;
        #endif
    }

    bool ProcessorX::producesMidi() const
    {
        #if JucePlugin_ProducesMidiOutput
          return true;
        #else
          return false;
        #endif
    }

    bool ProcessorX::isMidiEffect() const
    {
        #if JucePlugin_IsMidiEffect
          return true;
        #else
          return false;
        #endif
    }

    double ProcessorX::getTailLengthSeconds() const
    {
        return 0.0;
    }

    int ProcessorX::getNumPrograms()
    {
        return 1;
    }

    int ProcessorX::getCurrentProgram()
    {
        return 0;
    }

    void ProcessorX::setCurrentProgram(int index)
    {
        juce::ignoreUnused(index);
    }

    const juce::String ProcessorX::getProgramName(int index)
    {
          juce::ignoreUnused(index);
          return {};
    }

    void ProcessorX::changeProgramName(int index, const juce::String& newName)
    {
        juce::ignoreUnused(index, newName);
    }

    void ProcessorX::prepareToPlay(double sampleRate, int samplesPerBlock)
    {
      juce::ignoreUnused(sampleRate, samplesPerBlock);
    }

    void ProcessorX::releaseResources()
    {
    }

    bool ProcessorX::isBusesLayoutSupported(const BusesLayout& layouts) const
    {
        #if JucePlugin_IsMidiEffect
          juce::ignoreUnused(layouts);
          return true;
        #else
          // This is the place where you check if the layout is supported.
          // In this template code we only support mono or stereo.
          // Some plugin hosts, such as certain GarageBand versions, will only
          // load plugins that support stereo bus layouts.
          if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono() &&
              layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
            return false;

            // This checks if the input layout matches the output layout
        #if !JucePlugin_IsSynth
          if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
            return false;
        #endif

          return true;
        #endif
    }

    void ProcessorX::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
    {
      juce::ignoreUnused(midiMessages);

      juce::ScopedNoDenormals noDenormals;
      auto totalNumInputChannels = getTotalNumInputChannels();
      auto totalNumOutputChannels = getTotalNumOutputChannels();

      for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
      {
          buffer.clear(i, 0, buffer.getNumSamples());
      }
        
      for (int channel = 0; channel < totalNumInputChannels; ++channel)
      {
            auto* channelData = buffer.getWritePointer(channel);
            juce::ignoreUnused(channelData);
            // ..do something to the data...
      }
    }

    bool ProcessorX::hasEditor() const
    {
        return true;  // (change this to false if you choose to not supply an editor)
    }

    juce::AudioProcessorEditor* ProcessorX::createEditor()
    {
        return new EditorX(*this);
    }

    void ProcessorX::getStateInformation(juce::MemoryBlock& destData)
    {
        juce::ignoreUnused(destData);
    }

    void ProcessorX::setStateInformation(const void* data, int sizeInBytes)
    {
      // You should use this method to restore your parameters from this memory
      // block, whose contents will have been created by the getStateInformation()
      // call.
      juce::ignoreUnused(data, sizeInBytes);
    }


}  // namespace audio_plugin


juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
        return new audio_plugin::ProcessorX();
}
