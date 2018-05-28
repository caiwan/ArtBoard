function(MAC_EXECUTABLE _APPLICATION_NAME)
    configure_file(run_macos.template.sh ${CMAKE_BINARY_DIR}/bin/run.sh)
endfunction()
