cmake_minimum_required(VERSION 3.27.5)       

project(Plugin 
	VERSION 1.0
) 


set(JUCE_ENABLE_MODULE_SOURCE_GROUPS ON)

juce_add_plugin(${PROJECT_NAME}
    COMPANY_NAME BASCOMP 
    IS_SYNTH FALSE 
    NEEDS_MIDI_INPUT TRUE 
    NEEDS_MIDI_OUTPUT TRUE 
    PLUGIN_MANUFACTURER_CODE MANU 
    PLUGIN_CODE EXPL 
    FORMATS Standalone VST3 
    PRODUCT_NAME ${PROJECT_NAME} 
)
  

target_include_directories(${PROJECT_NAME}
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
	PRIVATE ${CMAKE_BINARY_DIR}/libs/juce/modules
)

target_link_directories(${PROJECT_NAME} 
	PRIVATE ${CMAKE_BINARY_DIR}/libs/juce/modules
)
..

target_sources(${PROJECT_NAME}
    PRIVATE
     	${CMAKE_CURRENT_SOURCE_DIR}/src/PluginEditor.cpp
     	${CMAKE_CURRENT_SOURCE_DIR}/src/PluginProcessor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/PluginEditor.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/PluginProcessor.h

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
	PUBLIC
		juce::juce_recommended_config_flags
      	juce::juce_recommended_lto_flags
      	juce::juce_recommended_warning_flags)


if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()


# install(TARGETS ${PROJECT_NAME} DESTINATION bin)
# install(FILES ${PROJECT_BINARY_DIR}/AMAConfig.h DESTINATION include)



