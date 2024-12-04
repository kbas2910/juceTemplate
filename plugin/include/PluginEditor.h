#pragma once

#include "PluginProcessor.h"
#include "someClass.h"


namespace audio_plugin {

    class EditorX : public juce::AudioProcessorEditor
    {
        public:
            explicit EditorX(ProcessorX&);
            ~EditorX() override;

            void paint(juce::Graphics&) override;
            void resized() override;

        private:
            ProcessorX& processorRef;

            someClass mClass ;
        
            JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EditorX)
    };

}  // namespace audio_plugin
