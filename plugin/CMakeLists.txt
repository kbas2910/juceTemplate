cmake_minimum_required(VERSION 3.27.5)       

project(Plugin VERSION 1.0) 

set(JUCE_BUILD_EXTRAS ON)

juce_add_plugin(${PROJECT_NAME}
    COMPANY_NAME BASCOMP 
    IS_SYNTH FALSE 
    NEEDS_MIDI_INPUT TRUE 
    NEEDS_MIDI_OUTPUT TRUE 
    PLUGIN_MANUFACTURER_CODE MANU 
    PLUGIN_CODE EXPL 
    FORMATS Standalone VST3 
    PRODUCT_NAME ${PROJECT_NAME}
    COPY_PLUGIN_AFTER_BUILD TRUE
	#ICON_BIG ${CMAKE_CURRENT_SOURCE_DIR}/plugin/assets/Bypass.png
)

target_include_directories(${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCE_DIR}/src
	PRIVATE ${LIB_DIR}/juce/modules
)

target_link_directories(${PROJECT_NAME} 
	PRIVATE ${LIB_DIR}/juce/modules
)


file(GLOB_RECURSE SourceFiles CONFIGURE_DEPENDS 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp" 
 
)

target_sources("${PROJECT_NAME}" 
	PRIVATE ${SourceFiles}
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        JUCE_WEB_BROWSER=0  
        JUCE_USE_CURL=0     
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:${PROJECT_NAME},JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:${PROJECT_NAME},JUCE_VERSION>")


target_link_libraries(${PROJECT_NAME}
    	PRIVATE
		juce::juce_audio_utils  
		juce::juce_dsp
            	juce::juce_osc
	PUBLIC
		juce::juce_recommended_config_flags
      		juce::juce_recommended_lto_flags
      		juce::juce_recommended_warning_flags)

juce_generate_juce_header(${PROJECT_NAME})


if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()





