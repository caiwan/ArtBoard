# Adds the files to the corresponding group bsed on their type and path, visual studio style
# caiwan/IR

function(assign_source_group)
	foreach(_source IN ITEMS ${ARGN})
		if (IS_ABSOLUTE "${_source}")
			file(RELATIVE_PATH _source_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source}")
		else()
			set(source_rel "${_source}")
		endif()
		
		get_filename_component(_source_path "${_source_rel}" PATH)
		
		string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")

		if ("${_source}" MATCHES ".*\\.(c(p|x)*|inc)\\s?")
			set(_source_path_msvc "Source Files\\${_source_path_msvc}")
			
		elseif("${_source}" MATCHES ".*\\.(js|qs|lua)\\s?")
			set(_source_path_msvc "Script Files\\${_source_path_msvc}")
			
		elseif("${_source}" MATCHES ".*\\.(hlsl|fx)\\s?")
			set(_source_path_msvc "Shader Files\\${_source_path_msvc}")
			
		elseif("${_source}" MATCHES ".*\\.(h(p|x)*|inl)\\s?")
			set(_source_path_msvc "Header Files\\${_source_path_msvc}")
			
		elseif("${_source}" MATCHES ".*\\.(ui)\\s?")
			set(_source_path_msvc "UI Files\\${_source_path_msvc}")

		elseif("${_source}" MATCHES ".*\\.(py)\\s?")
			set(_source_path_msvc "Source Files\\${_source_path_msvc}")
            
		elseif("${_source}" MATCHES ".*\\.(blend)\\s?")
			set(_source_path_msvc "Blender Files\\${_source_path_msvc}")
						
		else()
			set(_source_path_msvc "Resource Files\\${_source_path_msvc}")
			
		endif()

		source_group("${_source_path_msvc}" FILES "${_source}")

	endforeach()
endfunction(assign_source_group)
