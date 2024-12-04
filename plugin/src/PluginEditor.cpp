#include "PluginEditor.h"
#include "PluginProcessor.h"

namespace audio_plugin {

    EditorX::EditorX(ProcessorX& p)
    : AudioProcessorEditor(&p), processorRef(p)
    {
            juce::ignoreUnused(processorRef);
            setSize(400, 300);
    }

    EditorX::~EditorX() {}

    void EditorX::paint(juce::Graphics& g)
    {
        g.fillAll(
          getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

        g.setColour(juce::Colours::white);
        g.setFont(15.0f);
        g.drawFittedText("Es werde Licht!", getLocalBounds(),
                       juce::Justification::centred, 1);
    }

    void EditorX::resized()
    {
    }

}  // namespace audio_plugin
