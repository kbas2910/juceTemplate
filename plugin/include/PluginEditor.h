#pragma once

#include "PluginProcessor.h"

namespace audio_plugin {

class EditorX : public juce::AudioProcessorEditor {
public:
  explicit EditorX(ProcessorX&);
  ~EditorX() override;

  void paint(juce::Graphics&) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  ProcessorX& processorRef;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EditorX)
};
}  // namespace audio_plugin
