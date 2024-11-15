#include "PluginEditor.h"
#include "PluginProcessor.h"

MainEditor::MainEditor(MainProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p)
{
  juce::ignoreUnused(processorRef);
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(400, 300);
}

MainEditor::~MainEditor() {}

void MainEditor::paint(juce::Graphics& g)
{
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

  g.setColour(juce::Colours::white);
  g.setFont(15.0f);
  g.drawFittedText("Hello World!", getLocalBounds(),
                   juce::Justification::centred, 1);
}

void MainEditor::resized()
{
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
}
